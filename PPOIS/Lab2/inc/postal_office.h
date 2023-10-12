#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "customer.h"
#include "sorter.h"
#include "deliveryman.h"
#include "letter.h"
#include "parcel.h"
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