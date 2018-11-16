#ifndef PARENTHESIS
#define PARENTHESIS

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <sstream>
#include <token.h>

using namespace std;

class Paren: public Token{
public:
    Paren(TOKEN_TYPE e);
    ~Paren();
    Paren(const Paren &other);
    Paren& operator=(const Paren &other);
    void setValue(TOKEN_TYPE e);
    friend
    bool operator==(const Paren &x, const Paren &y);

    friend
    bool operator!=(const Paren &x, const Paren &y);

    friend
    ostream& operator<<(ostream& out, const Paren &paren);

    friend
    istream& operator>>(istream& in, Paren &paren);

protected:

private:
    void copy(const Paren& other);
};
Paren::Paren(TOKEN_TYPE e){
   if(e==TOKEN_PERENTHESE_LEFE){
        str() = '(';
        type() = TOKEN_PERENTHESE_LEFE;
     }else{
        str() = ')';
        type() = TOKEN_PERENTHESE_RIGHT;
     }
}
Paren::~Paren(){
  //done
}
void Paren::copy(const Paren& other)
{
  //done
  str() = other.getStr();
  type() = other.getType();
}
bool operator==(const Paren &x, const Paren &y){
  return x.getStr() == y.getStr() && x.getType() == y.getType();
}
bool operator!=(const Paren &x, const Paren &y){
  return x.getStr() != y.getStr() && x.getType() != y.getType();
}
ostream& operator<<(ostream& out, const Paren &paren){
      if(&out == &cout)
         out<<"value: "<<paren.getStr() <<", "<<paren.getType()<<endl;
      else{
          out<<"["<<paren.getStr() <<", "<<paren.getType()<<"]";
       }
        return out;
}


istream& operator>>(istream& in, Paren &paren){
  cout<<paren;
  //ya need to work on this. big time.
  if(&in == &cin)
     {
//         std::string line;
//         cout << "num: ";
//         getline (cin,line);
//         stringstream  ss(line);
//         //*(string*)theNode.getValue()=ss.str();
//         ss>>frac.numerator();
//         ss.str(std::string());
//         ss.clear();
//         cout << "denom; ";
//         getline(cin, line);
//         ss<<line;
//         ss>>frac.denominator();
//         ss.str(std::string());
//         ss.clear();

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
#endif // PARENTHESIS

