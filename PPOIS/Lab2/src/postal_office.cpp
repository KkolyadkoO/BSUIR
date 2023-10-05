#include "../inc/postal_office.h"

// Postal Office ---------------------------------------------------
PostalOffice::PostalOffice(const std::string& address_, const std::string& openingHours_, const std::string& service_)
: address(address_), openingHours(openingHours_), service(service_) {}

void PostalOffice::displayInfo() const{
    std::cout << "Postal Office Information:"<<std::endl;
    std::cout << "Address: " << PostalOffice::address << std::endl;
    std::cout << "Opening hours: " << PostalOffice::openingHours << std::endl;
    std::cout << "Service: " << PostalOffice::service << std::endl;
}

std::string PostalOffice::getAddress() const{
    return address;
}
std::string PostalOffice::getOpeningHours() const{
    return openingHours;
}
std::string PostalOffice::getService() const{
    return service;
}
void PostalOffice::loadClients(std::string filename){
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::string name, address, phoneNumber, mail, postcode, clientID;
        while (std::getline(inputFile, name)) {
            getline(inputFile, address);
            getline(inputFile, phoneNumber);
            getline(inputFile, mail);
            getline(inputFile, clientID);
            getline(inputFile, postcode);
            Customer customer(name,address,phoneNumber,mail,stoi(clientID),postcode);
            clients.push_back(customer);
        }

        inputFile.close();
    } else {
        std::cout << "Unable to open file:"<< filename << std::endl;
    }
}
void PostalOffice::showClients(){
    for (size_t i = 0; i < clients.size(); i++)
    {
        std::cout << "---------------------------- "<< "Client number " << i+1 << " ----------------------------"<<std::endl;
        clients[i].displayInfo();
    }
    
}
void PostalOffice::loadPostmans(std::string filename){
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::string name, address, phoneNumber, mail, salary,position;
        while (std::getline(inputFile, name)) {
            getline(inputFile, address);
            getline(inputFile, phoneNumber);
            getline(inputFile, mail);
            getline(inputFile, salary);
            getline(inputFile, position);
            if(position == "sorter"){
            Sorter sorter(name, address,phoneNumber,mail,stoi(salary));
            sorters.push_back(sorter);
            }
            if(position == "deliveryman"){
            Deliveryman deliveryman(name, address,phoneNumber,mail,stoi(salary));
            deliverymans.push_back(deliveryman);
            }
        }

        inputFile.close();
    } else {
        std::cout << "Unable to open file:"<< filename << std::endl;
    }
}
void PostalOffice::showPostmans(){
    for (size_t i = 0; i < sorters.size(); i++)
    {
        std::cout << "---------------------------- "<< "Sorter number " << i+1 << " ----------------------------"<<std::endl;
        sorters[i].displayInfo();
    }
    for (size_t i = 0; i < deliverymans.size(); i++)
    {
        std::cout << "---------------------------- "<< "Deliveryman number " << i+1 << " ----------------------------"<<std::endl;
        deliverymans[i].displayInfo();
    }
}
void PostalOffice::loadPackage(std::string letterFilename,std::string parcelFilename){
    std::ifstream letterFile(letterFilename);
    if (letterFile.is_open()) {
        bool senderFinded=false,recipientFinded=false;
        int senderNumber,recipientNumber;
        std::string weight, location, text,senderID,recipientID;
        while (std::getline(letterFile, senderID)) {
            getline(letterFile, recipientID);
            getline(letterFile, weight);
            getline(letterFile, location);
            getline(letterFile, text);
            for (size_t i = 0; i < clients.size(); i++)
            {
                if(stoi(senderID)==clients[i].getClientID())
                {
                   senderNumber = i;
                   senderFinded = true;
                }
                 if(stoi(recipientID)==clients[i].getClientID())
                {
                   recipientNumber = i;
                   recipientFinded = true;
                }
            }
            if(recipientFinded && senderFinded){
            Letter letter(clients[senderNumber],clients[recipientNumber],stof(weight),location,text);
            letters.push_back(letter);
            }
            senderFinded = false;
            recipientFinded = false;
        }

        letterFile.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
    std::ifstream parcelFile(parcelFilename);
    if (parcelFile.is_open()) {
        bool senderFinded=false,recipientFinded=false;
        int senderNumber,recipientNumber;
        std::string weight, location,senderID,recipientID,length,width,height;
        while (std::getline(parcelFile, senderID)) {
            getline(parcelFile, recipientID);
            getline(parcelFile, weight);
            getline(parcelFile, location);
            getline(parcelFile, length);
            getline(parcelFile, width);
            getline(parcelFile, height);

            for (size_t i = 0; i < clients.size(); i++)
            {
                if(stoi(senderID)==clients[i].getClientID())
                {
                   senderNumber = i;
                   senderFinded = true;
                }
                 if(stoi(recipientID)==clients[i].getClientID())
                {
                   recipientNumber = i;
                   recipientFinded = true;
                }
            }
            if(recipientFinded && senderFinded){
                Parcel parcel(clients[senderNumber],clients[recipientNumber],stof(weight),location,stof(length),stof(width),stof(height));
                parcels.push_back(parcel);
            }
            senderFinded = false;
            recipientFinded = false;
        }

        parcelFile.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
}


// Person ---------------------------------------------------
Person::Person(const std::string& name_,const std::string& address_,const std::string& phoneNumber_,const std::string& mail_)
: name(name_), address(address_),phoneNumber(phoneNumber_),mail(mail_){}

void Person::displayInfo() const{
    std::cout << "Name: " << Person::name << std::endl;
    std::cout << "Address: " << Person::address << std::endl;
    std::cout << "Phone number: " << Person::phoneNumber << std::endl;
    std::cout << "Mail: " << Person::mail << std::endl;
}

std::string Person::getAddress() const{
    return address;
}
std::string Person::getName() const{
    return name;
}
std::string Person::getPhoneNumer() const{
    return phoneNumber;
}
std::string Person::getMail() const{
    return mail;
}

// Customer ---------------------------------------------------
Customer::Customer(const std::string& name_,const std::string& address_,const std::string& phoneNumber_,const std::string& mail_, int clientID_,const std::string postcode_)
:Person(name_,address_,phoneNumber_,mail_),clientID(clientID_),postcode(postcode_){}

void Customer::displayInfo()const{
    std::cout << "Customer Information:"<<std::endl;
    Person::displayInfo();
    std::cout << "ClientID: " << clientID << std::endl;
    std::cout << "Postcode: " << postcode << std::endl;
}
int Customer::getClientID(){
    return clientID;
}
std::string Customer::getPostcode(){
    return postcode;
}

// PostMan ---------------------------------------------------
PostMan::PostMan(const std::string& name_,const std::string& address_,const std::string& phoneNumber_,const std::string& mail_, int salary_)
:Person(name_,address_,phoneNumber_,mail_),salary(salary_){}
void PostMan::displayInfo()const{
    std::cout << "Postman Information:"<<std::endl;
    Person::displayInfo();
    std::cout << "Salary: " << salary << std::endl;
}
int PostMan::getSalary(){
    return salary;
}

// Package ---------------------------------------------------
Package::Package(Customer sender_,Customer recipient_,double weight_,const std::string& location_)
:location(location_),sender(sender_),recipient(recipient_),weight(weight_){
    address.setDeliveryAddress(recipient_.getPostcode(),recipient_.getAddress());
}
std::string Package::getLocation(){
    return location;
}
void Package::setLocation(const std::string& location_){
    location = location_;
}
void Package::setOnPostOffice(bool value){
    onPostOffice = value;
}

// Letter ---------------------------------------------------
Letter::Letter(Customer sender_,Customer recipient_,double weight_,const std::string& location_,const std::string& letterText_)
:Package(sender_,recipient_,weight_,location_),letterText(letterText_){}

// Parcel ---------------------------------------------------
Parcel::Parcel(Customer sender_,Customer recipient_,double weight_,const std::string& location_, double length_, double width_, double height_)
:Package(sender_,recipient_,weight_,location_),length(length_),width(width_),height(height_){}

// DeliveryAddress ---------------------------------------------------
void DeliveryAddress::setDeliveryAddress(const std::string& postcode_,const std::string& address_)
{
    postcode = postcode_;
    address = address_;
}
std::string DeliveryAddress::getAddress(){
    return address;
}
std::string DeliveryAddress::getPostcode(){
    return postcode;
}

// Sorter --------------------------------------------------
Sorter::Sorter(const std::string& name_,const std::string& address_,const std::string& phoneNumber_,const std::string& mail_, int salary_)
:PostMan(name_,address_,phoneNumber_,mail_,salary_){}
void Sorter::sortPackage(std::vector<Letter>& letters,std::vector<Parcel>& parcels,std::string postOfficeAddress){
    for (size_t i = 0; i < letters.size(); i++)
    {
        if(letters[i].getLocation()==postOfficeAddress)
        letters[i].setOnPostOffice(true);
    }
    for (size_t i = 0; i < parcels.size(); i++)
    {
        if(parcels[i].getLocation()==postOfficeAddress)
        parcels[i].setOnPostOffice(true);
    }
}

// Deliveryman ---------------------------------------------
Deliveryman::Deliveryman(const std::string& name_,const std::string& address_,const std::string& phoneNumber_,const std::string& mail_, int salary_)
:PostMan(name_,address_,phoneNumber_,mail_,salary_){}