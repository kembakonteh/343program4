//
// Created by Kemba Konteh on 3/5/20.
//

/* The inventory class keeps all the movies in sorted order. For each movie, it tracks how many copies and to which
 * customers the copies have been rented out to.
*/
#ifndef PROGRAM4_INVENTORY_H
#define PROGRAM4_INVENTORY_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include "Customer.h"
#include "Movie.h"
#include "MovieFactory.h"

// forward declaration
class Movie;

class Customer;

using namespace std;

class Inventory
{
private:
    // to store the movies present in inventory
    vector<Movie*> movies;

    // To store the List of customers to whom
    // the movie have been rented
    map<Movie*, vector<Customer*>> checkedoutCopies;

public:
    // Destructor
    ~Inventory();

    // to load the movie inventory from a file
    void loadInventory(string fileName);

    // To print the inventory currently present.
    void printInventory() const;

    // To find if a movie exists in the inventory
    Movie* findMovie(Movie *movie);

    /*
    * This method checks if it is possible to checkout a movie.
    * For any errors, it prints the error message and returns
    * false.
    */
    bool checkoutMovie(Movie *movie, Customer* customer);

    /*
    * This method checks if it is possible to checkin a movie.
    * For any errors, it prints the error messsage and returns
    * false.
    */
    bool checkinMovie(Movie *movie, Customer* customer);

};

#endif //PROGRAM4_INVENTORY_H
