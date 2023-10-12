#pragma once
#include <iostream>
#include <fstream>
#include <vector>

/**
 * @brief A class containing the address of the parcel
 *
 */
class DeliveryAddress
{
private:
    std::string postcode;
    std::string address;

public:
    /**
     * @brief Set the Delivery Address object
     *
     * @param postcode_ Postcode
     * @param address_ Address
     */
    void setDeliveryAddress(const std::string &postcode_, const std::string &address_);
    /**
     * @brief Get the Postcode object
     *
     * @return std::string Postcode
     */
    std::string getPostcode();
    /**
     * @brief Get the Address object
     *
     * @return std::string Address
     */
    std::string getAddress();
};
