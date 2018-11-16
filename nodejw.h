#ifndef NODEJW
#define NODEJW
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
#include "basenode_jw.h"

using std::cin;
using std::cout;
using std::ostream;
//testing
using std::istream;
using std::stringstream;
using std::string;

enum NODEJW_ERROR {NODE_VALUE_NOT_SET};

template <typename T>
class nodeJW:public baseNodeJW{

    public:
       //nodeJW();
       nodeJW(T input = T());
       nodeJW(const nodeJW &other);
       nodeJW& operator=(const baseNodeJW &other);
       ~nodeJW(){
         delete (T*)getValue();
       }
       bool operator<(const baseNodeJW &x) const;
       bool operator<=(const baseNodeJW &x) const;
       bool operator>(const baseNodeJW &x) const;
       bool operator>=(const baseNodeJW &x) const;
       bool operator==(const baseNodeJW &x) const;
       bool operator!=(const baseNodeJW &x) const;
       inline T getData(){
           return *(T*) getValue();
       }

       template <typename U>
       friend
       ostream& operator<<(ostream& out, const nodeJW<U> &theNode);

       template <typename U>
       friend
       istream& operator>>(istream& in, nodeJW<U> &theNode);

    protected:
       //string type;
    private:
       void copy(const baseNodeJW *other);
};

template <typename T>
nodeJW<T>::nodeJW(T input){
   setValue(new T(input));
};
template <typename T>
nodeJW<T>::nodeJW(const nodeJW<T> &other){
  copy(&other);
}

template <typename T>
void nodeJW<T>::copy(const baseNodeJW* other)
{
    *(T*)getValue() = *(T*)(other->getValue());
}

template <typename T>
nodeJW<T>& nodeJW<T>::operator=(const baseNodeJW &other){
    if(this!=&other)
       copy(&other);
    return *this;
}
template <typename T>
bool nodeJW<T>::operator<(const baseNodeJW &x) const{
    return *(T*)getValue()<*(T*)x.getValue();
}
template <typename T>
bool nodeJW<T>::operator<=(const baseNodeJW &x) const{
    return *(T*)getValue()<=*(T*)x.getValue();
}
template <typename T>
bool nodeJW<T>::operator>(const baseNodeJW &x) const{
    return *(T*)getValue()>*(T*)x.getValue();
}
template <typename T>
bool nodeJW<T>::operator>=(const baseNodeJW &x) const{
    return *(T*)getValue()>=*(T*)x.getValue();
}
template <typename T>
bool nodeJW<T>::operator==(const baseNodeJW &x) const{
    return *(T*)getValue()==*(T*)x.getValue();
}
template <typename T>
bool nodeJW<T>::operator!=(const baseNodeJW &x) const{
    return *(T*)getValue()!=*(T*)x.getValue();
}

template <typename U>
ostream& operator<<(ostream& out, const nodeJW<U> &theNode)
{

    if(&out == &cout)
       out<<"value: "<<theNode.getData();
    else{
        out<<"["<<theNode.getData()<<"]";
     }
      return out;
}

template <typename U>
istream& operator>>(istream& in, nodeJW<U> &theNode)
{
    if(&in == &cin)
    {
        string line;
        cout << "Value: ";
        getline (cin,line);
        stringstream  ss(line);

        ss >> *(U*)theNode.getValue();
        ss.str(std::string());
        ss.clear();
    }
    else
    {
        string line;
        getline(in,line,']');
        if(line.size()!=0){
              line.erase(0,1);
              line.erase(line.size(),1);
              stringstream ss;
              ss >> *(U*)theNode.getValue();
              ss.clear();
        }
    }
    return in;
};
#endif // NODEJW

