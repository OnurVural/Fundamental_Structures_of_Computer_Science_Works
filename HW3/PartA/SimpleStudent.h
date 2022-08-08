//ONUR VURAL - CS201 SEC1 - 21902330
#ifndef SIMPLESTUDENT_H
#define SIMPLESTUDENT_H
#include <string>
#include <iostream>
using namespace std;

class Student
{
    public:
        Student();
        Student(string n, int i);
        Student& operator=(const Student& s);
        string getName();
        int getId();
        void setName(string n);
        void setId(int i);

    private:
        string name;
        int id;
};

#endif // SIMPLESTUDENT_H
