#include "../inc/person.h"
// Person ---------------------------------------------------
Person::Person(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_)
    : name(name_), address(address_), phoneNumber(phoneNumber_), mail(mail_) {}

void Person::displayInfo() const
{
    std::cout << "Name: " << Person::name << std::endl;
    std::cout << "Address: " << Person::address << std::endl;
    std::cout << "Phone number: " << Person::phoneNumber << std::endl;
    std::cout << "Mail: " << Person::mail << std::endl;
}

std::string Person::getAddress() const
{
    return address;
}
std::string Person::getName() const
{
    return name;
}
std::string Person::getPhoneNumer() const
{
    return phoneNumber;
}
std::string Person::getMail() const
{
    return mail;
}

