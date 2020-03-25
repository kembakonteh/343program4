//
// Created by Kemba Konteh on 3/5/20.
//

/*
* The transaction class checks in/out movies, Show the history of a customer and shows the movie records present in the
* inventory.It is a base class and it is inherited by the Show, History, borrow and Return classes.
*
* For simplicity, the derived classes are all kept in this file
*/
#ifndef PROGRAM4_TRANSACTION_H
#define PROGRAM4_TRANSACTION_H

#include<iostream>
#include<string>
#include<vector>
#include "Inventory.h"
#include "Customer.h"
#include "Movie.h"

class Inventory;
class Customer;
class Movie;

using namespace std;

class Transaction
{
public:
    virtual void doTransaction() = 0;
    virtual string to_string() const = 0;
};


/***********************************************************************************************************************
                                    Show All the movies present in movie inventory
***********************************************************************************************************************/
class Show : public Transaction {
private:

    // inventory
    const Inventory * inventory;
public:

    Show(const Inventory *inventory);

    void doTransaction();

    string to_string() const;
};

/***********************************************************************************************************************
                                    Show All the transactions done by a customer
***********************************************************************************************************************/
class History : public Transaction {
private:
    //customer
    const Customer * customer;
public:
    History(const Customer* cust);

    void doTransaction();
    string to_string() const;
};

/***********************************************************************************************************************
                                                 Borrow a movie
***********************************************************************************************************************/
class Borrow : public Transaction {
private:
    Customer * customer;
    Movie * movie;
    Inventory * inventory;

public:
    Borrow(Customer* cust, Inventory *inventory, Movie *movie);

    void doTransaction();
    string to_string() const;
};

/***********************************************************************************************************************
                                                     Return a movie
************************************************************************************************************************/
class Return : public Transaction {
private:
    Customer * customer;
    Movie * movie;
    Inventory * inventory;

public:
    Return(Customer* cust, Inventory *inventory, Movie *movie);

    void doTransaction();
    string to_string() const;
};


#endif //PROGRAM4_TRANSACTION_H
