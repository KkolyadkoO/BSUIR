package org.example;

public class Friend {

    private final Long friend_id;


    /**
     *  Friend constructor
     * @param friend_id id of friend
     */
    public Friend(Long friend_id) {
        this.friend_id = friend_id;
    }

    /**
     *  id getter
     * @return id of friends
     */
    public Long getFriend_id() {
        return friend_id;
    }
}
