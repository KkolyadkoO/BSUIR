#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "packege.h"
#include "customer.h"
/**
 * @brief A class letter
 *
 */
class Letter : public Package
{
public:
    const std::string letterText;
    /**
     * @brief Construct a new Letter object
     *
     * @param sender_
     * @param recipient_
     * @param weight_
     * @param location_
     * @param letterText_
     */
    Letter(Customer sender_, Customer recipient_, double weight_, const std::string &location_, const std::string &letterText_);
};