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

    public Customer( String name, String second_name, Photo avatar, String phoneNumber) {
        this.first_name = name;
        this.avatar = avatar;
        this.second_name = second_name;
        this.phoneNumber = phoneNumber;
    }
    public Customer( String name, String second_name, String phoneNumber) {
        this.first_name = name;
        this.second_name = second_name;
        this.phoneNumber = phoneNumber;
    }


    public Photo getAvatar() {
        return avatar;
    }

    public void setAvatar(Photo avatar) {
        this.avatar = avatar;
    }

    public String getFirst_name() {
        return first_name;
    }

    public String getSecond_name() {
        return second_name;
    }

    public Long getId() {
        return id;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public void setFriends(List<Friend> friends) {
        this.friends = friends;
    }

    public void setId(Long id) {
        this.id = id;
    }
}
