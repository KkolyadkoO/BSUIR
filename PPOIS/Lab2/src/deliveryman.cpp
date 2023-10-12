#include "../inc/deliveryman.h"

// Deliveryman ---------------------------------------------
Deliveryman::Deliveryman(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_, int salary_)
    : PostMan(name_, address_, phoneNumber_, mail_, salary_) {}
void Deliveryman::addLetter(Letter letter)
{
    lettersInStock.push_back(letter);
}
void Deliveryman::addParcel(Parcel parcel)
{
    parcelInStock.push_back(parcel);
}
int Deliveryman::getPackageInStock()
{
    return lettersInStock.size() + parcelInStock.size();
}
