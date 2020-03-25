//
// Created by Kemba Konteh on 3/5/20.
//

/*The movie class contains the implementation of the logic to modify and display a movie object. It is a base class
 * and it is inherited by the Comedy, Drama and Classics classes. For simplicity, the derived classes are all kept in this file
 * Please see below and the bottom of file
*/

#include "Movie.h"
#include "Movie.h"

//-------------------------------------------- constructor() -----------------------------------------------------------
/*
 * initializes stock, director and title
 * */
//----------------------------------------------------------------------------------------------------------------------
Movie::Movie(int stock, const string &director, const string &title)
{
    this->stock = stock;
    this->director = director;
    this->title = title;
}

//----------------------------------------------------- destructor() ---------------------------------------------------
/*
 * to free any object created with "new"
 * */
Movie::~Movie() {

}

//------------------------------------------------------- getStock() --------------------------------------------------
/*
 * retrieves the stock
 * return stock
 * */
//----------------------------------------------------------------------------------------------------------------------
int Movie::getStock() const
{
    return stock;
}

//-------------------------------------------------------- getDirector() -----------------------------------------------
/*
 * retrieves the director
 * return director
 * */
//----------------------------------------------------------------------------------------------------------------------
string Movie::getDirector() const
{
    return director;
}

//-------------------------------------------------------- getTitle() --------------------------------------------------
/*
 * retrieves the title
 * return title
 * */
//----------------------------------------------------------------------------------------------------------------------
string Movie::getTitle() const
{
    return title;
}

//-------------------------------------------------------- updateStock() -----------------------------------------------
/*
 * updates the stock
 * parameter: stock the stock
 * */
//----------------------------------------------------------------------------------------------------------------------
void Movie::updateStock(int stock)
{
    this->stock = stock;
}

//------------------------------------------------------ operator<() --------------------------------------------------
/*
 * operator<() to order the movies
 * parameter other the movie to be ordered
 * */
//---------------------------------------------------------------------------------------------------------------------
bool Movie::operator<(const Movie & other)
{
    const Movie* rhs = &other;

    // If movie codes are same.
    if (getMovieCode() == rhs->getMovieCode()) {

        // Cast movies to there types and then call their base methods
        if (getMovieCode() == 'C') {
            Classics* clhs = static_cast<Classics*>(this);
            const Classics* crhs = static_cast<const Classics*>(rhs);
            return  (*clhs) < (*crhs);
        }
        else if (getMovieCode() == 'D') {
            Drama* dlhs = static_cast<Drama*>(this);
            const Drama* drhs = static_cast<const Drama*>(rhs);
            return  (*dlhs) < (*drhs);
        }
        else if (getMovieCode() == 'F') {
            Comedy* clhs = static_cast<Comedy*>(this);
            const Comedy* crhs = static_cast<const Comedy*>(rhs);
            return  (*clhs) < (*crhs);
        }
    }

    // Else, order F -> D -> C
    return getMovieCode() > rhs->getMovieCode();
}

//--------------------------------------------------------- to_string() -----------------------------------------------
/*
 * Method to get the string representation of movie
 * */
//----------------------------------------------------------------------------------------------------------------------
string Movie::to_string() const {
    stringstream out;
    out << setw(31) << left << getTitle() << " | ";
    out << setw(6) << left << getStock() << " | ";
    out << setw(20) << left << getDirector() << " | ";
    out << setw(4) << left << getMovieCode() << " | ";
    return out.str();
}

//-------------------------------------------------- operator==() ------------------------------------------------------
/*
 * Method to compare if two movie objects match
 * parameter: &a movie a
 * parameter: &b movie b
 * */
//---------------------------------------------------------------------------------------------------------------------
bool operator==(const Movie &a, const Movie &b) {
    // two movies are not equal if they are not of same type.
    if (a.getMovieCode() != b.getMovieCode())
        return false;

    return a.is_equal(b);
}



// Note: As stated above, i kept this derieved class here for the sake of simplicity
/***********************************************************************************************************************
				                               COMEDY CLASS
************************************************************************************************************************/

//---------------------------------------- constructor() ---------------------------------------------------------------
/*
 * comedy class inherits the movie
 * */
//----------------------------------------------------------------------------------------------------------------------
Comedy::Comedy(int stock, const string &director, const string &title, int year)
        : Movie(stock, director, title)
{
    this->year = year;
}

//-------------------------------------------------------- destructor() ------------------------------------------------
/*
 * to free the memory
 * */
//----------------------------------------------------------------------------------------------------------------------
Comedy::~Comedy() {

}

//--------------------------------------------------- getReaseYear() --------------------------------------------------
/*
 * Method to get movie release year
 * return year
 * */
//----------------------------------------------------------------------------------------------------------------------
int Comedy::getReleaseYear() const
{
    return year;
}

//-------------------------------------------------------- operator<() -------------------------------------------------
/*
 * To order movie by title and then year
 * parametr: other the movie
 * */
//----------------------------------------------------------------------------------------------------------------------
bool Comedy::operator<(const Comedy & other)
{
    // order by title, year
    if (Movie::getTitle() < other.getTitle()) {
        return true;
    }
    if (Movie::getTitle() > other.getTitle()) {
        return false;
    }
    return (year < other.year);
}

//-------------------------------------------------------- getMovieCode() ----------------------------------------------
/*
 * Method to get the movie code
 * return 'F' (comedy)
 * */
//----------------------------------------------------------------------------------------------------------------------
char Comedy::getMovieCode() const
{
    return 'F';
}

//--------------------------------------------------------- to_string() ------------------------------------------------
/*
 * To get the string representation
 * */
//---------------------------------------------------------------------------------------------------------------------
string Comedy::to_string() const {
    stringstream out;
    out << Movie::to_string();
    out << setw(30) << left << getReleaseYear() << " | ";
    return out.str();
}

//---------------------------------------------------------------------------------------------------------------------
/*
 * compares if two objects are equal
 * parameter: other the object
 * */
//----------------------------------------------------------------------------------------------------------------------
bool Comedy::is_equal(const Movie& other) const
{
    Comedy const&c = static_cast<Comedy const&>(other);
    return (getReleaseYear() == c.getReleaseYear()) &&
           (getTitle() == c.getTitle());
}


// Note: As stated above, i kept this derieved class here for the sake of simplicity
/***********************************************************************************************************************
					                                  DRAMA CLASS
************************************************************************************************************************/

//----------------------------------------------- constructor() --------------------------------------------------------
/*
 * Drama class inherit the Movie class
 * */
//----------------------------------------------------------------------------------------------------------------------
Drama::Drama(int stock, const string &director, const string &title, int year)
        : Movie(stock, director, title)
{
    this->year = year;
}

//------------------------------------------------------------- destructor() -------------------------------------------
/*
 * to frees the memory
 * */
Drama::~Drama() {

}

//------------------------------------------------------- getReleaseYear() ---------------------------------------------
/*
 * Method to get the release year
 * return year
 * */
//______________________________________________________________________________________________________________________
int Drama::getReleaseYear() const
{
    return year;
}

//------------------------------------------------------- operator<() --------------------------------------------------
/*
 * operator overloaded to order movie by director and then title
 * */
//---------------------------------------------------------------------------------------------------------------------
bool Drama::operator<(const Drama & other)
{
    // order by Director, title
    if (Movie::getDirector() < other.getDirector()) {
        return true;
    }
    if (Movie::getDirector() > other.getDirector()) {
        return false;
    }
    return (Movie::getTitle() < other.getTitle());
}

//--------------------------------------------------------- getMovieCode() ---------------------------------------------
/*
 * retrieves the movie code
 * return 'D' (Drama)
 * */
//---------------------------------------------------------------------------------------------------------------------
char Drama::getMovieCode() const
{
    return 'D';
}

//------------------------------------------------------- to_string() --------------------------------------------------
/*
 * To get the string representation
 * */
//----------------------------------------------------------------------------------------------------------------------
string Drama::to_string() const {
    stringstream out;
    out << Movie::to_string();
    out << setw(30) << left << getReleaseYear() << " | ";
    return out.str();
}

//------------------------------------------------------- is_equal() ---------------------------------------------------
/*
 * compares if two objects are equal
 * parameter: other the movie
 * */
//----------------------------------------------------------------------------------------------------------------------
bool Drama::is_equal(const Movie& other) const
{
    Drama const&d = static_cast<Drama const&>(other);

    return (getTitle() == d.getTitle()) &&
           (getDirector() == d.getDirector());
}


// Note: As stated above, i kept this derived class here for the sake of simplicity
/***********************************************************************************************************************
				                                    CLASSICS CLASS
************************************************************************************************************************/

//----------------------------------------------- constructor() -------------------------------------------------------
/*
 * classic class inherits the Movie class
 * */
//---------------------------------------------------------------------------------------------------------------------
Classics::Classics(int stock, const string &director, const string &title,
                   const string &majorActor, int month, int year)
        : Movie(stock, director, title)
{
    this->majorActor = "";
    this->month = month;
    this->year = year;
}

//--------------------------------------------------------- destructor() -----------------------------------------------
/*
 * to frees the memory
 * */
//---------------------------------------------------------------------------------------------------------------------
Classics::~Classics() {

}

//-------------------------------------------------------- getReleaseYear() --------------------------------------------
/*
 * method to get the release year
 * return year
 * */
//----------------------------------------------------------------------------------------------------------------------
int Classics::getReleaseYear() const
{
    return year;
}

//-------------------------------------------------------------- getReleaseMonth() -------------------------------------
/*
 * method to get the movie release month
 * return month
 * */
//----------------------------------------------------------------------------------------------------------------------
int Classics::getReleaseMonth() const
{
    return month;
}

//--------------------------------------------------- getMajorActor() --------------------------------------------------
/*
 * method to get the major actor
 * return majorActor
 * */
//----------------------------------------------------------------------------------------------------------------------
string Classics::getMajorActor() const
{
    return majorActor;
}

//-------------------------------------------------------- operator<() ------------------------------------------------
/*
 * overloaded method to order by date and major actor
 * parameter: other
 * */
//----------------------------------------------------------------------------------------------------------------------
bool Classics::operator<(const Classics & other)
{
    // order by Date, Major Actor
    if (year < other.year) {
        return true;
    }
    if (year > other.year) {
        return false;
    }
    if (month < other.month) {
        return true;
    }
    if (month > other.month) {
        return false;
    }
    return (majorActor < other.majorActor);
}

//--------------------------------------------------- getMovieCode() ---------------------------------------------------
/*
 * method to get movie code
 * return 'C' (classic)
 * */
//----------------------------------------------------------------------------------------------------------------------
char Classics::getMovieCode() const
{
    return 'C';
}

//---------------------------------------------------- to_string() -----------------------------------------------------
/*
 * to get the string representation
 * return the string representation
 * */
//----------------------------------------------------------------------------------------------------------------------
string Classics::to_string() const {
    stringstream out;
    out << Movie::to_string();

    string s = getMajorActor() + " " + std::to_string(getReleaseMonth()) + " "
               + std::to_string(getReleaseYear());
    out << setw(30) << left << s << " | ";

    return out.str();
}

//----------------------------------------------------- ie_eqaul() -----------------------------------------------------
/*
 * compares if two objects are equal
 * */
//----------------------------------------------------------------------------------------------------------------------
bool Classics::is_equal(const Movie& other) const
{
    Classics const&c = static_cast<Classics const&>(other);

    return (getReleaseYear() == c.getReleaseYear()) &&
           (getReleaseMonth() == c.getReleaseMonth()) &&
           (getMajorActor() == c.getMajorActor());
}
