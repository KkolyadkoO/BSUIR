#pragma once
#include <iostream>
#include <fstream>
#include <vector>

/**
 * @brief A class containing the address of the parcel
 *
 */
class DeliveryAddress
{
private:
    std::string postcode;
    std::string address;

public:
    /**
     * @brief Set the Delivery Address object
     *
     * @param postcode_ Postcode
     * @param address_ Address
     */
    void setDeliveryAddress(const std::string &postcode_, const std::string &address_);
    /**
     * @brief Get the Postcode object
     *
     * @return std::string Postcode
     */
    std::string getPostcode();
    /**
     * @brief Get the Address object
     *
     * @return std::string Address
     */
    std::string getAddress();
};
/**
 * @brief Parent class for client and employee
 *
 */
class Person
{
protected:
    /**
     * @brief Construct a new Person object
     *
     * @param name_ Persons's name
     * @param address_ Persons's address
     * @param phoneNumber_ Persons's number
     * @param mail_ Persons's mail
     */
    Person(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_);

private:
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::string mail;

public:
    /**
     * @brief Displaying information about a person
     *
     */
    virtual void displayInfo() const;
    /**
     * @brief Get the Address object
     *
     * @return std::string Address
     */
    std::string getAddress() const;
    /**
     * @brief Get the Name object
     *
     * @return std::string Name
     */
    std::string getName() const;
    /**
     * @brief Get the Phone Numer object
     *
     * @return std::string Phone number
     */
    std::string getPhoneNumer() const;
    /**
     * @brief Get the Mail object
     *
     * @return std::string mail
     */
    std::string getMail() const;
};
/**
 * @brief A class Customer
 *
 */
class Customer : public Person
{
private:
    int clientID;
    std::string postcode;
public:
    /**
     * @brief Construct a new Customer object
     *
     * @param name_ Customer's Name
     * @param address_ Customer's Address
     * @param phoneNumber_ Customer's Number
     * @param mail_ Customer's mail
     * @param clientID_ Customer's ID
     * @param postcode_ Customer's postcode
     */
    Customer(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_, int clientID_, const std::string postcode_);
    /**
     * @brief Displays information about the customer
     *
     */
    void displayInfo() const override;
    /**
     * @brief Get the customer ID object
     *
     * @return int clientID
     */
    int getClientID();
    /**
     * @brief Get the Postcode object
     *
     * @return std::string postcode
     */
    std::string getPostcode();
};
/**
 * @brief A class Postman
 *
 */
class PostMan : public Person
{
private:
    int salary;

public:
    /**
     * @brief Construct a new Postman object
     *
     * @param name_ Postman's Name
     * @param address_ Postman's address
     * @param phoneNumber_ Postman's phone number
     * @param mail_ Postman's mail
     * @param salary_ Postman's salary
     */
    PostMan(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_, int salary_);
    /**
     * @brief Display info about the postman
     *
     */
    void displayInfo() const override;
    /**
     * @brief Get the Salary object
     *
     * @return int salary
     */
    int getSalary();
};
/**
 * @brief A class package
 *
 */
class Package
{
protected:
    /**
     * @brief Construct a new Package object
     *
     * @param sender_ Customer sender
     * @param recipient_ Customer recipient
     * @param weight_ Package's weight
     * @param location_ Package's location
     */
    Package(const Customer sender_, const Customer recipient_, double weight_, const std::string &location_);

private:
    std::string location;
    bool onPostOffice = false;

public:
    const Customer sender;
    const Customer recipient;
    const double weight;
    DeliveryAddress address;
    /**
     * @brief Get the Location object
     *
     * @return std::string location
     */
    std::string getLocation();
    /**
     * @brief Set the Location object
     *
     * @param location_
     */
    void setLocation(const std::string &location_);
    /**
     * @brief Set the On Post Office object
     *
     * @param value true/false
     */
    void setOnPostOffice(bool value);
    /**
     * @brief Get the parcel is at the post office
     *
     * @return true
     * @return false
     */
    bool getOnPostOffice();
};
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
/**
 * @brief A class sorter
 *
 */
class Sorter : public PostMan
{
public:
    /**
     * @brief Construct a new Sorter object
     *
     * @param name_
     * @param address_
     * @param phoneNumber_
     * @param mail_
     * @param salary_
     */
    Sorter(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_, int salary_);
    /**
     * @brief Sorting all package
     *
     * @param letters
     * @param parcels
     * @param postOfficeAddress
     */
    void sortPackage(std::vector<Letter> &letters, std::vector<Parcel> &parcels, std::string postOfficeAddress);
};
/**
 * @brief A class deliveryman
 *
 */
class Deliveryman : public PostMan
{
private:
    std::vector<Letter> lettersInStock;
    std::vector<Parcel> parcelInStock;

public:
    /**
     * @brief Construct a new Deliveryman object
     *
     * @param name_
     * @param address_
     * @param phoneNumber_
     * @param mail_
     * @param salary_
     */
    Deliveryman(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_, int salary_);
    /**
     * @brief add letter in lettersInStock
     *
     * @param letter
     */
    void addLetter(Letter letter);
    /**
     * @brief add letter in parcelInStock
     *
     * @param parcel
     */
    void addParcel(Parcel parcel);
    /**
     * @brief Get the Package In Stock object
     *
     * @return int number of all packege in stock
     */
    int getPackageInStock();
};
/**
 * @brief A class postaloffice
 *
 */
class PostalOffice
{
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
    /**
     * @brief Construct a new Postal Office object
     *
     * @param address_
     * @param openingHours_
     * @param service_
     */
    PostalOffice(const std::string &address_, const std::string &openingHours_, const std::string &service_);
    /**
     * @brief display info about postaloffice
     *
     */
    void displayInfo() const;
    /**
     * @brief Get the Address object
     *
     * @return std::string  address
     */
    std::string getAddress() const;
    /**
     * @brief Get the Opening Hours object
     *
     * @return std::string opining hours
     */
    std::string getOpeningHours() const;
    /**
     * @brief Get the Service object
     *
     * @return std::string service
     */
    std::string getService() const;
    /**
     * @brief load client from file
     *
     * @param fileDate
     */
    void loadClients(std::ifstream &fileDate);
    /**
     * @brief show all clients
     *
     */
    void showClients();
    /**
     * @brief load postman from file
     *
     * @param fileDate
     */
    void loadPostmans(std::ifstream &fileDate);
    /**
     * @brief show all postmans
     *
     */
    void showPostmans();
    /**
     * @brief load letter from file
     *
     * @param fileDate
     */
    void loadLetter(std::ifstream &fileDate);
    /**
     * @brief load parcel from file
     *
     * @param fileDate
     */
    void loadParcel(std::ifstream &fileDate);
    /**
     * @brief sort all packege in postaloffice
     *
     */
    void sortPackage();
    /**
     * @brief load all date from file
     *
     * @param filename
     */
    void loadDate(std::string filename);
    /**
     * @brief Get the Number Of Clients object
     *
     * @return int number of clients
     */
    int getNumberOfClients();
    /**
     * @brief Get the Number Of Postmans object
     *
     * @return int number of clients
     */
    int getNumberOfPostmans();
    /**
     * @brief Get the Package In Stock object
     *
     * @return int number package on postaloffice
     */
    int getPackageInStock();
};