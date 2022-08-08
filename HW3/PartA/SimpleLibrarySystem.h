//ONUR VURAL - CS201 SEC1 - 21902330
#ifndef SIMPLELIBRARYSYSTEM_H
#define SIMPLELIBRARYSYSTEM_H
#include <string>
#include <cstddef>
#include "SimpleStudent.h"
#include <iostream>
using namespace std;

typedef Student ListItemType;


class LibrarySystem {
public:
    LibrarySystem();
    ~LibrarySystem();
    void addStudent(const int studentId, const string studentName);
    void deleteStudent(const int studentId);
    void showStudent(const int studentId) const;
    bool isEmpty() const;
    bool checkUnique(const int studentId) const;


private:
    struct StudentNode{
        Student s; // a data item on the list
        StudentNode *next;
    };

    int studentSize; //size of the students
    StudentNode *head; //pointer to the linked list
};

#endif // SIMPLELIBRARYSYSTEM_H
