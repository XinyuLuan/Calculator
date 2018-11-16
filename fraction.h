#ifndef FRACTION
#define FRACTION
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <sstream>
#include <token.h>
#include <limits.h>
enum fraction_error {fraction_denom_zeor_error, fraction_overflow, fraction_underflow, fraction_denom_neg};
using namespace std;
double helper_cdf(double g, int &d){
   return g-(int)g!=0? helper_cdf(g*=10, d*=10) : g;
}
class fraction: public Token
{
    public:
        fraction(int n = 0, int d = 1);
        ~fraction();
        fraction(int x);
        fraction(double x);
        fraction(const fraction &other);
        fraction& operator=(const fraction &other);
        fraction& operator=(int other);
        fraction& operator=(double other);
        void setValue(int n = 0, int d = 1);


        fraction& operator+=(const fraction &other);
        fraction& operator-=(const fraction &other);
        fraction& operator*=(const fraction &other);
        fraction& operator/=(const fraction &other);
        fraction& operator^=(const fraction &other);
        fraction& operator+=(int other);
        fraction& operator-=(int other);
        fraction& operator*=(int other);
        fraction& operator/=(int other);
        fraction& operator^=(int other);
        fraction& operator+=(double other);
        fraction& operator-=(double other);
        fraction& operator*=(double other);
        fraction& operator/=(double other);
        fraction& operator^=(double other);

        friend
        fraction& operator+(const fraction &x, const fraction &y);
        friend
        fraction& operator-(const fraction &x, const fraction &y);
        friend
        fraction& operator*(const fraction &x, const fraction &y);
        friend
        fraction& operator/(const fraction &x, const fraction &y);
        friend
        fraction& operator^(const fraction &x, const fraction &y);

        friend
        bool operator==(const fraction &x, const fraction &y);

        friend
        bool operator!=(const fraction &x, const fraction &y);

        friend
        bool operator<=(const fraction &x, const fraction &y);

        friend
        bool operator>=(const fraction &x, const fraction &y);

        friend
        bool operator<(const fraction &x, const fraction &y);

        friend
        bool operator>(const fraction &x, const fraction &y);


        friend
        bool operator==(const fraction &x, const fraction &y);

        friend
        bool operator!=(const fraction &x, const fraction &y);

        friend
        bool operator<=(const fraction &x, const fraction &y);

        friend
        bool operator>=(const fraction &x, const fraction &y);

        friend
        bool operator<(const fraction &x, const fraction &y);

        friend
        bool operator>(const fraction &x, const fraction & y);

        friend
        bool operator==(const fraction &x, int y);

        friend
        bool operator!=(const fraction &x, int y);

        friend
        bool operator<=(const fraction &x, int y);

        friend
        bool operator>=(const fraction &x, int y);

        friend
        bool operator<(const fraction &x, int y);

        friend
        bool operator>(const fraction &x, int y);

        friend
        bool operator==(int  x, const fraction &y);

        friend
        bool operator!=(int  x, const fraction &y);

        friend
        bool operator<=(int  x, const fraction &y);

        friend
        bool operator>=(int  x, const fraction &y);

        friend
        bool operator<(int  x, const fraction &y);

        friend
        bool operator>(int  x, const fraction &y);

        friend
        bool operator==(double  x, const fraction &y);

        friend
        bool operator!=(double  x, const fraction &y);

        friend
        bool operator<=(double  x, const fraction &y);

        friend
        bool operator>=(double  x, const fraction &y);

        friend
        bool operator<(double  x, const fraction &y);

        friend
        bool operator>(double  x, const fraction &y);

        friend
        bool operator==(double  x, const fraction &y);

        friend
        bool operator!=(double  x, const fraction &y);

        friend
        bool operator<=(double  x, const fraction &y);

        friend
        bool operator>=(double  x, const fraction &y);

        friend
        bool operator<(double  x, const fraction &y);

        friend
        bool operator>(double  x, const fraction &y);

        friend
        fraction& operator+(const fraction &x, int y);

        friend
        fraction& operator-(const fraction &x, int y);

        friend
        fraction& operator*(const fraction &x, int y);

        friend
        fraction& operator/(const fraction &x, int y);

        friend
        fraction& operator^(const fraction &x, int y);

        friend
        fraction& operator+(int x, const fraction &y);

        friend
        fraction& operator-(int x, const fraction &y);

        friend
        fraction& operator*(int x, const fraction &y);

        friend
        fraction& operator/(int x, const fraction &y);

        friend
        fraction& operator^(int x, const fraction &y);


        friend
        fraction& operator+(const fraction &x, double y);

        friend
        fraction& operator-(const fraction &x, double y);

        friend
        fraction& operator*(const fraction &x, double y);

        friend
        fraction& operator/(const fraction &x, double y);

        friend
        fraction& operator^(const fraction &x, double y);

        friend
        fraction& operator+(const fraction &x, double y);

        friend
        fraction& operator-(const fraction &x, double y);

        friend
        fraction& operator*(const fraction &x, double y);

        friend
        fraction& operator/(const fraction &x, double y);

        friend
        fraction& operator^(const fraction &x, double y);

        friend
        ostream& operator<<(ostream& out, const fraction &frac);

        friend
        istream& operator>>(istream& in, fraction &frac);


        int getDenom() const;
        int getNume() const;
    protected:
        void reduce();
        int& numerator();
        int& denominator();
        bool utiSS(string& o, stringstream& ss);
        void setTokeSetting();

    private:
        int num, denom;

        void copy(const fraction& other);
        int gcd(int p, int q);
        double cdf(double g, int &d);
        int cdf2(double g, int &d);
        double cdf_2(double g, int &d);
        fraction& tdf(double g);
        void binary( double value);
        bool isDenomZero();
        bool throwingOver();
        bool throwingUnder();
        bool isDenomNeg();
        bool convertToNeg();

};
bool fraction::isDenomNeg(){
  throw fraction_denom_neg;
  return true;
}

bool fraction::isDenomZero(){
  throw fraction_denom_zeor_error;
  return true;
}
bool fraction::throwingOver(){
  throw fraction_overflow;
  return true;
}

bool fraction::throwingUnder(){
  throw fraction_underflow;
  return true;
}

void fraction::setTokeSetting(){
  type() = TOKEN_FACTION;
  stringstream ss;
  reduce();
  if(numerator()>denominator() && numerator()%denominator()!=0 && denominator()!=1){
      ss<<numerator()/denominator();
      string o;
      o = ss.str();
      ss.str(string());
      ss.clear();
      ss<<numerator()%denominator();
      o = o + ' ' + ss.str() + '/';
      ss.str(string());
      ss.clear();
      ss<<denominator();
      o = o + ss.str();
      str() = o;
      ss.str(string());
      ss.clear();
  }
  else{
    ss<<numerator();
    string o;
    o = ss.str();
    (denominator()!=1)&&utiSS(o, ss);
    str() = o;
   }
}
bool fraction::utiSS(string& o, stringstream& ss){
        o = o + ('/');
        ss.str(string());
        ss.clear();
        ss<<denominator();
        o = o + ss.str();
        return true;
}

int fraction::getDenom() const{
  return denom;
}
int fraction::getNume() const{
  return num;
}
fraction& fraction::tdf(double g){
  int whole = g;
  g = g - whole;
  int i = 1;
  while(g*i<1){
      i++;
  }
  static fraction re(whole * i, i);
  return re;
}
fraction::fraction(int n , int d){
  (d==0)&&isDenomZero();
  double x = n/d;
  (x > INT_MAX)&&throwingOver();
  (x <INT_MIN)&&throwingUnder();
   num = n;
   denom=d;
  (denom<=0)&&isDenomZero();
   setTokeSetting();
}
fraction::~fraction(){
   num = denom = 0;
}
fraction::fraction(int x){
   num = x;
   denom = 1;
   setTokeSetting();
}
fraction::fraction(double x){
   stringstream ss;
   ss<<x;
   string line = ss.str();
   denom = 1;
   try{
      if(line.find('.')!=string::npos){
          (x > INT_MAX)&&throwingOver();
          (x <INT_MIN)&&throwingUnder();
          num = (int)x;
          int base = 1;
          line = line.substr(line.find('.')+1, line.size()-1);
          for(unsigned int i=0; i<line.size(); i++, base*=10);
          (base>INT_MAX)&&throwingOver();
          denom *= base;
          num = num * base  + ((num<0)?(stoi(line)*-1):(stoi(line)));

      }else{
          num = std::stoi(line);
      }
   }
   catch(std::invalid_argument& e){
     throw fraction_overflow;
   }
   catch(std::out_of_range& e){
     throw fraction_overflow;
   }
   catch(...) {
     throw fraction_overflow;
   }
  setTokeSetting();
}
fraction::fraction(const fraction &other){
  //done
  (other.denom==0)&&this->isDenomZero();
  num = other.num;
  denom = other.denom;
  reduce();
  setTokeSetting();
}
fraction& fraction::operator=(const fraction &other){
  //done
(other.denom==0)&&this->isDenomZero();
  num = other.num;
  denom = other.denom;
  reduce();
  setTokeSetting();
  return *this;
}
fraction& fraction::operator=(int other){
  //done
  num = other;
  denom = 1;
  setTokeSetting();
  return *this;
}
fraction& fraction::operator=(double other){
  double x = other;
  stringstream ss;
  ss<<x;
  string line = ss.str();
  denom = 1;
  try{

       if(line.find('.')!=string::npos){
           (x > INT_MAX)&&throwingOver();
           (x <INT_MIN)&&throwingUnder();
           num = (int)x;
           int base = 1;
           line = line.substr(line.find('.')+1, line.size()-1);
           for(unsigned int i=0; i<line.size(); i++, base*=10);
           (base>INT_MAX)&&throwingOver();
               denom *= base;
               num = num * base  + stoi(line);
       }else{
           num = std::stoi(line);
       }
  }
  catch(std::invalid_argument& e){
    throw fraction_overflow;
  }
  catch(std::out_of_range& e){
    throw fraction_overflow;
  }
  catch(...) {
    throw fraction_overflow;
  }

  setTokeSetting();
  return *this;
}
void fraction::setValue(int n , int d ){
  //done
  num = n;
  denom = d;
  reduce();
}

fraction& fraction::operator+=(const fraction &other){
  //done
  if(denom == other.denom){
    num += other.num;
  }else{
    num = num * other.denom + other.num * denom;
    denom = denom * other.denom;
  }
  reduce();
  setTokeSetting();
  return *this;
}
fraction& fraction::operator-=(const fraction &other){
  //done
  if(denom == other.denom){
    num -= other.num;
  }else{
    num = num * other.denom - other.num * denom;
    denom = denom * other.denom;
  }
  reduce();
  setTokeSetting();
  return *this;
}
fraction& fraction::operator*=(const fraction &other){
  //done
  num *= other.num;
  denom *= other.denom;
  reduce();
  setTokeSetting();
  return *this;
}
fraction& fraction::operator/=(const fraction &other){
  //done
  num *= other.denom;
  denom *= other.num;
  reduce();
  setTokeSetting();
  return *this;
}
fraction& fraction::operator^=(const fraction &other){
  //need to check it
  double n, d;
  n = other.num;
  d = other.denom;
  double one = num/denom;
  double input = pow(one, n/d);
  static fraction re =  tdf(input);
  num = re.num;
  denom = re.denom;
  reduce();
  setTokeSetting();
  return *this;
}
fraction& fraction::operator+=(int other){
  //done
  num += other*denom;
  reduce();
  setTokeSetting();
  return *this;
}
fraction& fraction::operator-=(int other){
   //done
   num -= other*denom;
   reduce();
   setTokeSetting();
   return *this;
}
fraction& fraction::operator*=(int other){
  //done
  num *= other;
  reduce();
  setTokeSetting();
  return *this;
}
fraction& fraction::operator/=(int other){
  //done
  denom *= other;
  reduce();
  setTokeSetting();
  return *this;
}
fraction& fraction::operator^=(int other){
  //not working
  for(int i =1, base = num; i<other; i++){
     num *= base;
  }
  for(int i =1, base = denom; i<other; i++){
     denom *= base;
  }
  reduce();
  setTokeSetting();
  return *this;
}
fraction& fraction::operator+=(double other){
  //done
  int denom2 = 1;
  int num2 = cdf(other, denom2);
  num  = num *  denom2 +  num2 * denom;
  denom = denom * denom2;
  reduce();
  setTokeSetting();
  return *this;
}
fraction& fraction::operator-=(double other){
  //done
  int denom2 = 1;
  int num2 = cdf(other, denom2);
  num -= num * denom2 - num2 * denom;
  denom = denom * denom2;
  reduce();
  setTokeSetting();
  return *this;
}
fraction& fraction::operator*=(double other){
  //need to review
  int denom2 = 1;
  int num2 = cdf(other, denom2);
  num *= num2;
  denom *= denom;
  reduce();
  setTokeSetting();
  return *this;
}
fraction& fraction::operator/=(double other){
  //need to review
  int denom2 = 1;
  int num2 = cdf(other, denom2);
  num /= num2;
  denom /= denom;
  reduce();
  setTokeSetting();
  return *this;
}
fraction& fraction::operator^=(double other){
  //need help...
  int denom2 = 1;
  int num2 = cdf(other, denom2);
  for(int i =1, base = num; i<num2; i++){
     num *= base;
  }
  for(int i =1, base = denom; i<denom2; i++){
     denom *= base;
  }
  setTokeSetting();
  return *this;
}

void fraction::reduce(){
  //done
    int i = gcd(num, denom);
    num/=i;
    denom/=i;
    (denom<1)&&convertToNeg();
}
bool fraction::convertToNeg(){
  num*=-1;
  denom*=-1;
  return true;
}

int& fraction::numerator(){
  //done
  return num;
}
int& fraction::denominator(){
  //done
  return denom;
}

void fraction::copy(const fraction& other)
{
  //done
    num = other.num;
    denom = other.denom;
    setTokeSetting();
}

int fraction::gcd(int p, int q)
{
  //done
    return !q ? p : gcd(q,p%q);
}
int fraction::cdf2(double g, int &d){
  //cout<<"a: "<<numeric_limits<double>::denorm_min();
  //cout<<"b: "<<numeric_limits<double>::infinity();
  //return 0;
  double  x=g;//
  d*=10;
  for(unsigned int i=1; x-(int)x!=0 && d<INT_MAX; i++){
      cout<<"loop"<<endl;
           x*=10;
          d*=10;
  }
  return d;
}


double fraction::cdf(double g, int &d){
  if(g ==  numeric_limits<double>::denorm_min())
    throw fraction_denom_zeor_error;
  return g-(int)g!=0? cdf(g*=10, d*=10) : g;
}
double fraction::cdf_2(double g, int &d){
  //get base
   return g/10!=0? cdf_2(g/=10, d*=10) : g;
}


fraction& operator+(const fraction &x, const fraction &y){
  //it should have memory issue...
  fraction * re = new fraction();
  (*re).num = x.num * y.denom + y.num * x.denom;
  (*re).denom = x.denom * y.denom;
  (*re).reduce();
  (*re).setTokeSetting();
  return *re;
}

fraction& operator-(const fraction &x, const fraction &y){
  //it should have memory issue...
  fraction * re = new fraction();
  (*re).num = y.num * x.denom - x.num * y.denom;
  (*re).denom = y.denom * x.denom;
  (*re).reduce();
  (*re).setTokeSetting();
  return *re;

}

fraction& operator*(const fraction &x, const fraction &y){
  //it should have memory issue...
  fraction * re = new fraction();
  (*re).num = x.num * y.num;
  (*re).denom = x.denom * y.denom;
  (*re).reduce();
  (*re).setTokeSetting();
  return *re;
}

fraction& operator/(const fraction &x, const fraction &y){
  //it should have memory issue...
  fraction * re = new fraction();
  (*re).num = y.num *x.denom;
  (*re).denom = y.denom * x.num;
  (*re).reduce();
  (*re).setTokeSetting();
  return * re;
}

fraction& operator^(const fraction &x, const fraction &y){
  //need to work on this
  double one = y.num*1.0 / y.denom*1.0;
  double two = x.num*1.0 / x.denom*1.0;
  double result = pow((double)one, two);
  fraction * re = new fraction(result);
  (*re).reduce();
  (*re).setTokeSetting();
  return * re;
}


bool operator==(const fraction &x, const fraction &y){
  //done
  return x.num*y.denom == y.num*x.denom;
}


bool operator!=(const fraction &x, const fraction &y){
  //done
  return x.num*y.denom != y.num*x.denom;
}


bool operator<=(const fraction &x, const fraction &y){
  //done
  return x.num*y.denom <= y.num*x.denom;
}


bool operator>=(const fraction &x, const fraction &y){
  //done
  return x.num*y.denom >= y.num*x.denom;
}


bool operator<(const fraction &x, const fraction &y){
  //done
  return x.num*y.denom < y.num*x.denom;
}


bool operator>(const fraction &x, const fraction &y){
  //done
  return x.num*y.denom > y.num*x.denom;
}

bool operator==(const fraction &x, int y)
{
  //done
  return x.num == y *x.denom;
}


bool operator!=(const fraction &x, int y)
{
    //done
    return x.num != y *x.denom;
}

bool operator<=(const fraction &x, int y)
{
   //done
   return x.num <= y *x.denom;
}

bool operator>=(const fraction &x, int y)
{
   //done
   return x.num >= y *x.denom;
}


bool operator<(const fraction &x, int y)
{
    //done
    return x.num < y *x.denom;
}


bool operator>(const fraction &x, int y)
{
  //done
  return x.num > y *x.denom;
}


bool operator==(int  x, const fraction &y){
  //done
  return x *y.denom == y.num;
}


bool operator!=(int  x, const fraction &y){
  //done
  return x *y.denom != y.num;
}


bool operator<=(int  x, const fraction &y){
  //done
  return x *y.denom <= y.num;
}


bool operator>=(int  x, const fraction &y){
  //done
  return x *y.denom >= y.num;
}


bool operator<(int  x, const fraction &y){
  //done
  return x *y.denom < y.num;
}


bool operator>(int  x, const fraction &y){
  //done
  return x *y.denom > y.num;
}


bool operator==(double  x, const fraction &y){
  //not working
  double compare = y.getNume() / y.getNume();
  return x == compare;
  //or
  int n, d = 1;
  n = helper_cdf(x, d);
  return n*y.getDenom() == y.getDenom() * d;
}


bool operator!=(double  x, const fraction &y){
  //not working
  int n, d = 1;
  n = helper_cdf(x, d);
  return n*y.getDenom() != y.getDenom() * d;
}


bool operator<=(double  x, const fraction &y){
  //not working
  int n, d = 1;
  n = helper_cdf(x, d);
  return n*y.getDenom() <= y.getDenom() * d;
}


bool operator>=(double  x, const fraction &y){
  //not working
  int n, d = 1;
  n = helper_cdf(x, d);
  return n*y.getDenom() >= y.getDenom() * d;
}


bool operator<(double  x, const fraction &y){
  //not working
  int n, d = 1;
  n = helper_cdf(x, d);
  return n*y.getDenom() < y.getDenom() * d;
}

bool operator>(double  x, const fraction &y){
  //not working
  int n, d = 1;
  n = helper_cdf(x, d);
  return n*y.getDenom() > y.getDenom() * d;
}

fraction& operator+(const fraction &x, int y){
  //done
  static fraction re;
  re.num = x.num + y*x.denom;
  re.reduce();
  re.setTokeSetting();
  return re;
}


fraction& operator-(const fraction &x, int y){
  //done
  static fraction re;
  re.num = x.num - y*x.denom;
  re.reduce();
  re.setTokeSetting();
  return re;
}


fraction& operator*(const fraction &x, int y){
  //done
  static fraction re;
  re.num = x.num * y;
  re.reduce();
  re.setTokeSetting();
  return re;
}


fraction& operator/(const fraction &x, int y){
  //done
  static fraction re;
  re.denom = x.denom * y;
  re.reduce();
  re.setTokeSetting();
  return re;
}


fraction& operator^(const fraction &x, int y){
  //done
  static fraction re;
  re.num = pow((double)x.num, y);
  re.denom = pow((double)x.denom, y);
  re.reduce();
  re.setTokeSetting();
  return re;
}


fraction& operator+(int x, const fraction &y){
  //done
  static fraction re;
  re.num += x * y.denom;
  re.reduce();
  re.setTokeSetting();
  return re;
}


fraction& operator-(int x, const fraction &y){
  //done
  static fraction re;
  re.num -= x * y.denom;
  re.reduce();
  re.setTokeSetting();
  return re;
}


fraction& operator*(int x, const fraction &y){
  //done
  static fraction re;
  re.num *= x * y.num;
  re.reduce();
  re.setTokeSetting();
  return re;
}


fraction& operator/(int x, const fraction &y){
  //done
  static fraction re;
  re.num = x * y.denom;
  re.denom = y.num;
  re.reduce();
  re.setTokeSetting();
  return re;
}


fraction& operator^(int x, const fraction &y){
  //problem
  static fraction re;
  x = pow((double)x , y.getNume());
  double nthRoot=pow(x,1.0/y.getDenom());
  re.denom = 1;
  re.num = helper_cdf(nthRoot, re.denom);
  re.reduce();
  re.setTokeSetting();
  return re;
}



fraction& operator+(const fraction &x, double y){
  //problem
  static fraction re;
  int n, d = 1;
  n = helper_cdf(y, d);
  re.denom = x.getDenom() * d;
  re.num = x.getNume() * d + n * x.getDenom();
  re.reduce();
  re.setTokeSetting();
  return re;
}

fraction& operator-(const fraction &x, double y){
  //problem
  static fraction re;
  int n, d = 1;
  n = helper_cdf(y, d);
  re.denom = x.getDenom() * d;
  re.num = x.getNume() * d - n * x.getDenom();
  re.reduce();
  re.setTokeSetting();
  return re;
}

fraction& operator*(const fraction &x, double y){
  //problem
  static fraction re;
  int n, d = 1;
  n = helper_cdf(y, d);
  re.denom = x.getDenom() * d;
  re.num = x.getNume() * n;
  re.reduce();
  re.setTokeSetting();
  return re;
}

fraction& operator/(const fraction &x, double y){
  //problem
  static fraction re;
  int n, d = 1;
  n = helper_cdf(y, d);
  re.denom = x.getDenom() * n;
  re.num = x.getNume() * d;
  re.reduce();
  re.setTokeSetting();
  return re;
}

fraction& operator^(const fraction &x, double y){
  //problem...real problem
  static fraction re;
  int n, d = 1;
  n = helper_cdf(y, d);
  re.num = pow((double)x.getNume(), n);
  re.denom = pow((double)x.getDenom(), n);
  //double nthRoot=pow(x,1.0/y.getDenom());
  re.reduce();
  re.setTokeSetting();
  return re;
}

ostream& operator<<(ostream& out, const fraction &frac){
      if(&out == &cout){
            cout<<frac.num <<"/"<<frac.denom;
      }else{
          out<<"["<<frac.num <<"/"<<frac.denom<<"]";
       }
        return out;
}


istream& operator>>(istream& in, fraction &frac){
  if(&in == &cin)
     {
         std::string line;
         cout << "num: ";
         getline (cin,line);
         stringstream  ss(line);
         //*(string*)theNode.getValue()=ss.str();
         ss>>frac.numerator();
         ss.str(std::string());
         ss.clear();
         cout << "denom; ";
         getline(cin, line);
         ss<<line;
         ss>>frac.denominator();
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
               ss>>frac.numerator();
               ss.str(std::string());
               ss.clear();
               ss<<line.substr(line.find(':')+1, line.size());
               ss>>frac.denominator();
               ss.str(std::string());
               ss.clear();
         }else{

         }
     }
     return in;
}
#endif // FRACTION

