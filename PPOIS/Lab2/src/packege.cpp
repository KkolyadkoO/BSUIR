#include "../inc/packege.h"


// Package ---------------------------------------------------
Package::Package(Customer sender_, Customer recipient_, double weight_, const std::string &location_)
    : location(location_), sender(sender_), recipient(recipient_), weight(weight_)
{
    address.setDeliveryAddress(recipient_.getPostcode(), recipient_.getAddress());
}
std::string Package::getLocation()
{
    return location;
}
void Package::setLocation(const std::string &location_)
{
    location = location_;
}
void Package::setOnPostOffice(bool value)
{
    onPostOffice = value;
}
bool Package::getOnPostOffice()
{
    return onPostOffice;
}

