package org.example;

import java.sql.Timestamp;

public class Message {


    private final String text;
    private final Timestamp timeOfSending;
    private final Long sender_id;

    /**
     * Message constructor with Timestamp timeOfSending
     * @param text text of message
     * @param timeOfSending time of sending
     * @param senderId sender id of message
     */
    public Message(String text, Timestamp timeOfSending, Long senderId) {
        this.text = text;
        this.timeOfSending = timeOfSending;
        sender_id = senderId;
    }

    /**
     * Message constructor with Long timeOfSending
     * @param text text of message
     * @param timeOfSending time of sending
     * @param senderId sender id of message
     */
    public Message(String text, long timeOfSending, long senderId) {
        this.text = text;
        this.timeOfSending = new Timestamp(timeOfSending);
        sender_id = senderId;
    }

    /**
     * text getter
     * @return text
     */
    public String getText() {
        return text;
    }

    /**
     * timeOfSending getter
     * @return time of sending
     */
    public Timestamp getTimeOfSending() {
        return timeOfSending;
    }

    /**
     * sender_id getter
     * @return id of sender
     */
    public Long getSender_id() {
        return sender_id;
    }
}
