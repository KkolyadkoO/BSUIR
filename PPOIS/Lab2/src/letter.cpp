#include "../inc/letter.h"

// Letter ---------------------------------------------------
Letter::Letter(Customer sender_, Customer recipient_, double weight_, const std::string &location_, const std::string &letterText_)
    : Package(sender_, recipient_, weight_, location_), letterText(letterText_) {}
