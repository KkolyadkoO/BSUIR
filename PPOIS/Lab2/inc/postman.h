#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "person.h"

/**
 * @brief A class Postman
 *
 */
class PostMan : public Person
{
private:
    int salary;

public:
    /**
     * @brief Construct a new Postman object
     *
     * @param name_ Postman's Name
     * @param address_ Postman's address
     * @param phoneNumber_ Postman's phone number
     * @param mail_ Postman's mail
     * @param salary_ Postman's salary
     */
    PostMan(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_, int salary_);
    /**
     * @brief Display info about the postman
     *
     */
    void displayInfo() const override;
    /**
     * @brief Get the Salary object
     *
     * @return int salary
     */
    int getSalary();
};