#ifndef EXPRESS_H
#define EXPRESS_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <sstream>
#include <token.h>

using namespace std;

class Exp: public Token{
public:
    Exp(TOKEN_TYPE e, char input);
    ~Exp();
    Exp(const Op &other);
    Exp& operator=(const Exp &other);
    void setValue(TOKEN_TYPE e);
    int getP();
    char getAsso();
    friend
    bool operator==(const Exp &x, const Exp &y);

    friend
    bool operator!=(const Exp &x, const Exp &y);

    friend
    ostream& operator<<(ostream& out, const Exp &exp);

    friend
    istream& operator>>(istream& in, Exp &exp);

protected:

private:
    void copy(const Exp& exp);
    int precedence;
    char associativity;
};

Exp::Exp(TOKEN_TYPE e, char input){
        str() = input;
        type() = e;
}
Exp::~Exp(){
  //not sure
}
void Exp::copy(const Exp& other)
{
  //done
  str() = other.getStr();
  type() = other.getType();
}
bool operator==(const Exp &x, const Exp &y){
  return x.getStr() == y.getStr() && x.getType() == y.getType();
}
bool operator!=(const Exp &x, const Exp &y){
  return x.getStr() != y.getStr() && x.getType() != y.getType();
}
ostream& operator<<(ostream& out, const Exp &exp){
      if(&out == &cout)
         out<<"value: "<<exp.getStr() <<", "<<exp.getType()<<endl;
      else{
          out<<"["<<exp.getStr() <<", "<<exp.getType()<<"]";
       }
        return out;
}


istream& operator>>(istream& in, Exp &exp){
//  //ya need to work on this. big time.
//  cout<<exp;
  if(&in == &cin)
     {
         std::string line;
         cout << "Expression: ";
         getline (cin,line);
         stringstream  ss;
         ss<<line;
         ss>>exp.str();
         ss.str(std::string());
         ss.clear();

         exp.type() = TOKEN_EXP;
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
                ss<<line.substr(0, line.find(':')-1);
                ss>>exp.str();
                ss.str(std::string());
                ss.clear();
                ss<<line.substr(line.find(':')+1, line.size());
                ss>>exp.type();
                ss.str(std::string());
                ss.clear();
          }
     }
     return in;
}

#endif // EXPRESS_H
