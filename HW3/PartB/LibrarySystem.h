//ONUR VURAL - CS201 SEC1 - 21902330
#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H
#include "Student.h"
#include "Book.h"
#include <string>
#include <cstddef>
#include <iostream>
using namespace std;

class LibrarySystem {
    public:
        LibrarySystem();
        ~LibrarySystem();
        void addBook(const int bookId, const string bookName, const int bookYear);
        void deleteBook(const int bookId);

        void addStudent(const int studentId, const string studentName);
        void deleteStudent(const int studentId);

        void checkoutBook(const int bookId, const int studentId);
        void returnBook(const int bookId);

        void showAllBooks() const;
        void showBook(const int bookId) const;
        void showStudent(const int studentId) const;


        bool isEmpty() const;
        bool checkUniqueStudent(const int studentId) const;
        bool checkUniqueBook(const int bookId) const;
        bool checkedOutDelete(const int bookId);
        void addBookHelper(const int bookId, const string bookName, const int bookYear);


    private:
        struct StudentNode{
            Student s; // a data item on the list
            StudentNode *next;
    };

    int studentSize; //size of the students
    StudentNode *head; //pointer to the linked list

    struct BookNode{
            Book b; // a data item on the list
            BookNode *next;
    };

    int bookSize; //size of the books
    BookNode *headB; //pointer to the linked list
};
#endif // LIBRARYSYSTEM_H
