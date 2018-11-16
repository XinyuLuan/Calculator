#ifndef LINKEDLISTJW
#define LINKEDLISTJW
#include <cstdlib>
#include "basenode_jw.h"
#include <iostream>
//using namespace std;

enum LINKEDLIST_JW_ERROR {LINKEDLIST_JW_EMPTY, LINKEDLIST_JW_FULL, LINKEDLIST_JW_INVALID_MAXSIZE};

class linkedlist_jw{
  public:
      linkedlist_jw();
      virtual ~linkedlist_jw();
      bool empty();
      bool full();
      size_t size();
      size_t max_size();

  protected:
      baseNodeJW *head, *tail;
      size_t qty, maxQty;
      void insert(baseNodeJW *&whom);
      void insertFront(baseNodeJW *&whom);
  private:
};

linkedlist_jw::linkedlist_jw()
{
    head = new baseNodeJW;
    tail = new baseNodeJW;
    qty = 0;
    maxQty = 50;
}

linkedlist_jw::~linkedlist_jw()
{
    qty = 0;
    maxQty = 0;
}

bool linkedlist_jw::empty()
{
  return !qty;
}

bool linkedlist_jw::full()
{
  return !(maxQty - qty);
}

size_t linkedlist_jw::size()
{
  return qty;
}

size_t linkedlist_jw::max_size()
{
    return maxQty;
}

void linkedlist_jw::insert(baseNodeJW *&whom)
{
    //need to fix ....
    if(full())
        throw LINKEDLIST_JW_FULL;
    baseNodeJW *ptr = head;

    qty++;
    if(!ptr){
        head = new baseNodeJW;
        tail = new baseNodeJW;
        head = whom;
        whom->nextNode() = tail;
        tail->prevNode() = whom;
    }else{
        baseNodeJW *ptrToTail = tail->prevNode();
        whom->nextNode() = tail;
        whom->prevNode() = ptrToTail;
        ptrToTail->nextNode() = whom;
        tail->prevNode() = whom;
    }
}

void linkedlist_jw::insertFront(baseNodeJW *&whom){
    baseNodeJW *ptr = head;
    //baseNodeJW *ptrToTail = tail;
    if(full())
        throw LINKEDLIST_JW_FULL;
    qty++;
    if(!ptr->getValue()){
        head = whom;
        whom->nextNode() = tail;
        tail->prevNode() = whom;
    }else{
        whom->nextNode() = head;
        head->prevNode() = whom;
        head = whom;
    }
}


#endif // LINKEDLISTJW

