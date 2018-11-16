#ifndef QUEUE_LINK
#define QUEUE_LINK
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "linkedlistjw.h"
#include "nodejw.h"
#include "token.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ostream;
using std::istream;

enum LinkQ_ERRORS {EMPTY_LinkQ, FULL_LinkQ, INDEX_NOT_FOUND_LinkQ, INVALID_MAXSIZE_LINKQ};

template<typename D>
class LinkQueue:public linkedlist_jw
{
    public:       
        LinkQueue(size_t m = 10);
        ~LinkQueue();
        LinkQueue(const LinkQueue<D> &other);
        LinkQueue<D>& operator=(const LinkQueue<D> &other);
        void resize(size_t newSize = 10);
        void clear();
        void enqueue(const D& data);
        const D& peek() const;
        void dequeue(D& data);
        void print();
        void printAlg();
        string printAlgStr();
        LinkQueue<D>& operator>>(D &data);
        LinkQueue<D>& operator<<(const D& data);
        D& operator[](const size_t index);

        template<typename T>
        friend
        ostream& operator<<(ostream &out, const LinkQueue<T> &queue);


        template<typename T>
        friend
        istream& operator>>(istream &in, LinkQueue<T> &queue);

        friend
        istream& operator>>(istream &in, LinkQueue<string> &queue);

    private:
        void copy(const LinkQueue<D> &other);
        void nukem();
};

template<typename D>
void LinkQueue<D>::print(){
  baseNodeJW * ptr = head;
  for(;ptr && ptr!=tail; ptr = ptr->nextNode()){
      std::cout<<*(*(D*)ptr->getValue());
  }
}
template<>
void LinkQueue<Token *>::print(){
  std::cout<<"[";
  for(baseNodeJW * ptr = head;ptr && ptr!=tail; ptr = ptr->nextNode()){
      if(ptr==tail->prevNode())
        std::cout<<*(*(Token **)ptr->getValue());
      else
        std::cout<<*(*(Token **)ptr->getValue())<<" ";
  }
  std::cout<<"] = ";
}
template<>
string LinkQueue<Token *>::printAlgStr(){
  //change//

  string output="";
  if(this->qty!=0){
      output = "[";
      for(baseNodeJW * ptr = head;ptr && ptr!=tail; ptr = ptr->nextNode()){
          if(ptr==tail->prevNode())
            output+=(*(Token **)ptr->getValue())->getStr();
          else
            output+=(*(Token **)ptr->getValue())->getStr() + " ";
      }
      output += "] = ";
  }
  return output;
}

template<typename D>
D& LinkQueue<D>::operator[](const size_t index){
  size_t size = qty;
  if(index>size)
    throw INDEX_NOT_FOUND_LinkQ;
  baseNodeJW *ptr = head;

  for(unsigned int i=0; i<=index; ptr = ptr->nextNode());
  return *(D*)ptr->getValue();
}
template<typename D>
LinkQueue<D>& LinkQueue<D>::operator<<(const D& data)
{
    enqueue(data);
    return *this;
}
template<typename D>
LinkQueue<D>::LinkQueue(size_t m )
{
  if(m < 2)
      throw INVALID_MAXSIZE_LINKQ;
  qty = 0;
  maxQty= m;
}
template<typename D>
LinkQueue<D>::~LinkQueue()
{
    nukem();
}
template<typename D>
LinkQueue<D>::LinkQueue(const LinkQueue<D> &other)
{
    copy(other);
}
template<typename D>
void LinkQueue<D>::clear()
{
    nukem();
}
template<typename D>
LinkQueue<D>& LinkQueue<D>::operator=(const LinkQueue<D> &other)
{
    if(this != other)
    {
        nukem();
        copy(other);
    }
    return *this;
}

template<typename D>
void LinkQueue<D>::resize(size_t newSize)
{
     nukem();
     maxQty= newSize;
}
template<typename D>
const D& LinkQueue<D>::peek() const
{
    if(qty==0)
        throw EMPTY_LinkQ;
    return *(D*)head->getValue();
}
template<typename D>
void LinkQueue<D>::enqueue(const D& data)
{
  //insert at the tail
  if(full())
      throw FULL_LinkQ;
  baseNodeJW* whom = new nodeJW<D>(data);
  this->insert(whom);
}
template<typename D>
void LinkQueue<D>::dequeue(D& data)
{
   //delate head
    if(qty==0)
        throw EMPTY_LinkQ;
    --qty;
    baseNodeJW *bye = this->head;
    head = bye->nextNode();
    if(bye->nextNode()->nextNode())
        bye->nextNode()->nextNode()->prevNode() = head;
    if(qty==0){
        head->nextNode() = tail;
        tail->prevNode() = head;
        head = tail = NULL;
    }
    data = *(D*)bye->getValue();
    delete bye;
}
template<typename D>
LinkQueue<D>& LinkQueue<D>::operator>>(D &data)
{
    dequeue(data);
    return *this;
}
template<typename D>
void LinkQueue<D>::copy(const LinkQueue<D> &other)
{
    qty = other.qty;
    maxQty = other.maxQty;
    //problem...
    for(baseNodeJW *ptr = other.tail; ptr; ptr = ptr->prevNode()){
        enqueue(*(D*)ptr->getValue());
    }
}

template<typename D>
void LinkQueue<D>::nukem()
{
    for(baseNodeJW *ptr = head; ptr; ptr = head)
    {
        head = head->nextNode();
        delete ptr;
    }
    qty = 0;
    maxQty = 0;
    head = tail = NULL;
}

template<typename T>
ostream& operator<<(ostream &out, const LinkQueue<T> &queue)
{
    string eol(&out == &cout ? ", " : "\n");

    for(baseNodeJW *ptr = queue.head; queue.qty; ptr = ptr->nextNode()){
          out<<*(T*)ptr->getValue()<<eol;
    }

    if(&out == &cout)
        out<<"\b\b ";
    return out;

}

template<typename T>
istream& operator>>(istream &in, LinkQueue<T> &queue)
{
  string input;
  T inputOther;
  stringstream ss;
  if(&in == &cin){
      ss<<input;
      ss>>inputOther;
      ss.clear();
      ss.str(std::string());
      queue << inputOther;
  }else{
      while(in>>inputOther)
         queue << inputOther;
  }

}

istream& operator>>(istream &in, LinkQueue<string> &queue)
{
    string input;
    string inputOther;
    string data;
    stringstream ss;
    if(&in == &cin){
        while(getline(in,input)){
            queue.enqueue(input);
       }
   }else{

        while(std::getline(in, input))
        {
            input.erase(0, 1);
            input.erase(input.size() - 1, 1);
            ss << input;
            ss >> data;
            queue.enqueue(data);
            ss.str(std::string());
            ss.clear();
        }
   }
   return in;
}
#endif // QUEUE_LINK

