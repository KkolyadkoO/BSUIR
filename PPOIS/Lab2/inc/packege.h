#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "customer.h"
#include "delivery_address.h"
/**
 * @brief A class package
 *
 */
class Package
{
protected:
    /**
     * @brief Construct a new Package object
     *
     * @param sender_ Customer sender
     * @param recipient_ Customer recipient
     * @param weight_ Package's weight
     * @param location_ Package's location
     */
    Package(const Customer sender_, const Customer recipient_, double weight_, const std::string &location_);

private:
    std::string location;
    bool onPostOffice = false;

public:
    const Customer sender;
    const Customer recipient;
    const double weight;
    DeliveryAddress address;
    /**
     * @brief Get the Location object
     *
     * @return std::string location
     */
    std::string getLocation();
    /**
     * @brief Set the Location object
     *
     * @param location_
     */
    void setLocation(const std::string &location_);
    /**
     * @brief Set the On Post Office object
     *
     * @param value true/false
     */
    void setOnPostOffice(bool value);
    /**
     * @brief Get the parcel is at the post office
     *
     * @return true
     * @return false
     */
    bool getOnPostOffice();
};