//
// Created by Kemba Konteh on 3/5/20.
//

/*
* The Business class keeps track of movie inventory, Customers and the transactions done by the customers.
*/
#ifndef PROGRAM4_BUSINESS_H
#define PROGRAM4_BUSINESS_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "Inventory.h"
#include "HashTable.h"

using namespace std;


class Business
{
private:
    // inventory object to store the movies
    Inventory movieInventory;

    // Customer HashTable by Customer Id.
    HashTable customers;

    // private function to load the customers in hashtable
    void loadCustomers(string customersFile);

public:
    // constructor
    Business(string moviesFile, string customersFile);

    // Destructor
    ~Business();

    // to process the transaction files
    void processTransaction(string txnFile);
};

#endif //PROGRAM4_BUSINESS_H
