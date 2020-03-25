//
// Created by Kemba Konteh on 3/5/20.
//

/*The movie class contains the implementation of the logic to modify and display a movie object. It is a base class
 * and it is inherited by the Comedy, Drama and Classics classes.
 *
 * For simplicity, the derived classes are all kept in this file
*/

#ifndef PROGRAM4_MOVIE_H
#define PROGRAM4_MOVIE_H

#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>

using namespace std;

class Movie
{
private:
    // to store number of copies available in stock
    int stock;

    // store director and title of movie
    string director, title;

public:
    // public constructor
    Movie(int stock, const string &director, const string &title);

    // virtual base destructor
    virtual ~Movie();

    // to be implemented by child classes
    virtual char getMovieCode() const = 0;

    // Constant getter methods
    int getStock() const;
    string getDirector() const;
    string getTitle() const;

    // to update stock
    void updateStock(int stock);

    // to order the movies
    bool operator<(const Movie &other);

    // To get the stirng representation of movie
    virtual string to_string() const;

    // Equality method to be overloaded in the child classes
    virtual bool is_equal(const Movie& other) const = 0;

    // Method to compare if two movie objects match
    friend bool operator==(const Movie &a, const Movie &b);
};

// Note: As stated above, i kept this class in here for simplicity
/***********************************************************************************************************************
					                              COMEDY CLASS
***********************************************************************************************************************/
class Comedy : public Movie {
private:
    int year;

public:
    // Constructors
    Comedy(int stock, const string &director, const string &title, int year);

    // destructor
    ~Comedy();

    // Get release year
    int getReleaseYear() const;

    // Overloaded method
    bool operator<(const Comedy &other);

    // get the movie code
    char getMovieCode() const;

    // string representation
    string to_string() const;

    // check for equality
    bool is_equal(const Movie& other) const;
};


/*************************************************************
					DRAMA CLASS
**************************************************************/
class Drama : public Movie {
private:
    int year;

public:
    // Constructors
    Drama(int stock, const string &director, const string &title, int year);

    // destructor
    ~Drama();

    // Getters
    int getReleaseYear() const;

    // Overloaded methods
    bool operator<(const Drama &other);
    char getMovieCode() const;
    string to_string() const;
    bool is_equal(const Movie& other) const;
};



/*************************************************************
					CLASSICS CLASS
**************************************************************/
class Classics : public Movie {
private:
    string majorActor;
    int month, year;

public:
    // Constructors
    Classics(int stock, const string &director, const string &title,
             const string &majorActor, int month, int year);

    // destructor
    ~Classics();

    // Getters
    int getReleaseYear() const;
    int getReleaseMonth() const;
    string getMajorActor() const;

    // Overloaded methods
    bool operator<(const Classics &other);
    char getMovieCode() const;
    string to_string() const;
    bool is_equal(const Movie& other) const;
};

#endif //PROGRAM4_MOVIE_H
