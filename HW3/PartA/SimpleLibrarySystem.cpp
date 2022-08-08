//ONUR VURAL - CS201 SEC1 - 21902330
#include "SimpleLibrarySystem.h"
#include <cstddef>
LibrarySystem::LibrarySystem(): studentSize(0), head(NULL){
}

LibrarySystem::~LibrarySystem(){
   StudentNode* next;
    while ( head ){
        next = head->next;
        delete head;
        head = next;
    }

} // end destructor


bool LibrarySystem::isEmpty() const{
   return studentSize == 0;
}

void LibrarySystem::addStudent(const int studentId, const string studentName){
    bool isUnique = checkUnique(studentId);

    if (isUnique && studentId > 0){
    studentSize++;
    StudentNode *newSN = new StudentNode;
    newSN->s.setId(studentId); newSN->s.setName(studentName);
    newSN->next = head;
    head = newSN;
    cout << "Student " << studentId << " has been added" << endl;

    }
    else if (studentId <= 0)
    {
        cout << "Warning! studentId must be unique positive integers..." << endl;
    }
    else{
        cout << "Student " << studentId << " already exists!" << endl;
    }
};
void LibrarySystem::deleteStudent(const int studentId){
    //empty list
    if ( head == NULL){
        cout << "Cannot delete from empty list! " << endl;
    }
    else{
       StudentNode *cur = head;
       StudentNode *prev = NULL;

       while ( cur != NULL){
          //found
          if ( cur->s.getId() == studentId){
             break;
          }
          else{
            prev = cur;
            cur = cur->next;
          }
       }

       //checked all items and not found
       if ( cur == NULL){
          cout << "Student with ID: " << studentId << " does not exist!" << endl;
       }
       else{
          //delete from head
          if (head == cur ){
            head = head->next;
          }
          //delete from beyond head
          else{
             prev->next = cur->next;
          }
          delete cur;
          studentSize--;
          cout << "Student " << studentId << " has been deleted " << endl;
       }


    }
};
void LibrarySystem::showStudent(const int studentId) const{
    if(checkUnique(studentId)){
       cout << "Student with ID: " << studentId << " does not exist in the system!" << endl;
    }
    else{
        StudentNode *cur = head;
        while (cur != NULL){
        if ( cur->s.getId() == studentId){
        cout << "Student ID: " << studentId << " -- Student Name: " << cur->s.getName() << endl;
        }
        cur = cur->next;
        }
    }
};
bool LibrarySystem::checkUnique(const int studentId) const{
  if (head == NULL)
    return true;

  StudentNode *cur = head;
  while (cur != NULL){
    if ( cur->s.getId() == studentId)
        return false;
    cur = cur->next;
  }

  return true;
}
