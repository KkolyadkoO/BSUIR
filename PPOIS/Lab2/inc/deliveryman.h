#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "postman.h"
#include "letter.h"
#include "parcel.h"

/**
 * @brief A class deliveryman
 *
 */
class Deliveryman : public PostMan
{
private:
    std::vector<Letter> lettersInStock;
    std::vector<Parcel> parcelInStock;

public:
    /**
     * @brief Construct a new Deliveryman object
     *
     * @param name_
     * @param address_
     * @param phoneNumber_
     * @param mail_
     * @param salary_
     */
    Deliveryman(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_, int salary_);
    /**
     * @brief add letter in lettersInStock
     *
     * @param letter
     */
    void addLetter(Letter letter);
    /**
     * @brief add letter in parcelInStock
     *
     * @param parcel
     */
    void addParcel(Parcel parcel);
    /**
     * @brief Get the Package In Stock object
     *
     * @return int number of all packege in stock
     */
    int getPackageInStock();
};