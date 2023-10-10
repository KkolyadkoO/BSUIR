#include "../inc/postal_office.h"

// Postal Office ---------------------------------------------------
PostalOffice::PostalOffice(const std::string &address_, const std::string &openingHours_, const std::string &service_)
    : address(address_), openingHours(openingHours_), service(service_) {}

void PostalOffice::displayInfo() const
{
    std::cout << "Postal Office Information:" << std::endl;
    std::cout << "Address: " << PostalOffice::address << std::endl;
    std::cout << "Opening hours: " << PostalOffice::openingHours << std::endl;
    std::cout << "Service: " << PostalOffice::service << std::endl;
}

std::string PostalOffice::getAddress() const
{
    return address;
}
std::string PostalOffice::getOpeningHours() const
{
    return openingHours;
}
std::string PostalOffice::getService() const
{
    return service;
}
void PostalOffice::loadClients(std::ifstream &fileDate)
{
    std::string name, address, phoneNumber, mail, postcode, clientID;
    std::getline(fileDate, name);
    getline(fileDate, address);
    getline(fileDate, phoneNumber);
    getline(fileDate, mail);
    getline(fileDate, clientID);
    getline(fileDate, postcode);
    Customer customer(name, address, phoneNumber, mail, stoi(clientID), postcode);
    clients.push_back(customer);
}
void PostalOffice::showClients()
{
    for (size_t i = 0; i < clients.size(); i++)
    {
        std::cout << "---------------------------- "
                  << "Client number " << i + 1 << " ----------------------------" << std::endl;
        clients[i].displayInfo();
    }
}
void PostalOffice::loadPostmans(std::ifstream &fileDate)
{

    std::string name, address, phoneNumber, mail, salary, position;
    std::getline(fileDate, name);
    getline(fileDate, address);
    getline(fileDate, phoneNumber);
    getline(fileDate, mail);
    getline(fileDate, salary);
    getline(fileDate, position);
    if (position == "sorter")
    {
        Sorter sorter(name, address, phoneNumber, mail, stoi(salary));
        sorters.push_back(sorter);
    }
    if (position == "deliveryman")
    {
        Deliveryman deliveryman(name, address, phoneNumber, mail, stoi(salary));
        deliverymans.push_back(deliveryman);
    }
}
void PostalOffice::showPostmans()
{
    for (size_t i = 0; i < sorters.size(); i++)
    {
        std::cout << "---------------------------- "
                  << "Sorter number " << i + 1 << " ----------------------------" << std::endl;
        sorters[i].displayInfo();
    }
    for (size_t i = 0; i < deliverymans.size(); i++)
    {
        std::cout << "---------------------------- "
                  << "Deliveryman number " << i + 1 << " ----------------------------" << std::endl;
        deliverymans[i].displayInfo();
    }
}
void PostalOffice::loadLetter(std::ifstream &fileDate)
{
    bool senderFinded = false, recipientFinded = false;
    int senderNumber, recipientNumber;
    std::string weight, location, text = "", senderID, recipientID, allText = "";
    getline(fileDate, senderID);
    getline(fileDate, recipientID);
    getline(fileDate, weight);
    getline(fileDate, location);
    while (text != "END TEXT")
    {
        getline(fileDate, text);
        allText += text;
    }
    for (size_t i = 0; i < clients.size(); i++)
    {
        if (stoi(senderID) == clients[i].getClientID())
        {
            senderNumber = i;
            senderFinded = true;
        }
        if (stoi(recipientID) == clients[i].getClientID())
        {
            recipientNumber = i;
            recipientFinded = true;
        }
    }
    if (recipientFinded && senderFinded)
    {
        Letter letter(clients[senderNumber], clients[recipientNumber], stof(weight), location, allText);
        letters.push_back(letter);
    }
}
void PostalOffice::loadParcel(std::ifstream &fileDate)
{
    bool senderFinded = false, recipientFinded = false;
    int senderNumber, recipientNumber;
    std::string weight, location, senderID, recipientID, length, width, height;
    getline(fileDate, senderID);
    getline(fileDate, recipientID);
    getline(fileDate, weight);
    getline(fileDate, location);
    getline(fileDate, length);
    getline(fileDate, width);
    getline(fileDate, height);

    for (size_t i = 0; i < clients.size(); i++)
    {
        if (stoi(senderID) == clients[i].getClientID())
        {
            senderNumber = i;
            senderFinded = true;
        }
        if (stoi(recipientID) == clients[i].getClientID())
        {
            recipientNumber = i;
            recipientFinded = true;
        }
    }
    if (recipientFinded && senderFinded)
    {
        Parcel parcel(clients[senderNumber], clients[recipientNumber], stof(weight), location, stof(length), stof(width), stof(height));
        parcels.push_back(parcel);
    }
}

void PostalOffice::sortPackage()
{
    if (sorters.size() == 0)
    {
        std::cout << "There are no srters at the post office";
        return;
    }
    sorters[sorters.size() - 1].sortPackage(letters, parcels, address);
    for (size_t i = 0; i < letters.size(); i++)
    {
        if (letters[i].getOnPostOffice())
        {
            for (size_t j = 0; j < deliverymans.size(); j++)
            {
                deliverymans[j].addLetter(letters[i]);
            }
        }
    }
    for (size_t i = 0; i < parcels.size(); i++)
    {
        if (parcels[i].getOnPostOffice())
        {
            for (size_t j = 0; j < deliverymans.size(); j++)
            {
                deliverymans[j].addParcel(parcels[i]);
            }
        }
    }
}
void PostalOffice::loadDate(std::string filename)
{
    std::ifstream fileDate(filename);
    if (fileDate.is_open())
    {
        bool senderFinded = false, recipientFinded = false;
        int senderNumber, recipientNumber;
        std::string typeOfLoading;
        while (std::getline(fileDate, typeOfLoading))
        {
            if (typeOfLoading == "Letter")
            {
                loadLetter(fileDate);
            }
            if (typeOfLoading == "Postman")
            {
                loadPostmans(fileDate);
            }
            if (typeOfLoading == "Parcel")
            {
                loadParcel(fileDate);
            }
            if (typeOfLoading == "Client")
            {
                loadClients(fileDate);
            }
        }

        fileDate.close();
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
    }
}
int PostalOffice::getNumberOfClients()
{
    return clients.size();
}
int PostalOffice::getNumberOfPostmans()
{
    return sorters.size() + deliverymans.size();
}
int PostalOffice::getPackageInStock()
{
    return deliverymans[0].getPackageInStock();
}

// Person ---------------------------------------------------
Person::Person(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_)
    : name(name_), address(address_), phoneNumber(phoneNumber_), mail(mail_) {}

void Person::displayInfo() const
{
    std::cout << "Name: " << Person::name << std::endl;
    std::cout << "Address: " << Person::address << std::endl;
    std::cout << "Phone number: " << Person::phoneNumber << std::endl;
    std::cout << "Mail: " << Person::mail << std::endl;
}

std::string Person::getAddress() const
{
    return address;
}
std::string Person::getName() const
{
    return name;
}
std::string Person::getPhoneNumer() const
{
    return phoneNumber;
}
std::string Person::getMail() const
{
    return mail;
}

// Customer ---------------------------------------------------
Customer::Customer(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_, int clientID_, const std::string postcode_)
    : Person(name_, address_, phoneNumber_, mail_), clientID(clientID_), postcode(postcode_) {}

void Customer::displayInfo() const
{
    std::cout << "Customer Information:" << std::endl;
    Person::displayInfo();
    std::cout << "ClientID: " << clientID << std::endl;
    std::cout << "Postcode: " << postcode << std::endl;
}
int Customer::getClientID()
{
    return clientID;
}
std::string Customer::getPostcode()
{
    return postcode;
}

// PostMan ---------------------------------------------------
PostMan::PostMan(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_, int salary_)
    : Person(name_, address_, phoneNumber_, mail_), salary(salary_) {}
void PostMan::displayInfo() const
{
    std::cout << "Postman Information:" << std::endl;
    Person::displayInfo();
    std::cout << "Salary: " << salary << std::endl;
}
int PostMan::getSalary()
{
    return salary;
}

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

// Letter ---------------------------------------------------
Letter::Letter(Customer sender_, Customer recipient_, double weight_, const std::string &location_, const std::string &letterText_)
    : Package(sender_, recipient_, weight_, location_), letterText(letterText_) {}

// Parcel ---------------------------------------------------
Parcel::Parcel(Customer sender_, Customer recipient_, double weight_, const std::string &location_, double length_, double width_, double height_)
    : Package(sender_, recipient_, weight_, location_), length(length_), width(width_), height(height_) {}

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
