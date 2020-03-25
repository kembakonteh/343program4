//
// Created by Kemba Konteh on 3/5/20.
//

/*
* This class is designed on basis of Factory design pattern. It reads movie data and creates appropriate movie
*/

#ifndef PROGRAM4_MOVIEFACTORY_H
#define PROGRAM4_MOVIEFACTORY_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "Movie.h"
#include "Utility.h"

using namespace std;

class MovieFactory
{
public:
    static Movie* createMovie(string line);
};


#endif //PROGRAM4_MOVIEFACTORY_H
