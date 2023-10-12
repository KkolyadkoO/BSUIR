#include "../inc/customer.h"

// Customer ---------------------------------------------------
Customer::Customer(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_, int clientID_, const std::string postcode_)
    : Person(name_, address_, phoneNumber_, mail_), clientID(clientID_), postcode(postcode_) {}

void  Customer::displayInfo() const
{
    std::cout << "Customer Information:" << std::endl;
    Person::displayInfo();
    std::cout << "ClientID: " << clientID << std::endl;
    std::cout << "Postcode: " << postcode << std::endl;
}
int Customer::getClientID()
{
    return clientID;
}
std::string Customer::getPostcode()
{
    return postcode;
}