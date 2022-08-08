//N.ONUR VURAL - 21902330 - CS201:SEC1
#include "SearchStack.h"

SearchStack::SearchStack()
{
    topOnStack = NULL;
}

SearchStack::SearchStack(const SearchStack& aStack){
    if(aStack.topOnStack == NULL)
        topOnStack == NULL;
    else{
        topOnStack = new SearchStackNode;
        topOnStack->item = aStack.topOnStack->item;

        SearchStackNode *nPntr = topOnStack;
        for (SearchStackNode *origPtr = aStack.topOnStack->next; origPtr != NULL; origPtr = origPtr->next){
                nPntr->next = new SearchStackNode;
                nPntr = nPntr->next;
                nPntr->item = origPtr->item;
        }
        nPntr->next = NULL;
    }
}

SearchStack::~SearchStack(){
    while (!isEmpty())
      pop();
}

bool SearchStack::isEmpty() const {
    if (topOnStack)
        return false;
    else
        return true;
}

bool SearchStack::push(StackItemType itemToAdd){
    SearchStackNode* newNode = new SearchStackNode;
    newNode->item = itemToAdd;
    newNode->next = topOnStack;
    topOnStack = newNode;
    return true;
}

bool SearchStack::pop(){
    if (!isEmpty()){
      SearchStackNode *tempNode = topOnStack;
      topOnStack = topOnStack->next;
      tempNode->next = NULL; //optional
      delete tempNode;
      return true;
    }
   else
    return false; //to indicate we could not delete
}
bool SearchStack::pop(StackItemType& top){
    if (!isEmpty()){
        top = topOnStack->item;
        pop();
        return true;
    }
    else
        return false;

}


 bool SearchStack::peek(StackItemType& top) const{
    if (!isEmpty()){
        top = topOnStack->item;
        return true;
    }
   // stack is not empty; retrieve top
   else
    return false;
 }

 StackItemType SearchStack::peek() const{
 if (!isEmpty()){
        return topOnStack->item;
}

 }
