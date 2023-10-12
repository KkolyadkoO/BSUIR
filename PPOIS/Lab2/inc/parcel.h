#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "customer.h"
#include "packege.h"

/**
 * @brief A class parcel
 *
 */
class Parcel : public Package
{
private:
    double length;
    double width;
    double height;

public:
    /**
     * @brief Construct a new Parcel object
     *
     * @param sender_
     * @param recipient_
     * @param weight_
     * @param location_
     * @param length_
     * @param width_
     * @param height_
     */
    Parcel(Customer sender_, Customer recipient_, double weight_, const std::string &location_, double length_, double width_, double height_);
};