//
// Created by Kemba Konteh on 3/5/20.
//

/*
* The Utils class implements some general helper methods for string formatting
*/
#ifndef PROGRAM4_UTILITY_H
#define PROGRAM4_UTILITY_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Utility
{
public:
    // to trim leading and trailing spaces in string
    static string trimString(string& s);

    // to create the tokens from string using a delimiter
    static vector<string> parseTokenizedString(string line, char delimiter);

};


#endif //PROGRAM4_UTILITY_H
