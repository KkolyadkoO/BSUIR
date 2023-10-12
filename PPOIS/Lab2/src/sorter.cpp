#include "../inc/sorter.h"

// Sorter --------------------------------------------------
Sorter::Sorter(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_, int salary_)
    : PostMan(name_, address_, phoneNumber_, mail_, salary_) {}
void Sorter::sortPackage(std::vector<Letter> &letters, std::vector<Parcel> &parcels, std::string postOfficeAddress)
{
    for (size_t i = 0; i < letters.size(); i++)
    {
        if (letters[i].getLocation() == postOfficeAddress)
            letters[i].setOnPostOffice(true);
    }
    for (size_t i = 0; i < parcels.size(); i++)
    {
        if (parcels[i].getLocation() == postOfficeAddress)
            parcels[i].setOnPostOffice(true);
    }
}
