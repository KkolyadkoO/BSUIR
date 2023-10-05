#pragma once
#include <iostream>
#include <fstream>
#include <vector>


class DeliveryAddress{
private:
    std::string postcode;
    std::string address;
public:
    void setDeliveryAddress(const std::string& postcode_,const std::string& address_);
    std::string getPostcode();
    std::string getAddress();
};

class Person{
protected:
    Person(const std::string& name_,const std::string& address_,const std::string& phoneNumber_,const std::string& mail_);
private:
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::string mail;
public:
    virtual void displayInfo() const;
    std::string getAddress() const;
    std::string getName() const;
    std::string getPhoneNumer() const;
    std::string getMail() const;

};

class Customer : public Person{
private:
    int clientID;
    std::string postcode;
public:
    Customer(const std::string& name_,const std::string& address_,const std::string& phoneNumber_,const std::string& mail_, int clientID_,const std::string postcode_);

    void displayInfo()const override;

    int getClientID();
    std::string getPostcode();
};

class PostMan : public Person{
private:
    int salary;
public:
    PostMan(const std::string& name_,const std::string& address_,const std::string& phoneNumber_,const std::string& mail_, int salary_);

    void displayInfo()const override;

    int getSalary();
};

class Package {
protected:
    Package(const Customer sender_,const Customer recipient_,double weight_,const std::string& location_);
private:
    std::string location;
    bool onPostOffice = false;
public:
    const Customer sender;
    const Customer recipient;
    const double weight;
    DeliveryAddress address;
    std::string getLocation();
    void setLocation(const std::string& location_);
    void setOnPostOffice(bool value);
};

class Letter : public Package{
public:
    const std::string letterText;
    Letter(Customer sender_,Customer recipient_,double weight_,const std::string& location_,const std::string& letterText_);
};

class Parcel : public Package{
private:
        double length;
        double width;
        double height;
public:
    Parcel(Customer sender_,Customer recipient_,double weight_,const std::string& location_, double length_, double width_, double height_);
};

class Sorter : public PostMan{
public:
    Sorter(const std::string& name_,const std::string& address_,const std::string& phoneNumber_,const std::string& mail_, int salary_);
    void sortPackage(std::vector<Letter>& letters,std::vector<Parcel>& parcels,std::string postOfficeAddress);
};

class Deliveryman : public PostMan{
private:
    std::vector<Letter> lettersInStock;
public:
    Deliveryman(const std::string& name_,const std::string& address_,const std::string& phoneNumber_,const std::string& mail_, int salary_);

};

class PostalOffice{
private:
    std::string address;
    std::string openingHours;
    std::string service;
    std::vector<Customer> clients;
    std::vector<Sorter> sorters;
    std::vector<Deliveryman> deliverymans;
    std::vector<Letter> letters;
    std::vector<Parcel> parcels;
public:
    PostalOffice(const std::string& address_, const std::string& openingHours_, const std::string& service_);

    void displayInfo() const;
    std::string getAddress() const;
    std::string getOpeningHours() const;
    std::string getService() const;
    void loadClients(std::string filename);
    void showClients();
    void loadPostmans(std::string filename);
    void showPostmans();
    void loadPackage(std::string letterFilename,std::string parcelFilename);

};