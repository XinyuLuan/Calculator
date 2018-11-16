#ifndef STACKJW
#define STACKJW
//#include <iostream>
//#include <cstdlib>
//#include <fstream>
//#include <string>
//#include <sstream>
#include "linkedlistjw.h"
#include "nodejw.h"
#include "token.h"

using std::ostream;
using std::istream;
using std::endl;

enum STACK_ERRORS_LINK_JW {STACK_EMPTY_LINK_JW, STACK_FULL_LINK_JW, INVALID_MAXSIZE_LINK_JW};
template<typename T>
class stackJW:public linkedlist_jw
{
    public:
        stackJW(unsigned int maxSize =  10);
        ~stackJW();
        stackJW(const stackJW<T> &other);
        stackJW<T>& operator=(const stackJW<T> &other);

        unsigned int size();
        unsigned int max_size();

        void clear();
        void resize(unsigned int newSize);

        void push(const T &data);
        T pop();
        T top();
        T operator[](const size_t index);//done
        stackJW<T>& operator<<(const T &data); //Chainable push
        stackJW<T>& operator>>(T &data); // Chainable pop
        void print();

        template<typename R>
        friend
        ostream& operator<<(ostream& out, const stackJW<R> &s);

        template<typename R>
        friend
        istream& operator>>(istream& in, stackJW<R> &s);

    private:
        void copy(const stackJW
                  <T> &other);
        void nukem();

};
template<typename T>
T stackJW<T>::operator[](const size_t index){
  unsigned int i = 0;
  if(index>qty-1)
      throw STACK_EMPTY_LINK_JW;
  for(baseNodeJW * ptr = tail;ptr && ptr!=head && i<=index; ptr = ptr->prevNode(), i++);
  T data = *(T*)tail->prevNode()->getValue();
  return data;
}
template<typename T>
void stackJW<T>::print(){
  for(baseNodeJW * ptr = head; ptr && ptr!=tail; ptr = ptr->nextNode()){
      std::cout<<*(T*)ptr->getValue();
  }
}
template<>
void stackJW<Token *>::print(){
    for(baseNodeJW * ptr = head;ptr && ptr!=tail; ptr = ptr->nextNode()){
        std::cout<<*(*(Token **)ptr->getValue());
    }
}


template<typename T>
stackJW<T>::stackJW(unsigned int maxSize)
{
    if(maxSize < 2)
        throw INVALID_MAXSIZE_LINK_JW;
    qty = 0;
    maxQty= maxSize;
}

template<typename T>
stackJW<T>::~stackJW()
{
    nukem();
    maxQty = 0;
}

template<typename T>
stackJW<T>::stackJW(const stackJW<T> &other)
{
    copy(other);
}

template<typename T>
stackJW<T>& stackJW<T>::operator=(const stackJW<T> &other)
{
    if(this != &other)
    {
        nukem();
        copy(other);
    }
    return *this;
}


template<typename T>
unsigned int stackJW<T>::size()
{
    return qty;
}

template<typename T>
unsigned int stackJW<T>::max_size()
{
    return maxQty;
}

template<typename T>
void stackJW<T>::clear()
{
    nukem();
}

template<typename T>
void stackJW<T>::resize(unsigned int newSize)
{
    nukem();
    if(newSize < 2)
        throw INVALID_MAXSIZE_LINK_JW;
    maxQty = newSize;
}

template<typename T>
void stackJW<T>::push(const T &data)
{
    //insert at the tail
    if(full())
        throw STACK_FULL_LINK_JW;
    baseNodeJW* whom = new nodeJW<T>(data);
    this->insert(whom);
}

template<typename T>
T stackJW<T>::pop()
{
  //delate at the tail;
  if(qty==0)
      throw STACK_EMPTY_LINK_JW;
  baseNodeJW *ptr = tail->prevNode();
  baseNodeJW *ptrP = ptr->prevNode();
  qty--;
  T data = *(T*)tail->prevNode()->getValue();
  if(qty==0){
//      head->nextNode() = tail;
//      tail->prevNode() = head;
       head = tail = NULL;
  }else{
      ptrP->nextNode() = tail;
      tail->prevNode() = ptrP;
  }

  delete ptr;
  return data;
}

template<typename T>
T stackJW<T>::top()
{
   if(!head)
      throw STACK_EMPTY_LINK_JW;
   return *(T*)(tail->prevNode())->getValue();
}


template<typename T>
stackJW<T>& stackJW<T>::operator<<(const T &data) //Chainable push
{
    push(data);
    return *this;
}

template<typename T>
stackJW<T>& stackJW<T>::operator>>(T &data) // Chainable pop
{
    data = pop();
    return *this;
}

template<typename T>
void stackJW<T>::copy(const stackJW<T> &other)
{
  baseNodeJW *ptr = other.head;
  for(; ptr; ptr = ptr->nextNode()){
      linkedlist_jw::insert(ptr);
  }
    qty = other.qty;
    maxQty = other.maxQty;
}

template<typename T>
void stackJW<T>::nukem()
{
    baseNodeJW *ptr;
    qty = 0;
    while(head)
    {
        ptr = head;
        head = head->nextNode();
        delete ptr;
    }
    head = tail = NULL;
}

template<typename R>
ostream& operator<<(ostream& out, const stackJW<R> &s)
{
    baseNodeJW *ptr = s.head;
    for(; ptr; ptr = ptr->nextNode())
        out<<*(R*)ptr->getValue()<<endl;
    return out;
}

template<typename R>
istream& operator>>(istream& in, stackJW<R> &s)
{
    nodeJW<R> newNode;
    while(in>>newNode)
        s<<newNode.getData();
    return in;
}
#endif // STACKJW

