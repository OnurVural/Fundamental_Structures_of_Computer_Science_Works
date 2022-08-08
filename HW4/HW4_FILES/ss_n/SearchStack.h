//N.ONUR VURAL - 21902330 - CS201:SEC1
#ifndef SEARCHSTACK_H
#define SEARCHSTACK_H
#include <iostream>
#include <string>
using namespace std;
typedef string StackItemType;


class SearchStack
{
    public:
        SearchStack();
        SearchStack(const SearchStack& aStack);
        ~SearchStack();
        bool isEmpty() const;
        bool push(StackItemType itemToAdd);
        bool pop();
        bool pop(StackItemType& top);
        bool peek(StackItemType& top) const;
        StackItemType peek() const;

    private:
    struct SearchStackNode {
      StackItemType item;        // the respective data
      SearchStackNode *next;        // pointing to the next node of stack
   };

   SearchStackNode *topOnStack;     // pointer to first node in the stack

};

#endif // SEARCHSTACK_H
