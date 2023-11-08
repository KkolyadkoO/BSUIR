package org.example;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Customer {

    private Long id;
    private Photo avatar = new Photo(null);

    List<Friend> friends = new ArrayList<>();
    private final String first_name;
    private final String second_name;

    private String phoneNumber;

    /**
     * Customer constructor
     * @param name First_name
     * @param second_name Second_name
     * @param avatar Photo
     * @param phoneNumber number
     */
    public Customer( String name, String second_name, Photo avatar, String phoneNumber) {
        this.first_name = name;
        this.avatar = avatar;
        this.second_name = second_name;
        this.phoneNumber = phoneNumber;
    }

    /**
     * avatar getter
     * @return avatar
     */
    public Photo getAvatar() {
        return avatar;
    }

    /**
     * setter avatar
     * @param avatar Photo
     */
    public void setAvatar(Photo avatar) {
        this.avatar = avatar;
    }

    /**
     * first_name getter
     * @return first_name
     */
    public String getFirst_name() {
        return first_name;
    }

    /**
     * second_name getter
     * @return second_name
     */
    public String getSecond_name() {
        return second_name;
    }

    /**
     *  id getter
     * @return id
     */
    public Long getId() {
        return id;
    }

    /**
     * number getter
     * @return number
     */
    public String getPhoneNumber() {
        return phoneNumber;
    }

    /**
     * number getter
     * @param phoneNumber number
     */
    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    /**
     *  friends setter
     * @param friends list with friends
     */
    public void setFriends(List<Friend> friends) {
        this.friends = friends;
    }

    /**
     * id setter
     * @param id id
     */
    public void setId(Long id) {
        this.id = id;
    }
}
