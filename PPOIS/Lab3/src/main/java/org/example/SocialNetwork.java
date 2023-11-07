package org.example;

import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;

public class SocialNetwork {


    private final static String GROUP_CHAT_NAME_TABEL = "message_of_group_chat";
    private final static String PERSONAL_CHAT_NAME_TABEL = "message_of_personal_chat";
    private List<Customer> customers = new ArrayList<>();

    private List<GroupChat> groupChats = new ArrayList<>();
    private List<PersonalСhat> personalСhats = new ArrayList<>();
    private final ConnectionManager db = new ConnectionManager();

    public SocialNetwork() {
        loadCustomers();
        loadGroupChats();
        loadPersonalChats();
    }

    private void loadCustomers() {
        customers = db.getAllCustomerFromDateBase();
        for (Customer customer : customers) {
            customer.setFriends(db.getFriends(customer.getId()));
        }
    }

    private void loadGroupChats() {
        groupChats = db.getGroupChat();
        for (GroupChat groupChat : groupChats) {
            groupChat.setMessages(db.getMessages(groupChat.getChat_id(), GROUP_CHAT_NAME_TABEL));
            groupChat.setMembers_id(db.getGroupChatMembers_id(groupChat.getChat_id()));
        }
    }

    private void loadPersonalChats() {
        personalСhats = db.getPersonalChat();
        for (PersonalСhat personalСhat : personalСhats) {
            personalСhat.setMessages(db.getMessages(personalСhat.getChat_id(), PERSONAL_CHAT_NAME_TABEL));
        }
    }

    public List<Customer> getCustomers() {
        return customers;
    }

    public void addCustomers(Customer... customers) {
        for (Customer customer : customers) {
            db.addCustomer(customer);
            this.customers.add(customer);
        }
    }

    public List<GroupChat> getGroupChats() {
        return groupChats;
    }

    public void addGroupChats(GroupChat... groupChats) {
        for (GroupChat groupChat: groupChats){
            db.addGroupChat(groupChat);
            this.groupChats.add(groupChat);
        }
    }

    public List<PersonalСhat> getPersonalСhats() {
        return personalСhats;
    }

    public void addPersonalСhats(PersonalСhat... personalСhats) {
        for (PersonalСhat personalСhat : personalСhats) {
            db.addPersonalChat(personalСhat);
            this.personalСhats.add(personalСhat);
        }
    }

    private int findPersonalChatById(Long chat_id) {
        int cout = 0;
        for (PersonalСhat personalСhat : personalСhats) {
            if (personalСhat.getChat_id().equals(chat_id))
                break;
            cout++;
        }
        return cout;
    }

    public void addPersonalMessage(Long chat_id, String text, Long sender_id) {
        if (Objects.equals(personalСhats.get(findPersonalChatById(chat_id)).getFirst_member_id(), sender_id) || Objects.equals(personalСhats.get(findPersonalChatById(chat_id)).getSecond_member_id(), sender_id)) {
            Message message = new Message(text, new Timestamp(System.currentTimeMillis()), sender_id);
            db.addPersonalMessage(chat_id, message);
            this.personalСhats.get(findPersonalChatById(chat_id)).addMessage(message);
        }
    }

    private int findGroupChatById(Long chat_id) {
        int cout = 0;
        for (GroupChat groupChat : groupChats) {
            if (groupChat.getChat_id().equals(chat_id))
                break;
            cout++;
        }
        return cout;
    }

    private boolean isMemberInGroupChat(Long chat_id, Long sender_id) {
        for (Long members_id : groupChats.get(findGroupChatById(chat_id)).getMembers_id()) {
            if (sender_id.equals(members_id))
                return true;
        }
        return false;
    }

    public void addGroupMessage(Long chat_id, String text, Long sender_id) {
        if (isMemberInGroupChat(chat_id, sender_id)) {
            Message message = new Message(text, new Timestamp(System.currentTimeMillis()), sender_id);
            db.addGroupMessage(chat_id, message);
            this.groupChats.get(findGroupChatById(chat_id)).addMessage(message);
        }
    }
}
