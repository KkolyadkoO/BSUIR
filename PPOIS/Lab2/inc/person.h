#pragma once
#include <iostream>
#include <fstream>
#include <vector>
/**
 * @brief Parent class for client and employee
 *
 */
class Person
{
protected:
    /**
     * @brief Construct a new Person object
     *
     * @param name_ Persons's name
     * @param address_ Persons's address
     * @param phoneNumber_ Persons's number
     * @param mail_ Persons's mail
     */
    Person(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_);

private:
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::string mail;

public:
    /**
     * @brief Displaying information about a person
     *
     */
    virtual void displayInfo() const;
    /**
     * @brief Get the Address object
     *
     * @return std::string Address
     */
    std::string getAddress() const;
    /**
     * @brief Get the Name object
     *
     * @return std::string Name
     */
    std::string getName() const;
    /**
     * @brief Get the Phone Numer object
     *
     * @return std::string Phone number
     */
    std::string getPhoneNumer() const;
    /**
     * @brief Get the Mail object
     *
     * @return std::string mail
     */
    std::string getMail() const;
};