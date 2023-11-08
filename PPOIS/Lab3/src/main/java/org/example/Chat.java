package org.example;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public abstract class Chat {



    private List<Message> messages = new ArrayList<>();

    private Long chat_id;

    /**
     * chat constructor with id
     * @param chatId id of chat
     */
    protected Chat(Long chatId) {
        chat_id = chatId;
    }

    /**
     * chat constructor without id
     */
    protected Chat(){}

    /**
     * chat_id setter
     * @param chatId id of chat
     */
    public void setChat_id(Long chatId){
        this.chat_id = chatId;
    }

    /**
     * messages getter
     * @return list with messages
     */
    public List<Message> getMessages() {
        return messages;
    }

    /**
     * messages setter
     * @param messages list with messages
     */
    public void setMessages(List<Message> messages) {
        this.messages = messages;
    }

    /**
     * add one message
     * @param message message
     */
    public void addMessage(Message message){
        this.messages.add(message);
    }

    /**
     * chat_id getter
     * @return id of chat
     */
    public Long getChat_id() {
        return chat_id;
    }
}
