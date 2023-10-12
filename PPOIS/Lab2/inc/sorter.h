#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "postman.h"
#include "letter.h"
#include "parcel.h"
/**
 * @brief A class sorter
 *
 */
class Sorter : public PostMan
{
public:
    /**
     * @brief Construct a new Sorter object
     *
     * @param name_
     * @param address_
     * @param phoneNumber_
     * @param mail_
     * @param salary_
     */
    Sorter(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_, int salary_);
    /**
     * @brief Sorting all package
     *
     * @param letters
     * @param parcels
     * @param postOfficeAddress
     */
    void sortPackage(std::vector<Letter> &letters, std::vector<Parcel> &parcels, std::string postOfficeAddress);
};