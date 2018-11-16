#ifndef MIXED
#define MIXED

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <sstream>

#include "fraction.h"
using namespace std;

class mixed : public fraction
{
    public:
        mixed(int w = 0, int n = 0, int d = 1);
        mixed(const fraction& x);
        mixed(int x);
        mixed(double x);
        mixed(const mixed &x);
        mixed(int x, const fraction &f);
        mixed& operator=(const mixed &other);
        mixed& operator=(int x);
        mixed& operator=(double x);
        mixed& operator=(const fraction &x);
        ~mixed();
        void value(int w = 0, int n = 0, int d = 1);
        void value(double x);
        void value(const fraction &x);
//        void setTokeSetting();
        friend
        ostream& operator<<(ostream& out, const mixed &number);

        friend
        istream& operator>>(istream& in, mixed &number);

    private:
        double cdf(double g, int &d);

};

double mixed::cdf(double g, int &d){
   return g-(int)g!=0? cdf(g*=10, d*=10) : g;
}
mixed::mixed(int w, int n, int d):fraction(w * d + (n = (w>=0)?n:n*-1), d){
  setTokeSetting();
}

mixed::mixed(const fraction& x){
  value(x);
  setTokeSetting();
}
mixed::mixed(int x){
  static fraction re(x, 1);
  value(re);
}
mixed::mixed(double x){
  value(x);
}
mixed::mixed(const mixed &x){
  numerator() = x.getNume();
  denominator() = x.getDenom();
  setTokeSetting();
}
mixed::mixed(int x, const fraction &f){
  numerator() = x * f.getDenom() + f.getNume();
  denominator() = f.getDenom();
  setTokeSetting();
}
mixed& mixed::operator=(const mixed &other){
  numerator() = other.getNume();
  denominator() = other.getDenom();
  setTokeSetting();
  return *this;
}

mixed& mixed::operator=(int x){
  numerator() = x * denominator();
  setTokeSetting();
  return *this;
}
mixed& mixed::operator=(double x){
  denominator() = 1;
  numerator() = cdf(x, denominator());
  value(x);
  return *this;
}
mixed& mixed::operator=(const fraction &x){
  value(x);
  return *this;
}
mixed::~mixed(){

}
void mixed::value(int w, int n, int d){
  numerator() = w * d + n;
  denominator() = d;
  setTokeSetting();
}

void mixed::value(double x){
  denominator() = 1;
  numerator() = cdf(x, denominator());
  setTokeSetting();
}

void mixed::value(const fraction &x){
   numerator() = x.getNume();
   denominator() = x.getDenom();
   setTokeSetting();
}
ostream& operator<<(ostream& out, const mixed &number){
  if(&out == &cout){
     out<<"value: "<<number.getNume() <<"/"<<number.getDenom()<<endl;
  }else{
      out<<"["<<number.getNume() <<"/"<<number.getDenom()<<"]";
   }
    return out;
}
istream& operator>>(istream& in, mixed &number){
  if(&in == &cin)
     {
         std::string line;
         cout << "num: ";
         getline (cin,line);
         stringstream  ss(line);
         ss>>number.numerator();
         ss.str(std::string());
         ss.clear();
         cout << "denom; ";
         getline(cin, line);
         ss<<line;
         ss>>number.denominator();
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
               ss>>number.numerator();
               ss.str(std::string());
               ss.clear();
               ss<<line.substr(line.find(':')+1, line.size());
               ss>>number.denominator();
               ss.str(std::string());
               ss.clear();
         }
     }
  return in;
}

#endif // MIXED

