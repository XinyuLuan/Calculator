#ifndef OPERATORS
#define OPERATORS

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <sstream>
#include <token.h>

using namespace std;
class Op;
typedef void (Op::*fptr6)(TOKEN_TYPE e, char input);
class Op: public Token{
public:
    Op(TOKEN_TYPE e, char input);
    ~Op();
    Op(const Op &other);
    Op& operator=(const Op &other);
    void setValue(TOKEN_TYPE e);
    int getP();
    char getAsso();
    friend
    bool operator==(const Op &x, const Op &y);

    friend
    bool operator!=(const Op &x, const Op &y);

    friend
    ostream& operator<<(ostream& out, const Op &op);

    friend
    istream& operator>>(istream& in, Op &op);

protected:

private:
    void copy(const Op& op);
    int precedence;
    char associativity;
    fptr6 output[128];

    void POWER(TOKEN_TYPE e, char input);
    void ADD(TOKEN_TYPE e, char input);
    void MIN(TOKEN_TYPE e, char input);
    void MULT(TOKEN_TYPE e, char input);
    void DIV(TOKEN_TYPE e, char input);

};
int Op::getP(){
  return precedence;
}

char Op::getAsso(){
  return associativity;
}

void Op::POWER(TOKEN_TYPE e, char input){
  str() = input;
  type() = e;
    precedence = 4;
    associativity = 'r';
}
void Op::ADD(TOKEN_TYPE e, char input){
  str() = input;
  type() = e;
  precedence = 2;
  associativity = 'l';
}
void Op::MIN(TOKEN_TYPE e, char input){
  str() = input;
  type() = e;
  precedence = 2;
  associativity = 'l';
}
void Op::MULT(TOKEN_TYPE e, char input){
  str() = input;
  type() = e;
  precedence = 3;
  associativity = 'l';
}
void Op::DIV(TOKEN_TYPE e, char input){
  str() = input;
  type() = e;
  precedence = 3;
  associativity = 'l';
}

Op::Op(TOKEN_TYPE e, char input){



      for(int i=0; i<128; ++i)
         Op::output[i] = NULL;
      output[static_cast<int>('+')] =  &Op::ADD;
      output[static_cast<int>('-')] =  &Op::MIN;
      output[static_cast<int>('/')] =  &Op::DIV;
      output[static_cast<int>('*')] =  &Op::MULT;
      output[static_cast<int>('^')] =  &Op::POWER;
      (this->*output[
          static_cast<int>(input)
          ]
      )(e, input);

}
Op::~Op(){
  //not sure
}
void Op::copy(const Op& other)
{
  //done
  str() = other.getStr();
  type() = other.getType();
}
bool operator==(const Op &x, const Op &y){
  return x.getStr() == y.getStr() && x.getType() == y.getType();
}
bool operator!=(const Op &x, const Op &y){
  return x.getStr() != y.getStr() && x.getType() != y.getType();
}
ostream& operator<<(ostream& out, const Op &op){
      if(&out == &cout)
         out<<"value: "<<op.getStr() <<", "<<op.getType()<<endl;
      else{
          out<<"["<<op.getStr() <<", "<<op.getType()<<"]";
       }
        return out;
}


istream& operator>>(istream& in, Op &op){
  if(&in == &cin)
     {
         std::string line;
         cout << "enter expression: ";
         getline (cin,line);
         stringstream  ss(line);

         ss>>op.str();
         ss.str(std::string());
         ss.clear();
         cout << "enter type #: ";
         getline(cin, line);
         ss<<line;
         ss>>op.type();
         ss.str(std::string());
         ss.clear();

     }
     else
     {
      //need to work on it..
//         string line;
//         getline(in,line,']');
//         if(line.size()!=0){
//               line.erase(0,1);
//               line.erase(line.size(),1);
//               stringstream ss;
//               *(string*)theNode.getValue()=ss.str();
//               ss.clear();
//         }
     }
     return in;
}


#endif // OPERATORS

