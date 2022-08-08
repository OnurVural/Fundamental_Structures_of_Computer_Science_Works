//ONUR VURAL - CS201 SEC1 - 21902330
#include "Book.h"

Book::Book()
{
    id = 0;
    title = "";
    year = 0;
}

Book::Book(const int i, const string t, const int y){
    id = i;
    title = t;
    year = y;
}

void Book::setId( const int i){
    id = i;
}
void Book::setTitle( const string t){
    title = t;
}
void Book::setYear( const int y){
    year = y;
}
int Book::getId(){
    return id;
}
string Book::getTitle(){
    return title;
}
int Book::getYear(){
    return year;
}

Book& Book::operator=(const Book& b){
     id = b.id;
     title = b.title;
     year = b.year;
     return *this;
}
