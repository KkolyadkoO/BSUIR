#include "../inc/parcel.h"

// Parcel ---------------------------------------------------
Parcel::Parcel(Customer sender_, Customer recipient_, double weight_, const std::string &location_, double length_, double width_, double height_)
    : Package(sender_, recipient_, weight_, location_), length(length_), width(width_), height(height_) {}
