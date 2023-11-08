package org.example;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class GroupChat extends Chat{

    private List<Long> members_id = new ArrayList<>();
    private String chatName;

    /**
     * Group chat constructor without chat_id
     * @param chatName Name of chat
     */
    public GroupChat(String chatName) {
        this.chatName = chatName;
    }

    /**
     * Group chat constructor with chat_id
     * @param chat_id id of chat
     * @param chatName name of chat
     */
    public GroupChat(Long chat_id, String chatName) {
        super(chat_id);
        this.chatName = chatName;
    }

    /**
     * add one member
     * @param member_id id of member
     */
    public void addMember(Long member_id){
        members_id.add(member_id);
    }

    /**
     * members_id getter
     * @return list with members_id
     */
    public List<Long> getMembers_id() {
        return members_id;
    }

    /**
     * members_id setter
     * @param members_id List with members_id
     */
    public void setMembers_id(List<Long> members_id) {
        this.members_id = members_id;
    }

    /**
     * chat name getter
     * @return name of chat
     */
    public String getChatName() {
        return chatName;
    }

    /**
     * chat name setter
     * @param chatName name of chat
     */
    public void setChatName(String chatName) {
        this.chatName = chatName;
    }

}
