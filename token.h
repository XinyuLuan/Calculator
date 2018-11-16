#ifndef TOKEN
#define TOKEN
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::ostream;
//testing
using std::istream;
using std::stringstream;
using std::string;

enum TOKEN_TYPE {TOKEN_MIX, TOKEN_FACTION,
                 TOKEN_OPERATOR,
                 TOKEN_PERENTHESE_LEFE,
                 TOKEN_PERENTHESE_RIGHT,
                 TOKEN_EXP
                };

class Token{
    public:
       Token();
       Token(string input, int type);
       Token(const Token &other);
       Token& operator=(const Token &other);
       ~Token(){
         _str = "";
         _type = 0;
       }
       bool operator==(const Token &x) const;
       bool operator!=(const Token &x) const;
       bool operator<=(const Token &x) const;
       bool operator>(const Token &x) const;
       bool operator>=(const Token &x) const;

       inline string& str(){
           return _str;
       }
       inline int& type(){
          return _type;
       }
       string getStr() const;
       int getType() const;



       string getResult() const;

       Token* returnSelf();
       friend
       ostream& operator<<(ostream& out, const Token &token);

       friend
       istream& operator>>(istream& in, Token &token);

    protected:
    private:
       string _str;
       int _type;
       void copy(const Token *other);
};
Token* Token::returnSelf(){
  return this;
}

string Token::getResult() const{
 return _str;

}
string Token::getStr() const{
  return _str;
}
int Token::getType() const{
  return _type;
}
Token::Token(){
  _str = "";
  _type = 0;
}
Token::Token(string input, int type){
  _str = input;
  _type = type;
}
Token::Token(const Token &other){
  copy(&other);
}
Token& Token::operator=(const Token &other) {
  if(this!=&other)
     copy(&other);
  return *this;
}
bool Token::operator==(const Token &x) const{
  return getStr() == x.getStr() &&  getType() == x.getType();
}
bool Token::operator!=(const Token &x) const{
  return getStr() != x.getStr() && getType() != x.getType();
}
bool Token::operator>(const Token &x) const{

  return getType() > x.getType();
}

bool Token::operator>=(const Token &x) const{

  return getType() >= x.getType();
}
bool Token::operator<=(const Token &x) const{

  return getType() <= x.getType();
}
void Token::copy(const Token *other){
  _str = other->getStr();
  _type = other->getType();
}

ostream& operator<<(ostream& out, const Token &token){
    if(&out == &cout){
      cout<<token.getStr();
    }else{
        out<<"["<<token.getStr()<<": "<<token.getType()<<"]";
     }
      return out;
}

istream& operator>>(istream& in, Token &token)
{
    if(&in == &cin)
    {
        string line;
        cout << "Value: ";
        getline(cin,line);
        stringstream  ss(line);

        ss >> token.str();
        ss.str(std::string());
        ss.clear();
        cout<<"type: ";
        getline(cin, line);
        ss<<line;
        ss<<token.type();
        ss.clear();
        ss.str(std::string());
    }
    else
    {
        string line;
        getline(in,line,']');
        if(line.size()!=0){
              line.erase(0,1);
              line.erase(line.size(),1);
              stringstream ss;
              ss << line.substr(0, line.find(":")-1);
              ss >>token.str();

              ss.clear();
              ss.str(std::string());
              ss<<line.substr(line.find(":")+1, line.size()-1);
              ss>>token.type();
              ss.clear();
              ss.str(std::string());
        }
    }
    return in;
};
#endif // TOKEN
