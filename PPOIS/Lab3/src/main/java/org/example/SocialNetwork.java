package org.example;

import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class SocialNetwork {


    private final static String GROUP_CHAT_NAME_TABEL = "message_of_group_chat";
    private final static String PERSONAL_CHAT_NAME_TABEL = "message_of_personal_chat";
    private List<Customer> customers = new ArrayList<>();

    private List<GroupChat> groupChats = new ArrayList<>();
    private List<PersonalСhat> personalСhats = new ArrayList<>();
    private final ConnectionManager db = new ConnectionManager();

    /**
     * constructor, load all date
     */
    public SocialNetwork() {
        loadCustomers();
        loadGroupChats();
        loadPersonalChats();
    }

    /**
     * load all customers from db
     */
    private void loadCustomers() {
        customers = db.getAllCustomerFromDateBase();
        for (Customer customer : customers) {
            customer.setFriends(db.getFriends(customer.getId()));
        }
    }

    /**
     * load all group chats from db
     */
    private void loadGroupChats() {
        groupChats = db.getGroupChat();
        for (GroupChat groupChat : groupChats) {
            groupChat.setMessages(db.getMessages(groupChat.getChat_id(), GROUP_CHAT_NAME_TABEL));
            groupChat.setMembers_id(db.getGroupChatMembers_id(groupChat.getChat_id()));
        }
    }

    /**
     * load all personal chats from db
     */
    private void loadPersonalChats() {
        personalСhats = db.getPersonalChat();
        for (PersonalСhat personalСhat : personalСhats) {
            personalСhat.setMessages(db.getMessages(personalСhat.getChat_id(), PERSONAL_CHAT_NAME_TABEL));
        }
    }

    /**
     * customers getter
     * @return list with customers
     */
    public List<Customer> getCustomers() {
        return customers;
    }

    /**
     * add customer insert into list and db
     * @param customers customer that need to be added
     */
    public void addCustomers(Customer... customers) {
        for (Customer customer : customers) {
            db.addCustomer(customer);
            this.customers.add(customer);
        }
    }

    /**
     * groupChats getter
     * @return list with group chats
     */
    public List<GroupChat> getGroupChats() {
        return groupChats;
    }

    /**
     * add group chat insert into list and db
     * @param groupChats group chats that need to be added
     */
    public void addGroupChats(GroupChat... groupChats) {
        for (GroupChat groupChat : groupChats) {
            db.addGroupChat(groupChat);
            this.groupChats.add(groupChat);
        }
    }

    /**
     * personalСhats getter
     * @return list with personal chats
     */
    public List<PersonalСhat> getPersonalСhats() {
        return personalСhats;
    }

    /**
     * add personal chat insert into list and db
     * @param personalСhats personal chats that need to be added
     */
    public void addPersonalСhats(PersonalСhat... personalСhats) {
        for (PersonalСhat personalСhat : personalСhats) {
            db.addPersonalChat(personalСhat);
            this.personalСhats.add(personalСhat);
        }
    }

    /**
     * find number of personal chat by id
     * @param chat_id id of chat
     * @return chat number in the list
     */
    private int findPersonalChatById(Long chat_id) {
        int cout = 0;
        for (PersonalСhat personalСhat : personalСhats) {
            if (personalСhat.getChat_id().equals(chat_id))
                break;
            cout++;
        }
        return cout;
    }

    /**
     * add personal message into List and db
     * @param chat_id id of chat
     * @param text text of message
     * @param sender_id id of customer
     */
    public void addPersonalMessage(Long chat_id, String text, Long sender_id) {
        if (Objects.equals(personalСhats.get(findPersonalChatById(chat_id)).getFirstMember_id(), sender_id) || Objects.equals(personalСhats.get(findPersonalChatById(chat_id)).getSecondMember_id(), sender_id)) {
            Message message = new Message(text, new Timestamp(System.currentTimeMillis()), sender_id);
            db.addPersonalMessage(chat_id, message);
            this.personalСhats.get(findPersonalChatById(chat_id)).addMessage(message);
        }
    }

    /**
     * find number of group chat by id
     * @param chat_id id of chat
     * @return chat number in the list
     */
    private int findGroupChatById(Long chat_id) {
        int cout = 0;
        for (GroupChat groupChat : groupChats) {
            if (groupChat.getChat_id().equals(chat_id))
                break;
            cout++;
        }
        return cout;
    }

    /**
     * check is member in group chat
     * @param chat_id id of chat
     * @param sender_id id of customer
     * @return true of false
     */
    private boolean isMemberInGroupChat(Long chat_id, Long sender_id) {
        for (Long members_id : groupChats.get(findGroupChatById(chat_id)).getMembers_id()) {
            if (sender_id.equals(members_id))
                return true;
        }
        return false;
    }

    /**
     * add group message into List and db
     * @param chat_id id of chat
     * @param text text of message
     * @param sender_id id of customer
     */
    public void addGroupMessage(Long chat_id, String text, Long sender_id) {
        if (isMemberInGroupChat(chat_id, sender_id)) {
            Message message = new Message(text, new Timestamp(System.currentTimeMillis()), sender_id);
            db.addGroupMessage(chat_id, message);
            this.groupChats.get(findGroupChatById(chat_id)).addMessage(message);
        }
    }

    /**
     * find number of customer chat by id
     * @param id id of customer
     * @return customer in the list
     */
    private int findCustomerById(Long id) {
        int count = 0;
        for (Customer customer : customers) {
            if (customer.getId().equals(id))
                count++;
        }
        return count;
    }

    /**
     * delete customer from List and db
     * @param id id of customer
     */
    public void deleteCustomer(Long id) {
        db.deleteCustomer(id);
        customers.remove(findCustomerById(id));
    }

    /**
     * delete group chat from List and db
     * @param chat_id id of chat
     */
    public void deleteGroupChat(Long chat_id) {
        db.deleteGroupChat(chat_id);
        groupChats.remove(findGroupChatById(chat_id));
    }

    /**
     * delete personal chat from List and db
     * @param chat_id id of chat
     */
    public void deletePersonalChat(Long chat_id) {
        db.deletePersonalChat(chat_id);
        personalСhats.remove(findPersonalChatById(chat_id));
    }

    /**
     * find number of personal chat message by id
     * @param chat_id id of chat
     * @param text text of message
     * @param sender_id id of customer
     * @return message number in the list
     */
    private int findPersonalMessage(Long chat_id, String text, Long sender_id) {
        int count = 0;
        for (Message message : personalСhats.get(findPersonalChatById(chat_id)).getMessages()) {
            if (Objects.equals(message.getText(), text) && Objects.equals(message.getSender_id(), sender_id)) {
                return count;
            }
            count++;
        }
        return count;
    }

    /**
     * find number of group chat message by id
     * @param chat_id id of chat
     * @param text text of message
     * @param sender_id id of customer
     * @return message number in the list
     */
    private int findGroupMessage(Long chat_id, String text, Long sender_id) {
        int count = 0;
        for (Message message : groupChats.get(findGroupChatById(chat_id)).getMessages()) {
            if (Objects.equals(message.getText(), text) && Objects.equals(message.getSender_id(), sender_id)) {
                return count;
            }
            count++;
        }
        return count;
    }


    /**
     * delete personal message from List and db
     * @param chat_id id of chat
     * @param text text
     * @param sender_id id of customer
     */
    public void deletePersonalMessage(Long chat_id, String text, Long sender_id) {
        db.deletePersonalMessage(chat_id, personalСhats.get(findPersonalChatById(chat_id)).getMessages().get(findPersonalMessage(chat_id,text,sender_id)));
        personalСhats.get(findPersonalChatById(chat_id)).getMessages().remove(findPersonalMessage(chat_id,text,sender_id));
    }

    /**
     * delete group message from List and db
     * @param chat_id id of chat
     * @param text text
     * @param sender_id id of customer
     */
    public void deleteGroupMessage(Long chat_id, String text, Long sender_id) {
        db.deleteGroupMessage(chat_id, groupChats.get(findGroupChatById(chat_id)).getMessages().get(findGroupMessage(chat_id,text,sender_id)));
        groupChats.get(findGroupChatById(chat_id)).getMessages().remove(findGroupMessage(chat_id,text,sender_id));
    }
}
