package org.example;


import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.List;

class Main {
    public static void main(String[] args) {
        SocialNetwork sn = new SocialNetwork();

       sn.addGroupMessage(2L, "salam", 15L);
    }

}