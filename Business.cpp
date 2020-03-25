//
// Created by Kemba Konteh on 3/5/20.
//

/*
* The Business class keeps track of movie inventory, Customers and the transactions done by the customers.
*/

#include "Business.h"


//------------------------------------------------------ LoadCustomer -------------------------------------------------
/* private function to load the customers in hashtable. Reads the file line by line till the end
 * Parameter: customerFile the file to be read
 */
//---------------------------------------------------------------------------------------------------------------------
void Business::loadCustomers(string customersFile)
{
    cout << endl;
    cout << "Loading Customers from " << customersFile << endl;

    // open file for reading
    ifstream inFile(customersFile);

    if (inFile.fail()) {
        cout << "Unable to find file: " << customersFile << endl;
        return;
    }

    int id;
    string first, last;

    // keep reading lines until the end of file is reached
    while (inFile >> id >> last >> first) {
        Customer *c = new Customer(id, first, last);
        customers.addCustomer(c);
    }
    cout << "Number of customers loaded: " << customers.getNumEntries() << endl;
    cout << endl;
}

//--------------------------------------------------------- Constructor -----------------------------------------------
/* Takes in movie and customer files and makes use of the
 * parameter: moviesFile the movie file to be read
 * parameter: customerFile the customer file to be read
 */
//---------------------------------------------------------------------------------------------------------------------
Business::Business(string moviesFile, string customersFile)
{
    movieInventory.loadInventory(moviesFile);
    loadCustomers(customersFile);
}

//---------------------------------------------------- Destructor -----------------------------------------------------
/*
 * The destrcutor to free the customer objects in the hash table
 * */
//---------------------------------------------------------------------------------------------------------------------
Business::~Business()
{
    // free the customer objects in the hashtable
    customers.freeObjects();

    // movie inventory will automatically be deleted on exit
}

//----------------------------------------------------- ProcessTransaction ---------------------------------------------
/*
 * Method to process the transaction files. This method shows transactions of a customer in chronological order
 * (latest to earliest) and specifies whether the movie was borrowed or returned. It also takes care of all Comedy movies,
 * then all Dramas, then all Classics. Each category of movies is ordered according to the sorting criteria as per the instruction.
 * parameter: txnFike the file to be processed
 * */
//----------------------------------------------------------------------------------------------------------------------
void Business::processTransaction(string txnFile)
{
    cout << "Processing transactions from " << txnFile << endl;

    // open input file for reading line by line
    ifstream inFile(txnFile);

    if (inFile.fail()) {
        cout << "Unable to find file: " << txnFile << endl << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {

        Transaction *transaction = nullptr;
        istringstream ss(line);

        string txnCode;
        ss >> txnCode;

        // check if valid transaction code
        if (txnCode != "B" && txnCode != "R" && txnCode != "I" && txnCode != "H") {
            cout << "invalid action code: " << txnCode << endl;
            cout << "Skipping line: " << line << endl << endl;
            continue;
        }

        if (txnCode == "I") {
            // No more arguments required for processing this command.
            transaction = new Show(&movieInventory);
        }
        else {

            int custId;
            ss >> custId;

            // Try to find the customer for transaction
            Customer *c = customers.searchCustomer(custId);
            if (c == nullptr) {
                cout << "Invalid customer id: " << custId << endl;
                cout << "Skipping line: " << line << endl << endl;
                continue;
            }

            // If history needs to be printed for customer
            if (txnCode == "H") {
                // Only customer Id needed.
                transaction = new History(c);

            }
            else {
                string mediaType;
                ss >> mediaType;

                // check the media type, only DVD supported
                if (mediaType != "D") {
                    cout << "Invalid media type: " << mediaType << endl;
                    cout << "Skipping line: " << line << endl << endl;
                    continue;
                }

                // validate the type of movie
                string movieType;
                ss >> movieType;
                if (movieType != "F" &&
                    movieType != "D" &&
                    movieType != "C") {
                    cout << "Invalid Movie type: " << movieType << endl;
                    cout << "Skipping line: " << line << endl << endl;
                    continue;
                }

                // Create the temporary object for appropriate movie
                // for purpose of search in inventory
                string movieLine;
                Movie *m = nullptr;

                if (movieType == "F") {
                    getline(ss, movieLine);
                    vector <string> csvTokens = Utility::parseTokenizedString(movieLine, ',');
                    m = new Comedy(0, "", csvTokens[0], atoi(csvTokens[1].c_str()));

                }
                else if (movieType == "D") {
                    getline(ss, movieLine);
                    vector <string> csvTokens = Utility::parseTokenizedString(movieLine, ',');
                    m = new Drama(0, csvTokens[0], csvTokens[1], 0);

                }
                else if (movieType == "C") {
                    int mo, yr;
                    string f, l;

                    ss >> mo >> yr >> f >> l;

                    vector <string> csvTokens = Utility::parseTokenizedString(ss.str(), ',');
                    m = new Classics(0, "", "",	f + " " + l, mo, yr);
                }

                // If we could not construct the movie
                if (m == nullptr) {
                    cout << "Invalid movie data: " << mediaType << endl;
                    cout << "Skipping line: " << line << endl << endl;
                    continue;
                }

                // If we could not find the movie in the inventory
                Movie *inventoryMovie = movieInventory.findMovie(m);
                if (inventoryMovie == nullptr) {
                    cout << "Unable to find movie line: " << line << endl << endl;
                    delete m;
                    continue;
                }

                if (txnCode == "B") {
                    transaction = new Borrow(c, &movieInventory, inventoryMovie);
                }
                else {
                    transaction = new Return(c, &movieInventory, inventoryMovie);
                }

                // delete the movie object created for temporary usage
                delete m;
            }
        }

        if (transaction != nullptr) {
            transaction->doTransaction();

            // delete the transaction.
            delete transaction;
        }
    }

}
