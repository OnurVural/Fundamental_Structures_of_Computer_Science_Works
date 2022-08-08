//ONUR VURAL - CS201 SEC1 - 21902330
#include "LibrarySystem.h"
#include <iostream>
#include <iomanip>
#include <cstddef>
LibrarySystem::LibrarySystem(): studentSize(0), head(NULL), bookSize(0), headB(NULL){
}

LibrarySystem::~LibrarySystem(){

    StudentNode* next;
    while ( head ){
        next = head->next;
        delete head;
        head = next;
    }

    BookNode* next2;
    while ( headB ){
        next2 = headB->next;
        delete headB;
        headB = next2;
    }
}


bool LibrarySystem::isEmpty() const{
   return studentSize == 0;
}

void LibrarySystem::addStudent(const int studentId, const string studentName){
    bool isUnique = checkUniqueStudent(studentId);

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
    Book temp;
    bool truth;
    int i = 0;
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


          while (cur->s.haveBooks())
          {

             temp = cur->s.giveFirst();
             cur->s.returnBook(cur->s.giveFirst().getId());

             addBookHelper(temp.getId(),temp.getTitle(),temp.getYear());
             cout << "Book " << temp.getId() << " has been returned" << endl;
          }

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
    if(checkUniqueStudent(studentId)){
       cout << "Student with ID: " << studentId << " does not exist in the system!" << endl;
    }
    else{
        StudentNode *cur = head;
        while (cur != NULL){
        if ( cur->s.getId() == studentId){
        cout << "Student ID: " << studentId << " -- Student Name: " << cur->s.getName() << endl;
        if (cur->s.haveBooks()){
        cout << "Student " << studentId << " has checked out the following books:" <<endl;
        cout << "Book id/   Book name/     Year " << endl;
        cur->s.showAll2();
        }
        else{
        cout <<"Student " << studentId << " has no books" << endl;
        }

        }
        cur = cur->next;
        }
    }
};
bool LibrarySystem::checkUniqueStudent(const int studentId) const{
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

bool LibrarySystem::checkUniqueBook(const int bookId) const{
  if (headB == NULL)
    return true;

  BookNode *cur = headB;
  while (cur != NULL){
    if ( cur->b.getId() == bookId)
        return false;
    cur = cur->next;
  }
  return true;
}

void LibrarySystem::addBook(const int bookId, const string bookName, const int bookYear){

    bool isUnique = checkUniqueBook(bookId);
    bool isUnique2 = true;

    if (head != NULL){
        StudentNode *cur = head;
        while (cur != NULL){
        if ( cur->s.hasBook(bookId))
            isUnique2 = false;
        cur = cur->next;
        }
    }

    if (isUnique && isUnique2 && bookId > 0){
    bookSize++;
    BookNode *newSN = new BookNode;
    newSN->b.setId(bookId); newSN->b.setTitle(bookName); newSN->b.setYear(bookYear);
    newSN->next = headB;
    headB = newSN;
    cout << "Book " << bookId << " has been added" << endl;

    }
    else if (bookId <= 0)
    {
        cout << "Warning! bookId must be unique positive integers..." << endl;
    }
    else{
        cout << "Book " << bookId << " already exists!" << endl;
    }

}

void LibrarySystem::checkoutBook(const int bookId, const int studentId){
    bool checkedByOther = false;
    string title;
    int year;

    if (head != NULL){
        StudentNode *cur = head;
        while (cur != NULL){
        if ( cur->s.hasBook(bookId))
           checkedByOther = true;
        cur = cur->next;
        }
        }
    if(checkUniqueBook(bookId)&& !checkedByOther){
        cout << "Book with ID: " << bookId << " does not exist for checkout" << endl;
    }
    else if(checkUniqueStudent(studentId)){
       cout << "Student with ID: " << studentId << " does not exist for checkout" << endl;
    }
    else {

        if (checkedByOther){
                cout << "Book " <<  bookId << " has been already checked out by another student " << endl;
        }
        else{
                if (headB != NULL){
                BookNode *cur = headB;
                while (cur != NULL){
                    if (cur->b.getId()== bookId){
                        title = cur->b.getTitle(); year = cur->b.getYear();
                         if ( headB!= NULL){
                        BookNode *cur = headB;
                        BookNode *prev = NULL;

                        while ( cur != NULL){
                        //found
                        if ( cur->b.getId() == bookId){
                        break;
                        }
                        else{
                        prev = cur;
                        cur = cur->next;
                        }
                        }

                        //checked all items and not found
                        if ( cur != NULL){
                        //delete from head
                        if (headB== cur ){
                        headB= headB->next;
                        }
                        //delete from beyond head
                        else{
                        prev->next = cur->next;
                        }
                        delete cur;
                        }
                        }
                         break;
                }
                cur = cur->next;
                    }
                }
                if (head != NULL){
                    StudentNode *cur = head;
                    while (cur != NULL){
                    if ( cur->s.getId() == studentId)
                        cur->s.getBook(bookId, title, year);
                    cur = cur->next;
                    }
                }
           cout << "Book " << bookId << " has been checked out by student " <<  studentId << endl;
        }
    }
}
void LibrarySystem::returnBook(const int bookId){
    bool checkedOut = false;
    bool exists = false;
    Book temp;

    if (headB != NULL){
        BookNode *cur = headB;
        while (cur != NULL){
        if ( cur->b.getId()== bookId){
            exists = true;
            break;
        }
        cur = cur->next;
        }
    }

    if (head != NULL){
        StudentNode *cur = head;
        while (cur != NULL){
        if ( cur->s.hasBook(bookId)==true){
            checkedOut = true;
            break;
        }
        cur = cur->next;
        }
    }

    if (!checkedOut && !exists){
       cout << "Book " << bookId << " does not exist in the system" << endl;
    }
    else if (!checkedOut && exists){
       cout << "Book " << bookId << " has not been checked out" << endl;
    }
    else if (checkedOut){
    if (head != NULL){
        StudentNode *cur = head;
        while (cur != NULL){
        if ( cur->s.hasBook(bookId)==true){
            temp = cur->s.giveBook(bookId);
            cur->s.returnBook(bookId);
            break;
        }
        cur = cur->next;
        }
    }

    addBookHelper(temp.getId(),temp.getTitle(),temp.getYear());
    cout << "Book " << bookId << " has been returned" << endl;
    }
}

void LibrarySystem::showAllBooks() const{

  if (headB == NULL && head == NULL){
    cout << "No books in the system" << endl;
    return;
  }

  cout << "Book id/   Book name/    Year/    Status" << endl;
  if (headB != NULL){
     BookNode *cur = headB;
     while (cur != NULL){
        showBook(cur->b.getId());
        cur = cur->next;
     }
  }
  if (head != NULL){
     StudentNode *cur = head;
     while (cur != NULL){
        cur->s.showAll();
        cur = cur->next;
     }
  }
}

void LibrarySystem::showBook(const int bookId) const{
    bool notChecked = false;
    bool checked = false;
    Book temp;
    int id, year;
    int stuId;
    string stuName;
    string title;

    if (headB != NULL){
        BookNode *cur = headB;
        while (cur != NULL){
        if ( cur->b.getId() == bookId){
           id = cur->b.getId(); title = cur->b.getTitle(); year = cur->b.getYear();
           notChecked = true;
           break;
        }
        cur = cur->next;
        }
    }

    if (head != NULL){
        StudentNode *cur = head;
        while (cur != NULL){
        if ( cur->s.hasBook(bookId)){
           stuId = cur->s.getId(); stuName = cur->s.getName();
           temp = cur->s.giveBook(bookId);
           checked = true;
           break;
        }
        cur = cur->next;
        }
    }

    if (notChecked){
           cout << bookId << "/      " << title << "/  " << year << "/ Not checked out " << endl;
    }
    else if (checked){

        cout << bookId << "/      " << temp.getTitle() << "/  " << temp.getYear() << "/ Checked out by student " << stuId << "  " << stuName << endl;
    }
    else{
       cout << "Book " << bookId << " does not exist in system" << endl;
    }

}


void LibrarySystem::deleteBook(const int bookId){
bool deleted = false;
bool flag1 = false;
bool flag2 = false;
Book temp;
//if finds among not checked out directly delete it
if(checkedOutDelete(bookId)){
        deleted = true;
        flag1 = true;
    }

    if (head != NULL){
        StudentNode *cur = head;
        while (cur != NULL){
        if ( cur->s.hasBook(bookId)){
           temp = cur->s.giveBook(bookId);
           cur->s.returnBook(bookId);
           cout << "Book " << bookId <<  " has been returned" << endl;

           bookSize--;
           deleted = true;
           break;
        }
        cur = cur->next;
        }
    }

    if (flag1){
        cout << "Book " << bookId <<  " has not been checked out" << endl;
    }
    if (!deleted){
        cout << "Could not find book " << bookId << " to delete..." << endl;
    }
    else
        cout << "Book " << bookId <<  " has been deleted" << endl;

}




bool LibrarySystem::checkedOutDelete(const int bookId){
    if (headB == NULL)
        return false;
    else{
        BookNode * cur = headB;
        BookNode *prev = NULL;

        while (cur != NULL){
            if ( cur->b.getId() == bookId){
                break;
            }
            else{
                prev = cur;
                cur = cur->next;
            }
        }

        if ( cur == NULL){
            return false;
        }
        //found book among not checked out
        else{
           if (headB == cur) {
                headB = headB->next;

           }
           else{
            prev->next = cur->next;
           }
           delete cur;
           bookSize--;
           return true;
        }
    }
}



void LibrarySystem::addBookHelper(const int bookId, const string bookName, const int bookYear){

bool isUnique = checkUniqueBook(bookId);
    bool isUnique2 = true;

    if (head != NULL){
        StudentNode *cur = head;
        while (cur != NULL){
        if ( cur->s.hasBook(bookId))
            isUnique2 = false;
        cur = cur->next;
        }
    }

    if (isUnique && isUnique2 && bookId > 0){
    bookSize++;
    BookNode *newSN = new BookNode;
    newSN->b.setId(bookId); newSN->b.setTitle(bookName); newSN->b.setYear(bookYear);
    newSN->next = headB;
    headB = newSN;

    }
    else if (bookId <= 0)
    {
        cout << "Warning! bookId must be unique positive integers..." << endl;
    }
    else{
        cout << "Book " << bookId << " already exists!" << endl;
    }


}

