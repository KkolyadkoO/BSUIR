package org.example;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public final class ConnectionManager {
    private static final String URL_KEY = "db.url";
    private static final String USERNAME_KEY = "db.username";
    private static final String PASSWORD_KEY = "db.password";


    /**
     * open db
     * @return Connection
     */
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

    /**
     * get all customer from db
     * @return list with customer
     */
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

    /**
     * get friends from db
     * @param id id of customer
     * @return list with friends
     */
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

    /**
     * get all group chats from db
     * @return list with group chats
     */
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

    /**
     * get message from db
     * @param chat_id id of chat
     * @param nameOfTable name of table (group of personal)
     * @return list with message
     */
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

    /**
     * get all member for group chat from db
     * @param chat_id id of chat
     * @return list with
     */
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

    /**
     * get all personal chats from db
     * @return list with personal chats
     */
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

    /**
     * add customer into db
     * @param customer customer
     */
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

    /**
     * add photo into db
     * @param user_id id of user
     * @param url url of photo
     */
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

    /**
     * add personal chat into db
     * @param personalСhat personal chat
     */
    public void addPersonalChat(PersonalСhat personalСhat) {
        String sql = """
                INSERT INTO personal_chat(first_customer_id, second_customer_id)
                VALUES (?,?);
                """;
        try (var connection = ConnectionManager.open();
             var prepareStatement = connection.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS)) {
            prepareStatement.setLong(1, personalСhat.getFirstMember_id());
            prepareStatement.setLong(2, personalСhat.getSecondMember_id());
            prepareStatement.execute();
            var generatedKeys = prepareStatement.getGeneratedKeys();
            if (generatedKeys.next()) {
                personalСhat.setChat_id(generatedKeys.getLong("id"));
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * add message into personal chat message db
     * @param chat_id id of chat
     * @param message message
     */
    public void addPersonalMessage(Long chat_id, Message message) {
        String sql = """
                INSERT INTO message_of_personal_chat(chat_id, text, time, customer_id)
                VALUES (?,?,?,?);
                """;
        addMessage(chat_id, message, sql);
    }

    /**
     * add group chat into db
     * @param groupChat group chat
     */
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

    /**
     * add member into db
     * @param chat_id id of chat
     * @param member_id id of member
     */
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

    /**
     * add message into group chat db
     * @param chat_id id of chat
     * @param message message
     */
    public void addGroupMessage(Long chat_id, Message message) {
        String sql = """
                INSERT INTO message_of_group_chat(chat_id, text, time, customer_id)
                VALUES (?,?,?,?);
                """;
        addMessage(chat_id, message, sql);
    }

    /**
     * add message into db
     * @param chat_id id of chat
     * @param message message
     * @param sql sql request
     */
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

    /**
     * delete customer from db
     * @param id id of customer
     */
    public void deleteCustomer(Long id){
        String sql = """
                DELETE FROM customer
                WHERE id = ?;
                """;
        try (var connection = ConnectionManager.open();
             var preparedStatement = connection.prepareStatement(sql)){
            preparedStatement.setLong(1, id);
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * delete group chat from db
     * @param chat_id id of chat
     */
    public void deleteGroupChat(Long chat_id){
        String sql = """
                DELETE FROM group_chat
                WHERE id = ?;
                """;
        try (var connection = ConnectionManager.open();
             var preparedStatement = connection.prepareStatement(sql)){
            preparedStatement.setLong(1, chat_id);
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * delete personal chat from db
     * @param chat_id id of chat
     */
    public void deletePersonalChat(Long chat_id){
        String sql = """
                DELETE FROM personal_chat
                WHERE id = ?;
                """;
        try (var connection = ConnectionManager.open();
             var preparedStatement = connection.prepareStatement(sql)){
            preparedStatement.setLong(1, chat_id);
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * delete personal message from db
     * @param chat_id id of chat
     * @param message message
     */
    public void deletePersonalMessage(Long chat_id ,Message message){
        String sql = """
                DELETE FROM message_of_personal_chat
                WHERE chat_id = ? AND time = ? AND text = ? AND customer_id = ?;
                """;
        deleteMessage(chat_id, message, sql);
    }

    /**
     * delete group message from db
     * @param chat_id id of chat
     * @param message message
     */
    public void deleteGroupMessage(Long chat_id ,Message message){
        String sql = """
                DELETE FROM message_of_group_chat
                WHERE chat_id = ? AND time = ? AND text = ? AND customer_id = ?;
                """;
        deleteMessage(chat_id, message, sql);
    }

    /**
     * delete message from db
     * @param chat_id id of chat
     * @param message message
     * @param sql sql request
     */
    private void deleteMessage(Long chat_id, Message message, String sql) {
        try (var connection = ConnectionManager.open();
             var preparedStatement = connection.prepareStatement(sql)){
            preparedStatement.setLong(1, chat_id);
            preparedStatement.setTimestamp(2, message.getTimeOfSending());
            preparedStatement.setString(3, message.getText());
            preparedStatement.setLong(4, message.getSender_id());
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
