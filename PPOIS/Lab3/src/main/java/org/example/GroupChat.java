package org.example;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class GroupChat extends Chat{

    private List<Long> members_id = new ArrayList<>();
    private String chatName;

    public GroupChat(String chatName) {
        this.chatName = chatName;
    }

    public GroupChat(Long chat_id, String chatName) {
        super(chat_id);
        this.chatName = chatName;
    }

    public void addMember(Long member_id){
        members_id.add(member_id);
    }
    public List<Long> getMembers_id() {
        return members_id;
    }

    public void setMembers_id(List<Long> members_id) {
        this.members_id = members_id;
    }

    public String getChatName() {
        return chatName;
    }

    public void setChatName(String chatName) {
        this.chatName = chatName;
    }

}
