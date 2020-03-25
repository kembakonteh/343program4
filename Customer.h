//
// Created by Kemba Konteh on 3/5/20.
//
/*
 * Customer checks out and checks in the movies. In customer profile i will store the transactions done by a customer.
*/
#ifndef PROGRAM4_CUSTOMER_H
#define PROGRAM4_CUSTOMER_H

#include<iostream>
#include<string>
#include<vector>
#include "Transaction.h"

// forward declaration
class Transaction;

using namespace std;

class Customer {
private:
    int id;
    string first, last;

    vector<string> transactions;
public:

    // constructor
    Customer(int id, string first, string last);

    // getters
    string getFirstName() const;
    string getLastName() const;
    int getCustomerId() const;

    // add a transaction done by this customer
    void addTransaction(const Transaction * t);

    // print the transaction history done by this customer
    void printTransactions() const;

    // output Customer details
    friend ostream& operator<<(ostream &out, const Customer &c);
};


#endif //PROGRAM4_CUSTOMER_H
