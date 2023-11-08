package org.example;

import org.junit.jupiter.api.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;
import static org.junit.jupiter.api.Assertions.assertEquals;

class SocialNetworkTest {

    @Test
    void getCustomers() {
        SocialNetwork sn = new SocialNetwork();
        var customers = sn.getCustomers();
        assertTrue(customers.size() - 1 != 0);
    }

    @Test
    void addCustomers() {
        var socialNetwork = new SocialNetwork();
        var customer = new Customer("Ivan", "Ivanov", new Photo("https:/asdasd"), "+375 (23) 123-123-12");
        var customer_size = socialNetwork.getCustomers().size() - 1;
        socialNetwork.addCustomers(customer);
        assertEquals(customer_size + 1, socialNetwork.getCustomers().size() - 1);
        socialNetwork.deleteCustomer(customer.getId());
        assertEquals(customer_size, socialNetwork.getCustomers().size() - 1);
    }

    @Test
    void getGroupChats() {
        SocialNetwork sn = new SocialNetwork();
        var groupChats = sn.getGroupChats();
        assertTrue(groupChats.size() - 1 != 0);
    }

    @Test
    void addGroupChats() {
        var socialNetwork = new SocialNetwork();
        var groupChat = new GroupChat("Test_chat");
        var size = socialNetwork.getGroupChats().size() - 1;
        socialNetwork.addGroupChats(groupChat);
        assertEquals(size + 1, socialNetwork.getGroupChats().size() - 1);
        socialNetwork.deleteGroupChat(groupChat.getChat_id());
        assertEquals(size, socialNetwork.getGroupChats().size() - 1);
    }

    @Test
    void getPersonalСhats() {
        var socialNetwork = new SocialNetwork();
        var personalСhats = socialNetwork.getPersonalСhats();
        assertTrue(personalСhats.size() - 1 != 0);
    }

    @Test
    void addPersonalСhats() {
        var socialNetwork = new SocialNetwork();
        var personalСhat = new PersonalСhat(21L, 1L);
        var size = socialNetwork.getPersonalСhats().size() - 1;
        socialNetwork.addPersonalСhats(personalСhat);
        assertEquals(size + 1, socialNetwork.getPersonalСhats().size() - 1);
        socialNetwork.deletePersonalChat(personalСhat.getChat_id());
        assertEquals(size, socialNetwork.getPersonalСhats().size() - 1);
    }

    @Test
    void addPersonalMessage() {
        var socialNetwork = new SocialNetwork();
        var size = socialNetwork.getPersonalСhats().get(1).getMessages().size() - 1;
        socialNetwork.addPersonalMessage(2L, "test", 15L);
        assertEquals(size + 1, socialNetwork.getPersonalСhats().get(1).getMessages().size() - 1);
        socialNetwork.deletePersonalMessage(2L, "test", 15L);
        assertEquals(size, socialNetwork.getPersonalСhats().get(1).getMessages().size() - 1);
    }

    @Test
    void addGroupMessage() {
        var socialNetwork = new SocialNetwork();
        var size = socialNetwork.getGroupChats().get(0).getMessages().size() - 1;
        socialNetwork.addGroupMessage(1L, "test", 1L);
        assertEquals(size + 1, socialNetwork.getGroupChats().get(0).getMessages().size() - 1);
        socialNetwork.deleteGroupMessage(1L , "test", 1L);
        assertEquals(size, socialNetwork.getGroupChats().get(0).getMessages().size() - 1);
    }
}