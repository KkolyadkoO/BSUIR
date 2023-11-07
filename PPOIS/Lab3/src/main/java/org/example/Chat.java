package org.example;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public abstract class Chat {



    private List<Message> messages = new ArrayList<>();

    private Long chat_id;

    protected Chat(Long chatId) {
        chat_id = chatId;
    }
    protected Chat(){}

    public void setChat_id(Long chatId){
        this.chat_id = chatId;
    }

    public List<Message> getMessages() {
        return messages;
    }

    public void setMessages(List<Message> messages) {
        this.messages = messages;
    }

    public void addMessage(Message message){
        this.messages.add(message);
    }

    public Long getChat_id() {
        return chat_id;
    }
}
