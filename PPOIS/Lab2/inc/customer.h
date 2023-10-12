#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "person.h"

/**
 * @brief A class Customer
 *
 */
class Customer : public Person
{
private:
    int clientID;
    std::string postcode;
public:
    /**
     * @brief Construct a new Customer object
     *
     * @param name_ Customer's Name
     * @param address_ Customer's Address
     * @param phoneNumber_ Customer's Number
     * @param mail_ Customer's mail
     * @param clientID_ Customer's ID
     * @param postcode_ Customer's postcode
     */
    Customer(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_, int clientID_, const std::string postcode_);
    /**
     * @brief Displays information about the customer
     *
     */
    void displayInfo() const override;
    /**
     * @brief Get the customer ID object
     *
     * @return int clientID
     */
    int getClientID();
    /**
     * @brief Get the Postcode object
     *
     * @return std::string postcode
     */
    std::string getPostcode();
};