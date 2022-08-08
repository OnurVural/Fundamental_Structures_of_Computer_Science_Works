//ONUR VURAL - CS201 SEC1 - 21902330
#include "SimpleStudent.h"

Student::Student()
{
    name = "";
    id = 0;
}

Student::Student(string n, int i)
{
    name = n;
    id = i;
}

Student& Student::operator=(const Student& s){
   name = s.name;
   id = s.id;
}
string Student::getName(){
   return name;
}

int Student::getId(){
   return id;
}
void Student::setName(string n){
    name = n;
}

void Student::setId(int i){
    id = i;
}
