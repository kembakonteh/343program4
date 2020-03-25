//
// Created by Kemba Konteh on 3/5/20.
//

/*
* This class is designed on basis of Factory design pattern. It reads movie data and creates appropriate movie
*/
#include "MovieFactory.h"

//----------------------------------------------- createMovie() --------------------------------------------------------
/*
 * method to create the movie. It reads movie data and creates appropriate movie
 *
 * */
//----------------------------------------------------------------------------------------------------------------------
Movie * MovieFactory::createMovie(string line)
{
    // Break the line into tokens using comma as delimiter
    vector <string> csvTokens = Utility::parseTokenizedString(line, ',');

    // check if valid movie type
    string movieType = csvTokens[0];
    if (movieType != "F" &&
        movieType != "D" &&
        movieType != "C") {
        cout << "Invalid Movie type: " << movieType << endl;
        cout << "ignored: " << line << endl;
        return nullptr;
    }

    // check if sufficient data is present
    if (csvTokens.size() < 4) {
        cout << "Invalid data line for movie." << endl;
        return nullptr;
    }

    // find attributes
    int stock = atoi(csvTokens[1].c_str());
    string director = csvTokens[2];
    string title = csvTokens[3];

    if (movieType == "F") {
        return new Comedy(stock, director, title, atoi(csvTokens[4].c_str()));
    }
    else if (movieType == "D") {
        return new Drama(stock, director, title, atoi(csvTokens[4].c_str()));
    }
    else if (movieType == "C") {

        if (csvTokens.size() < 5) {
            cout << "Invalid data line for movie." << endl;
            return nullptr;
        }

        // Classics contain the major actor as well as month & year in
        // the last field(all has spaces in between)
        csvTokens = Utility::parseTokenizedString(csvTokens[4], ' ');

        if (csvTokens.size() < 4) {
            cout << "Invalid data line for movie." << endl;
            return nullptr;
        }

        return new Classics(stock, director, title,
                            csvTokens[0] + " " + csvTokens[1],
                            atoi(csvTokens[2].c_str()),
                            atoi(csvTokens[3].c_str()));
    }

    return nullptr;
}
