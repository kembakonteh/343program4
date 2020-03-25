//
// Created by Kemba Konteh on 3/5/20.
//

/*
* The Utils class implements some general helper methods for string formatting
*/
#include "Utility.h"

//------------------------------------------------------------ trimString() --------------------------------------------
/*helper method to trim leading and trailing spaces in string
 * */
string Utility::trimString(string& s)
{
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);
    return s;
}

//---------------------------------------- parseTokenizedString() ------------------------------------------------------
/* Method to create the tokens from string using a delimiter
 *
 * */
//----------------------------------------------------------------------------------------------------------------------
vector<string> Utility::parseTokenizedString(string line, char delimiter) {
    vector<string> tokens;
    size_t pos = 0;
    std::string token;
    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        tokens.push_back(trimString(token));
        line.erase(0, pos + 1);
    }
    if (!line.empty()) {
        tokens.push_back(trimString(line));
    }
    return tokens;
}
