//ONUR VURAL - CS201 SEC1 - 21902330
#ifndef STUDENT_H
#define STUDENT_H
#include "Book.h"
#include <string>
#include <iostream>
using namespace std;

class Student
{
    public:
        Student();
        Student(const string n, const int i);
        ~Student();
        Student& operator=(const Student& s);
        string getName();
        int getId();
        void setName(const string n);
        void setId(const int i);

        //
        void getBook(const int bookId, const string bookName, const int bookYear);
        void returnBook(const int bookId);
        bool hasBook(const int bookId);
        Book giveBook(const int bookId);

        Book giveLast();
        Book giveFirst();
        void showAll();
        void showAll2();
        bool haveBooks();
        int getSize();

        void giveBookIndex(int index, Book& b);


    private:
        string name;
        int id;
        struct BookNode{
            Book b; // a data item on the list
            BookNode *next;
        };

        BookNode *headB; //pointer to the linked list
        int bsize;

   // Returns a pointer to the index-th node
   // in the linked list

};

#endif // STUDENT_H
