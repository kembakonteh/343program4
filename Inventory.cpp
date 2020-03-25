//
// Created by Kemba Konteh on 3/5/20.
//

#include "Inventory.h"

//------------------------------------------------ findMovie() ---------------------------------------------------------
/* method to find the movies in inventory. The movie may have incomplete data only sufficient to search the movie in
 * inventory. So, we return the movie reference from the vector directly
 */
//----------------------------------------------------------------------------------------------------------------------
Movie * Inventory::findMovie(Movie * movie)
{
    for (Movie *m : movies) {
        if (*m == *movie) {
            return m;
        }
    }
    return nullptr;
}

//------------------------------------------------------- destructor() -------------------------------------------------
/*
 * To delete all the movie objects created
 * */
//----------------------------------------------------------------------------------------------------------------------
Inventory::~Inventory()
{
    // delete all the movie objects created
    for (Movie *m : movies) {
        delete m;
    }
}

//-------------------------------------------------------- loadInventory() ---------------------------------------------
/*
 * Method to load the movie inventory from a file
 * parameter: fileName the file name
 * */
//----------------------------------------------------------------------------------------------------------------------
void Inventory::loadInventory(string fileName)
{
    cout << "Loading Movie inventory from " << fileName << endl;

    // open file for reading
    ifstream inFile(fileName);
    if (inFile.fail()) {
        cout << "Unable to find file: " << fileName << endl;
        return;
    }

    string s, token;
    // keep reading lines until the end of file is reached
    while (getline(inFile, s)) {

        if (s.empty()) {
            break;
        }

        // Create the movie using movie factory
        Movie *m = MovieFactory::createMovie(s);
        if (m != nullptr) {
            movies.push_back(m);
            checkedoutCopies.insert(make_pair(m, vector<Customer*>())); // no copies checkout yet
        }
    }

    // sort the movies vector as per their sorting order
    sort(movies.begin(), movies.end(), [](Movie* a, Movie* b) { return *a < *b; });
}

//----------------------------------------------------- printInventory() -----------------------------------------------
/*
 * Method to print the inventory currently present.
 * */
//----------------------------------------------------------------------------------------------------------------------
void Inventory::printInventory() const
{
    // prints header
    cout << setfill('-') << setw(105) << "" << endl;

    cout << setfill(' ');
    cout << setw(31) << left << "Title" << " | ";
    cout << setw(6) << left << "Stock" << " | ";
    cout << setw(20) << left << "Director" << " | ";
    cout << setw(4) << left << "Code" << " | ";
    cout << setw(30) << left << "Comments" << " | " << endl;
    cout << setfill('-') << setw(105) << "" << endl;

    // print all the lines, one at a time
    for (Movie *m : movies) {
        cout << m->to_string() << endl;
    }

    // footer
    cout << setfill('-') << setw(105) << "" << endl << endl;
}

//------------------------------------------------------- checkoutMovie() ---------------------------------------------
/*
 * This method checks if it is possible to checkout a movie. For any errors, it prints the error message and returns
 * false.
 * parameter: movie the movie
 * parameter: customer the customer
 * */
//---------------------------------------------------------------------------------------------------------------------
bool Inventory::checkoutMovie(Movie * movie, Customer* customer)
{
    // find movie in inventory
    Movie *invMovie = findMovie(movie);
    if (invMovie == nullptr) {
        cout << "Checkout: unable to find the movie in inventory." << endl << endl;
        return false;
    }

    // Check if any copies of movie are available
    if (invMovie->getStock() == 0) {
        cout << "Checkout: no copies available for movie " << movie->getTitle() << endl << endl;
        return false;
    }

    // everything was successful.
    checkedoutCopies[invMovie].push_back(customer);
    invMovie->updateStock(invMovie->getStock() - 1);

    return true;
}

//------------------------------------------------- checkinMovie() -----------------------------------------------------
/*
 * This method checks if it is possible to checkin a movie. For any errors, it prints the error message and returns false.
 * parameter: movie the movie
 * parameter: customer the customer
 * */
//----------------------------------------------------------------------------------------------------------------------
bool Inventory::checkinMovie(Movie * movie, Customer* customer)
{
    // find movie in inventory
    Movie *invMovie = findMovie(movie);
    if (invMovie == nullptr) {
        cout << "Checkin: unable to find the movie in inventory." << endl << endl;
        return false;
    }

    // check if really this movie has been rented out
    int numCopies = checkedoutCopies[invMovie].size();
    if (numCopies == 0) {
        cout << "Checkin: no copies were checked out for movie " << movie->getTitle() << endl << endl;
        return false;
    }

    // Check if this customer has really borowed this movie
    vector<Customer *> custs = checkedoutCopies[invMovie];
    if (find(custs.begin(), custs.end(), customer) == custs.end()) {
        cout << "Checkin: no copies of given movie were checkedout by customer." << endl << endl;
        return false;
    }

    // everything was successful, remove the customer
    custs.erase(remove(custs.begin(), custs.end(), customer), custs.end());
    invMovie->updateStock(invMovie->getStock() + 1);

    return true;
}
