//
// Created by Kemba Konteh on 3/5/20.
//

#include "Customer.h"

//------------------------------------------------ constructor() ---------------------------------------------------------
/*
 * Constructor to initialize the id, first and last name all of customer
 * */
//----------------------------------------------------------------------------------------------------------------------
Customer::Customer(int id, string first, string last)
{
    this->id = id;
    this->first = first;
    this->last = last;
}

//--------------------------------------------------- getFirstName() -----------------------------------------------------
/* Method to retrieve the first name of the customer
 * return first the first name of the customer
 * */
//----------------------------------------------------------------------------------------------------------------------
string Customer::getFirstName() const
{
    return first;
}

//------------------------------------------------ getLastName() -------------------------------------------------------
/*
 * Method to retrieve the last name of the customer
 * return last the last name of the customer
 * */
//---------------------------------------------------------------------------------------------------------------------
string Customer::getLastName() const
{
    return last;
}

//-------------------------------------------------- getCustomerId() ---------------------------------------------------
/*
 * Retrieves the customer id
 * return id the customer id
 * */
//----------------------------------------------------------------------------------------------------------------------
int Customer::getCustomerId() const
{
    return id;
}

//------------------------------------------------- addTransaction() --------------------------------------------------
/* Method to add the transaction in profile.Method makes use of victor
 * parameter: t the transaction to be added of type Transaction
 */
//---------------------------------------------------------------------------------------------------------------------
void Customer::addTransaction(const Transaction * t)
{
    transactions.push_back(t->to_string());
}

//------------------------------------------------------ printTransaction() --------------------------------------------
/* Method to print out all the transactions done by customer
 *
 * */
void Customer::printTransactions() const
{
    for (string t : transactions) {
        cout << t << endl;
    }
    if (transactions.size() == 0) {
        cout << "No transactions available." << endl;
    }
    cout << endl;
}

//--------------------------------------------------- operator<<() ----------------------------------------------------
/* Method to print the customer profile. This is an overloaded operator<<()
 * */
//---------------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream &out, const Customer &c) {
    out << c.getCustomerId() << " | " << c.getFirstName() << " | "
        << c.getLastName();
    return out;
}
