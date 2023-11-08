package org.example;

public class PersonalСhat extends Chat {

    private final Long firstMember_id;

    private final Long secondMember_id;


    /**
     * PersonalСhat constructor with chat id
     * @param chatId id of chat
     * @param firstMember id of first member
     * @param secondMember id of second member
     */
    public PersonalСhat(Long chatId, Long firstMember, Long secondMember) {
        super(chatId);
        firstMember_id = firstMember;
        secondMember_id = secondMember;
    }

    /**
     * PersonalСhat constructor without chat id
     * @param firstMember id of first member
     * @param secondMember id of second member
     */
    public PersonalСhat( Long firstMember, Long secondMember){
        if (firstMember<secondMember){
        firstMember_id = firstMember;
        secondMember_id = secondMember;}
        else {
            firstMember_id = secondMember;
            secondMember_id = firstMember;
        }
    }

    /**
     * firstMember_id
     * @return id of first member
     */
    public Long getFirstMember_id() {
        return firstMember_id;
    }

    /**
     * secondMember_id
     * @return id of second member
     */
    public Long getSecondMember_id() {
        return secondMember_id;
    }

}
