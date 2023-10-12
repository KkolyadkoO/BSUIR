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



