//ONUR VURAL - CS201 SEC1 - 21902330
#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <cstddef>
#include <iostream>
using namespace std;

class Book
{
    public:
    Book();
    Book(const int i, const string t, const int y);
    void setId( const int i);
    void setTitle( const string t);
    void setYear( const int y);

    int getId();
    string getTitle();
    int getYear();

    Book& operator=(const Book& b);

    private:
    int id;
    string title;
    int year;

};

#endif // BOOK_H
