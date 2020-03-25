//
// Created by Kemba Konteh on 3/5/20.
//

/*
 * Hashtable of customers. This class stores the customers in a hashtable. The collisions are handled using linear probing.
*/

#ifndef PROGRAM4_HASHTABLE_H
#define PROGRAM4_HASHTABLE_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "Customer.h"

class HashTable
{
private:
    // capacity of array
    int capacity;

    // current number of entries
    int numEntries;

    // data array
    Customer **customers;

    // private method to double the capacity of hashtable
    void resize();

public:
    // constructor
    HashTable();

    // destructor
    ~HashTable();

    // add a customer to table
    void addCustomer(Customer *c);

    // search a customer in table using customer id
    Customer* searchCustomer(int customerId);

    // free all the customer objects stored in hashtable
    void freeObjects();

    // get number of entries in table
    int getNumEntries();
};


#endif //PROGRAM4_HASHTABLE_H
