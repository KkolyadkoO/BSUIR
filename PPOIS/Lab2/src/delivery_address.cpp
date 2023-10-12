#include "../inc/delivery_address.h"

// DeliveryAddress ---------------------------------------------------
void DeliveryAddress::setDeliveryAddress(const std::string &postcode_, const std::string &address_)
{
    postcode = postcode_;
    address = address_;
}
std::string DeliveryAddress::getAddress()
{
    return address;
}
std::string DeliveryAddress::getPostcode()
{
    return postcode;
}
