//
// Created by Kemba Konteh on 3/5/20.
//

/*
* The transaction class checks in/out movies, Show the history of a customer and shows the movie records present in the
* inventory.It is a base class and it is inherited by the Show, History, borrow and Return classes.
*
* For simplicity, the derived classes are all kept in this file
*/

#include "Transaction.h"


/***********************************************************************************************************************
			                                 SHOW INVENTORY TRANSACTION
************************************************************************************************************************/

//--------------------------------------------- show() ----------------------------------------------------------------
/*
 * shows all the movies present in the movie inventory
 *
 * */
//---------------------------------------------------------------------------------------------------------------------
Show::Show(const Inventory * inventory)
{
    this->inventory = inventory;
}

//-------------------------------------------------------- doTransaction() --------------------------------------------
/*
 * prints the inventory
 * */
//---------------------------------------------------------------------------------------------------------------------
void Show::doTransaction()
{
    cout << endl << "Printing inventory:" << endl;
    inventory->printInventory();
}


//------------------------------------------------------- to_string() --------------------------------------------------
/*
 * to get the string representation
 * */
//----------------------------------------------------------------------------------------------------------------------
string Show::to_string() const
{
    return "ShowInventory";
}


/***********************************************************************************************************************
			                                SHOW CUSTOMER HISTORY
************************************************************************************************************************/
//----------------------------------------------- constructor ----------------------------------------------------------
/*
 * shows all transactions done by a customer
 * */
//----------------------------------------------------------------------------------------------------------------------
History::History(const Customer * cust)
{
    cout << "Transaction history for customer " << cust->getFirstName() << " "
         << cust->getLastName() << ":" << endl;
    customer = cust;
}

//-------------------------------------------- doTransaction() ---------------------------------------------------------
/*
 * prints customer transaction
 * */
//----------------------------------------------------------------------------------------------------------------------
void History::doTransaction()
{
    customer->printTransactions();
}

//------------------------------------------------- to_string() --------------------------------------------------------
/*
 * gets the string representation
 * */
//----------------------------------------------------------------------------------------------------------------------
string History::to_string() const
{
    return "Show History";
}


/***********************************************************************************************************************
			                               BORROW MOVIE TRANSACTION
************************************************************************************************************************/
//----------------------------------------------- constructor() --------------------------------------------------------
/*
 * the borrow movie transaction
 * */
//----------------------------------------------------------------------------------------------------------------------
Borrow::Borrow(Customer * cust, Inventory *inventory, Movie * movie)
{
    this->customer = cust;
    this->movie = movie;
    this->inventory = inventory;
}

//------------------------------------------------- doTransaction() ----------------------------------------------------
/*
 * method checks if a movie is being checked out by a customer and then adds the transaction for that customer
 * */
void Borrow::doTransaction()
{
    if (inventory->checkoutMovie(movie, customer)) {
        customer->addTransaction(this);
    }
}

//----------------------------------------------------- to_string() ----------------------------------------------------
/*
 * to get the string representation
 * */
//----------------------------------------------------------------------------------------------------------------------
string Borrow::to_string() const
{
    return movie->getTitle() + " borrowed by " + customer->getFirstName()
           + " " + customer->getLastName();
}


/***********************************************************************************************************************
			                                 RETURN MOVIE TRANSACTION
************************************************************************************************************************/
//-------------------------------------------------- constructor -------------------------------------------------------
/*
 * return movie transaction
 * */
Return::Return(Customer * cust, Inventory *inventory, Movie * movie)
{
    this->customer = cust;
    this->movie = movie;
    this->inventory = inventory;
}

//--------------------------------------------- doTransaction() --------------------------------------------------------
/*
 * Method checks if movie is being checked in by a customer and adds the transaction for that customer
 * */
//----------------------------------------------------------------------------------------------------------------------
void Return::doTransaction()
{
    if (inventory->checkinMovie(movie, customer)) {
        customer->addTransaction(this);
    }
}

//--------------------------------------------------- to_string() ------------------------------------------------------
/*
 * to get the string representation
 * */
//----------------------------------------------------------------------------------------------------------------------
string Return::to_string() const
{
    return movie->getTitle() + " returned by " + customer->getFirstName()
           + " " + customer->getLastName();
}
