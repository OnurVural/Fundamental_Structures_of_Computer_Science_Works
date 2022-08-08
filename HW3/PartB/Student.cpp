//ONUR VURAL - CS201 SEC1 - 21902330
#include "Student.h"

Student::Student()
{
    name = "";
    id = 0;
    headB = NULL;
    bsize = 0;
}

Student::Student(const string n, const int i)
{
    name = n;
    id = i;
    headB = NULL;
    bsize = 0;
}

Student::~Student(){

BookNode* next;
    while ( headB ){
        next = headB->next;
        delete headB;
        headB = next;
    }
}

Student& Student::operator=(const Student& s){
   name = s.name;
   id = s.id;
   return *this;
}
string Student::getName(){
   return name;
}

int Student::getId(){
   return id;
}
void Student::setName(const string n){
    name = n;
}

void Student::setId(const int i){
    id = i;
}

void Student::getBook(const int bookId, const string bookName, const int bookYear){
    BookNode *newSN = new BookNode;
    newSN->b.setId(bookId); newSN->b.setTitle(bookName); newSN->b.setYear(bookYear);
    newSN->next = headB;
    headB = newSN;
    bsize++;
}
void Student::returnBook(const int bookId){

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

       if ( cur != NULL){
          //delete from head
          if (headB== cur ){
            headB = headB->next;
          }
          //delete from beyond head
          else{
             prev->next = cur->next;
          }
          delete cur;
          bsize--;
       }
    }
}
bool Student::hasBook(const int bookId){
if (headB == NULL)
    return false;

  BookNode * cur = headB;
  while (cur != NULL){
    if ( cur->b.getId() == bookId)
        return true;
    cur = cur->next;
  }
  return false;

}
Book Student::giveBook(const int bookId){
    if (headB != NULL){

    BookNode * cur = headB;
    while (cur != NULL){
        if ( cur->b.getId() == bookId)
            return cur->b;
        cur = cur->next;
    }

    }
}

void Student::showAll(){

if (headB != NULL){

    BookNode * cur = headB;
    while (cur != NULL){
        cout << cur->b.getId() << "/      " << cur->b.getTitle() << "/  " << cur->b.getYear() << "/ Checked out by student " << getId() << "  " << getName() << endl;
        cur = cur->next;
    }
}
}

void Student::showAll2(){

if (headB != NULL){

    BookNode * cur = headB;
    while (cur != NULL){
        cout << cur->b.getId() << "/      " << cur->b.getTitle() << "/  " << cur->b.getYear() << endl;
        cur = cur->next;
    }
}
}

bool Student::haveBooks(){
if ( bsize > 0 )
    return true;
return false;
}

Book Student::giveLast(){
BookNode* cur = headB;
while (cur != NULL)
{
    cur = cur->next;
    if(cur->next==NULL){
      return cur->b;
    }
}

}

Book Student::giveFirst(){
   if (headB != NULL)
    return headB->b;

}
int Student::getSize(){
    return bsize;
}

void Student::giveBookIndex(int index, Book& b){

if ( (index < 1) || (index > getSize()) )
      cout << "BIG PROBLEM" << endl;

   else{ // count from the beginning of the list
      BookNode *cur = headB;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      b = cur->b;
   }


}
