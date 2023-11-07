package org.example;

import java.sql.Timestamp;

public class Message {


    private final String text;
    private final Timestamp timeOfSending;
    private final Long sender_id;

    public Message(String text, Timestamp timeOfSending, Long senderId) {
        this.text = text;
        this.timeOfSending = timeOfSending;
        sender_id = senderId;
    }

    public Message(String text, long timeOfSending, long senderId) {
        this.text = text;
        this.timeOfSending = new Timestamp(timeOfSending);
        sender_id = senderId;
    }

    public String getText() {
        return text;
    }

    public Timestamp getTimeOfSending() {
        return timeOfSending;
    }

    public Long getSender_id() {
        return sender_id;
    }
}
