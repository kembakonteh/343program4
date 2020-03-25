//
// Created by Kemba Konteh on 3/5/20.
//
/*
 * Hashtable of customers. This class stores the customers in a hashtable. The collisions are handled using linear probing.
*/

#include "HashTable.h"

//---------------------------------------------------- resize() --------------------------------------------------------
/* Private method to double the capacity of hashtable
 *
 * */
//----------------------------------------------------------------------------------------------------------------------
void HashTable::resize()
{
    int oldCapacity = capacity;
    Customer **oldData = customers;

    // Now reset all current members.
    capacity = 2 * oldCapacity;
    numEntries = 0;
    customers = new Customer*[capacity];
    for (int i = 0; i < capacity; i++) {
        customers[i] = nullptr;
    }

    // copy data from old to new table
    for (int i = 0; i < oldCapacity; i++) {
        if (oldData[i] != nullptr) {
            addCustomer(oldData[i]);
        }
    }

    // delete old array
    delete[] oldData;
}

//-------------------------------------------------------- Constructor() ------------------------------------------------
/* Default constructor to initialize capacity, customer array, and numEntries
 * */
//---------------------------------------------------------------------------------------------------------------------
HashTable::HashTable()
{
    capacity = 10;
    customers = new Customer*[10];
    numEntries = 0;
    for (int i = 0; i < capacity; i++) {
        customers[i] = nullptr;
    }
}


//-------------------------------------------------------- Destructor() -----------------------------------------------
/*
 * Destructor to free customer object
 *
 * */
//----------------------------------------------------------------------------------------------------------------------
HashTable::~HashTable()
{
    delete[] customers;
}

//---------------------------------------------------- addCuctomer() --------------------------------------------------
/* Method adds a customer to table. It checks and doubles the capacity of the array if the load factor is more than 0.7
 * parameter: c customer to be added
 * */
//----------------------------------------------------------------------------------------------------------------------
void HashTable::addCustomer(Customer * c)
{
    // if load factor is more than 0.7
    if (numEntries > capacity * 0.7) {
        resize();
    }

    unsigned int location = c->getCustomerId() % capacity;

    // open addressing linear probing
    while (customers[location] != NULL) {
        location = (1 + location) % capacity;  // wrap-around if necessary
    }
    customers[location] = c;
    numEntries++;
}

//---------------------------------------------------- searchCustomer() ------------------------------------------------
/* Method to search a customer in table using customer id (search by customer id). returns null pointer if customer
 * not found
 * Parameter: customerId the customer id
 * */
//----------------------------------------------------------------------------------------------------------------------
Customer* HashTable::searchCustomer(int customerId)
{
    // find the location using customerId
    unsigned int location = customerId % capacity;

    // We keep probing linearly until we get desired customer
    // or a null entry, which means customer does not exist
    while (customers[location] != NULL) {
        if (customers[location]->getCustomerId() == customerId) {
            return customers[location];
        }
        location = (1 + location) % capacity;  // wrap-around if necessary
    }

    // customer not found
    return nullptr;
}

//----------------------------------------------------------- freeObjects() --------------------------------------------
/* Method frees all the customer objects stored in hashtable
 *
 * */
//----------------------------------------------------------------------------------------------------------------------
void HashTable::freeObjects()
{
    for (int i = 0; i < capacity; i++) {
        if (customers[i] != nullptr) {
            delete customers[i];
        }
    }
}

//-------------------------------------------------------- getNumEntries() ---------------------------------------------
/* Method gets number of entries in table
 * */
//----------------------------------------------------------------------------------------------------------------------
int HashTable::getNumEntries()
{
    return numEntries;
}
