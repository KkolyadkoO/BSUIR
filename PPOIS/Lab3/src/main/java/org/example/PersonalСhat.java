package org.example;

public class PersonalСhat extends Chat {

    private final Long first_member_id;

    private final Long second_member_id;

    public PersonalСhat(Long chatId, Long firstMember, Long secondMember) {
        super(chatId);
        first_member_id = firstMember;
        second_member_id = secondMember;
    }
    public PersonalСhat( Long firstMember, Long secondMember){
        if (firstMember<secondMember){
        first_member_id = firstMember;
        second_member_id = secondMember;}
        else {
            first_member_id = secondMember;
            second_member_id = firstMember;
        }
    }


    public Long getFirst_member_id() {
        return first_member_id;
    }

    public Long getSecond_member_id() {
        return second_member_id;
    }

}
