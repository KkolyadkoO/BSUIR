package org.example;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public final class ConnectionManager {
    private static final String URL_KEY = "db.url";
    private static final String USERNAME_KEY = "db.username";
    private static final String PASSWORD_KEY = "db.password";


    public static Connection open() {
        try {
            return DriverManager.getConnection(
                    PropertiesUtil.get(URL_KEY),
                    PropertiesUtil.get(USERNAME_KEY),
                    PropertiesUtil.get(PASSWORD_KEY)
            );
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public List<Customer> getAllCustomerFromDateBase() {
        List<Customer> customers = new ArrayList<>();
        String sql = """
                SELECT c.id cus_id,
                       c.first_name f_name,
                       c.second_name s_name,
                       c.number num,
                       p.url p_url
                FROM customer c
                JOIN photo p on c.id = p.user_id;
                """;
        try (var connection = ConnectionManager.open();
             var prepareStatement = connection.prepareStatement(sql)) {
            ResultSet resultSet = prepareStatement.executeQuery();
            while (resultSet.next()) {
                customers.add(new Customer(resultSet.getString("f_name"),
                                            resultSet.getString("s_name"),
                        new Photo(resultSet.getLong("cus_id"),
                                  resultSet.getString("p_url")),
                                  resultSet.getString("num")));
                customers.get(customers.size() - 1).setId(resultSet.getLong("cus_id"));
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return customers;
    }

    public List<Friend> getFriends(Long id) {
        List<Friend> friends = new ArrayList<>();
        String sql = """
                SELECT second_customer_id
                FROM friendship
                WHERE first_customer_id = ?;
                """;
        try (var connection = ConnectionManager.open();
             var preparedStatement = connection.prepareStatement(sql)) {
            preparedStatement.setLong(1, id);
            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                friends.add(new Friend(resultSet.getLong("second_customer_id")));
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return friends;
    }

    public List<GroupChat> getGroupChat() {
        List<GroupChat> groupChats = new ArrayList<>();
        String sql = """
                SELECT *
                FROM group_chat;
                """;
        try (var connection = ConnectionManager.open();
             var prepareStatement = connection.prepareStatement(sql)) {
            ResultSet resultSet = prepareStatement.executeQuery();
            while (resultSet.next()) {
                groupChats.add(new GroupChat(resultSet.getLong("id"),
                        resultSet.getString("name")));
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return groupChats;
    }

    public List<Message> getMessages(Long chat_id, String nameOfTable) {
        List<Message> messages = new ArrayList<>();
        String sql = "";
        if (nameOfTable.equals("message_of_group_chat")) {
            sql = """
                    SELECT *
                    FROM message_of_group_chat
                    WHERE chat_id = ?;
                    """;
        } else if (nameOfTable.equals("message_of_personal_chat")) {
            sql = """
                    SELECT *
                    FROM message_of_personal_chat
                    WHERE chat_id = ?;
                    """;
        }
        try (var connection = ConnectionManager.open();
             var prepareStatement = connection.prepareStatement(sql)) {
            prepareStatement.setLong(1, chat_id);
            ResultSet resultSet = prepareStatement.executeQuery();
            while (resultSet.next()) {
                messages.add(new Message(resultSet.getString("text"),
                        resultSet.getTimestamp("time"),
                        resultSet.getLong("customer_id")));
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return messages;
    }

    public List<Long> getGroupChatMembers_id(Long chat_id) {
        List<Long> members_id = new ArrayList<>();
        String sql = """
                SELECT member
                FROM members_of_group_chat
                WHERE group_chat_id = ?;
                """;
        try (var connection = ConnectionManager.open();
             var preparedStatement = connection.prepareStatement(sql)) {
            preparedStatement.setLong(1, chat_id);
            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                members_id.add(resultSet.getLong("member"));
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return members_id;
    }

    public List<PersonalСhat> getPersonalChat() {
        List<PersonalСhat> personalChats = new ArrayList<>();
        String sql = """
                SELECT *
                FROM personal_chat;
                """;
        try (var connection = ConnectionManager.open();
             var prepareStatement = connection.prepareStatement(sql)) {
            ResultSet resultSet = prepareStatement.executeQuery();
            while (resultSet.next()) {
                personalChats.add(new PersonalСhat(resultSet.getLong("id"),
                        resultSet.getLong("first_customer_id"),
                        resultSet.getLong("second_customer_id")));
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return personalChats;
    }

    public void addCustomer(Customer customer) {
        String sql = """
                   INSERT INTO customer(first_name, second_name, number)
                   VALUES (?,?,?);
                """;
        try (var connection = ConnectionManager.open();
             var prepareStatement = connection.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS)) {
            prepareStatement.setString(1, customer.getFirst_name());
            prepareStatement.setString(2, customer.getSecond_name());
            prepareStatement.setString(3, customer.getPhoneNumber());
            prepareStatement.execute();
            var generatedKeys = prepareStatement.getGeneratedKeys();
            if (generatedKeys.next()) {
                customer.setId(generatedKeys.getLong("id"));
                addPhoto(generatedKeys.getLong("id"), customer.getAvatar().getUrlPhoto());
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    private void addPhoto(Long user_id, String url) {
        String sql = """
                   INSERT INTO photo(user_id, url) 
                   VALUES (?,?); 
                """;
        try (var connection = ConnectionManager.open();
             var prepareStatement = connection.prepareStatement(sql)) {
            prepareStatement.setLong(1, user_id);
            prepareStatement.setString(2, url);
            prepareStatement.execute();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void addPersonalChat(PersonalСhat personalСhat) {
        String sql = """
                INSERT INTO personal_chat(first_customer_id, second_customer_id) 
                VALUES (?,?); 
                """;
        try (var connection = ConnectionManager.open();
             var prepareStatement = connection.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS)) {
            prepareStatement.setLong(1, personalСhat.getFirst_member_id());
            prepareStatement.setLong(2, personalСhat.getSecond_member_id());
            prepareStatement.execute();
            var generatedKeys = prepareStatement.getGeneratedKeys();
            if (generatedKeys.next()) {
                personalСhat.setChat_id(generatedKeys.getLong("id"));
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void addPersonalMessage(Long chat_id, Message message) {
        String sql = """
                INSERT INTO message_of_personal_chat(chat_id, text, time, customer_id) 
                VALUES (?,?,?,?); 
                """;
        addMessage(chat_id, message, sql);
    }

    public void addGroupChat(GroupChat groupChat) {
        String sql = """
                INSERT INTO group_chat(name)
                VALUES (?);
                """;
        try (var connection = ConnectionManager.open();
             var prepareStatement = connection.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS)) {
            prepareStatement.setString(1, groupChat.getChatName());
            prepareStatement.execute();
            var generatedKeys = prepareStatement.getGeneratedKeys();
            if (generatedKeys.next()) {
                groupChat.setChat_id(generatedKeys.getLong("id"));
                for (Long member_id : groupChat.getMembers_id()) {
                    addGroupChatMember(generatedKeys.getLong("id"), member_id);
                }
                for (Message message : groupChat.getMessages()) {
                    addGroupMessage(generatedKeys.getLong("id"), message);
                }
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void addGroupChatMember(Long chat_id, Long member_id) {
        String sql = """
                INSERT INTO members_of_group_chat(group_chat_id, member)
                VALUES (?,?);
                """;
        try (var connection = ConnectionManager.open();
             var prepareStatement = connection.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS)) {
            prepareStatement.setLong(1, chat_id);
            prepareStatement.setLong(2, member_id);
            prepareStatement.execute();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void addGroupMessage(Long chat_id, Message message) {
        String sql = """
                INSERT INTO message_of_group_chat(chat_id, text, time, customer_id) 
                VALUES (?,?,?,?); 
                """;
        addMessage(chat_id, message, sql);
    }

    private void addMessage(Long chat_id, Message message, String sql) {
        try (var connection = ConnectionManager.open();
             var prepareStatement = connection.prepareStatement(sql)) {
            prepareStatement.setLong(1, chat_id);
            prepareStatement.setString(2, message.getText());
            prepareStatement.setTimestamp(3, message.getTimeOfSending());
            prepareStatement.setLong(4, message.getSender_id());
            prepareStatement.execute();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

}
