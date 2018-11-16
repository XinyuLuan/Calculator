#ifndef PARSER
#define PARSER
//#include <iostream>
//#include <cstdlib>
//#include <string>
//#include "token.h"
#include "stackjw.h"
#include "queue_link.h"
#include "fraction.h"
#include "mixed.h"
#include "operators.h"
#include "parenthesis.h"
#include "express.h"
#include <fstream>
#include <stdexcept>
#include <stdlib.h>
#include "vector"
using std::cin;
using std::cout;
using std::string;

using std::ostream;

using namespace std;

class Parser;
enum INPUT_ERROR { MISSING_PARENTHESIS, DENOM_NEGATIVE, INCORECT_INPUT, NO_MEMORY_STORED, EMPTYINPUT, INPUT_CANNT_DISPLAY};

typedef void (Parser::*fptr)();
typedef void (Parser::*fptr3)(Token * pba);
typedef string (Parser::*fptr4)();
typedef void (Parser::*fptr5)();

class Parser{
  public:
    Parser();
    ~Parser();
    string getUserInput2(string input2);
    void printStackOne();
    string printQue();
    void run(char type);
    string calReult();
    void READ(string &line);
    void WRITE();

  protected:
     //string type;
  private:
    LinkQueue<Token *> que;
    stackJW<Token *> stackOne;
    stackJW<Token *> stackTwo;
    stackJW<Token *> memoryDeleteStack;
    ofstream outputFile;

    void leftP();
    void rightP();
    void operAdd();
    void operMin();
    void operMult();
    void operDiv();
    void operPower();
    void isSpace();
    void isNumber();
    void isDec();
    void isMemory();

    void isMemory_c_ALL();
    void isMemory_c_single();
    void isTrimS();
    void isThrow();
    void processNumber();
    void processDec();
    void processFrac();
    void processOnlyNumber();
    void processFrac_fra();
    void processFrac_mixed();



    void Add(Token * pba);
    void Min(Token * pba);
    void Mult(Token * pba);
    void Div(Token * pba);
    void Power(Token * pba);
    void Number(Token * pba);
    void isThrowToken(Token* pba);

    void TOKEN_LEFT_f();
    void TOKEN_FRACTION_f();
    void TOKEN_EXP_f();
    void TOKEN_RIGHT_f();
    void TOKEN_THROW_f();
    void TOKEN_OP_f();
    void TOKEN_LEFT_f_option1();
    void TOKEN_FRACTION_f_option1();
    void TOKEN_FRACTION_f_option2();
    void TOKEN_EXP_f_option1();
    void TOKEN_OP_f_opetion1();
    void processOnlyNumber_option1();
    void processOnlyNumber_option2();

    bool validAlg();
    bool throwing_INPUT_ERROR();
    bool throwing_EMPTY();
    bool throwing_MISSING_PAR();
    bool throwing_NO_MEMORY_STORED();
    bool processMem();
    bool addQtoSone();
    bool processStoreMem();
    bool processStoreMem2();
    bool buildOutput();
    bool writeOutput();
    bool isMemory_c();
    bool writeProcess(int i);
    bool processNegSign();
    bool processNegSign2();
    bool reParser();
    bool reParser2();
    bool spcParser();
    bool reParser3();
    string MISSING_PARENTHESIS_f();
    string DENOM_NEGATIVE_f();
    string INCORECT_INPUT_f();
    string NO_MEMORY_STORED_f();
    string EMPTYINPUT_f();
    string INPUT_CANNT_DISPLAY_f();

    fptr whatToDo[128];
    fptr3 output[128];
    fptr4 errorFptr[10];
    fptr5 validFptr[10];

    mixed ** memory;

    bool isMemoryProcess;
    char memory_spot;
    vector<char> memory_spot_v;
    bool loop;
    string input;
    string temp;
    int expCount;
    int calCount;
    ifstream file;
};
Parser::Parser(){
  for(unsigned int i = 0; i < 128; ++i)
     whatToDo[i] = &Parser::isThrow;
  whatToDo[static_cast<int>('(')] = &Parser::leftP;
  whatToDo[static_cast<int>(')')] = &Parser::rightP;
  whatToDo[static_cast<int>('+')] = &Parser::operAdd;
  whatToDo[static_cast<int>('-')] = &Parser::operMin;
  whatToDo[static_cast<int>('*')] = &Parser::operMult;
  whatToDo[static_cast<int>('/')] = &Parser::operDiv;
  whatToDo[static_cast<int>('^')] = &Parser::operPower;
  whatToDo[static_cast<int>(' ')] = &Parser::isSpace;

  whatToDo[1] = &Parser::isMemory_c_ALL;
  whatToDo[0] = &Parser::isMemory_c_single;

  whatToDo[static_cast<int>('3')] = &Parser::isNumber;
  whatToDo[static_cast<int>('.')] = &Parser::isDec;
  whatToDo[static_cast<int>('#')] = &Parser::isTrimS;
  whatToDo[4] = &Parser::processDec;//4
  whatToDo[5] = &Parser::processFrac;//5
  whatToDo[6] = &Parser::processOnlyNumber;//6
  whatToDo[7] = &Parser::processFrac_mixed;//7
  whatToDo[8] = &Parser::processFrac_fra;//8
  whatToDo[9] = &Parser::isThrow;
  whatToDo[10] = &Parser::TOKEN_LEFT_f_option1;
  whatToDo[11] = &Parser::TOKEN_FRACTION_f_option2;
  whatToDo[12] = &Parser::TOKEN_FRACTION_f_option1;
  whatToDo[13] = &Parser::TOKEN_FRACTION_f_option2;
  whatToDo[14] = &Parser::TOKEN_FRACTION_f_option1;
  whatToDo[15] = &Parser::isThrow;
  whatToDo[16]= &Parser::TOKEN_OP_f_opetion1;
  whatToDo[17]= &Parser::processOnlyNumber_option2;
  whatToDo[18]= &Parser::processOnlyNumber_option1;
  for(unsigned int i=0; i<26; i++){
     whatToDo[static_cast<int>('a')+i] =
     whatToDo[static_cast<int>('A')+i] =
        &Parser::isMemory;
   }
  for(int i=0; i<128; ++i)
     Parser::output[i] = &Parser::isThrowToken;
  output[static_cast<int>('+')] =  &Parser::Add;
  output[static_cast<int>('-')] =  &Parser::Min;
  output[static_cast<int>('/')] =  &Parser::Div;
  output[static_cast<int>('*')] =  &Parser::Mult;
  output[static_cast<int>('^')] =  &Parser::Power;
  output[static_cast<int>('3')] =  &Parser::Number;


  errorFptr[MISSING_PARENTHESIS] = &Parser::MISSING_PARENTHESIS_f;
  errorFptr[DENOM_NEGATIVE]= &Parser::DENOM_NEGATIVE_f;
  errorFptr[INCORECT_INPUT] = &Parser::INCORECT_INPUT_f;
  errorFptr[NO_MEMORY_STORED] = &Parser::NO_MEMORY_STORED_f;
  errorFptr[EMPTYINPUT] = &Parser::EMPTYINPUT_f;
  errorFptr[INPUT_CANNT_DISPLAY] = &Parser::INPUT_CANNT_DISPLAY_f;

  validFptr[TOKEN_EXP] = &Parser::TOKEN_EXP_f;
  validFptr[TOKEN_FACTION] = &Parser::TOKEN_FRACTION_f;
  validFptr[TOKEN_OPERATOR] = &Parser::TOKEN_OP_f;
  validFptr[TOKEN_PERENTHESE_LEFE] = &Parser::TOKEN_LEFT_f;
  validFptr[TOKEN_PERENTHESE_RIGHT] = &Parser::TOKEN_RIGHT_f;
  validFptr[6] = &Parser::TOKEN_THROW_f;

  isMemoryProcess = false;
  memory = new mixed*[26];
  loop = true;

}
Parser::~Parser(){
  for(unsigned int i=0; i<26; ++i){
       delete (memory[i]);
      memory[i] = NULL;
  }
  delete [] memory;
  while(!memoryDeleteStack.empty()){
      delete memoryDeleteStack.pop();
  }
  outputFile.close();
}
void Parser::TOKEN_LEFT_f_option1(){
  memoryDeleteStack.push(stackOne.pop());
  stackOne.pop();
  memoryDeleteStack.push(stackTwo.pop());
  Token * t = new Exp(TOKEN_EXP,'E');
  stackOne.push(t);
  memoryDeleteStack.push(t);
  expCount=0;
}

void Parser::TOKEN_LEFT_f(){
   expCount++;
   (this->*whatToDo[(expCount==3 || (expCount==2 && calCount==1))+9])();
}
void Parser::TOKEN_FRACTION_f_option1(){
  Token * bye = stackTwo.pop();
  (stackOne.size()<2 ) && throwing_INPUT_ERROR();
  for(unsigned int i=0; i<2;i++){
      bye = stackOne.pop();
  }
  //need to hold on to this memorya and delete it
  Token * t = new Exp(TOKEN_EXP,'E');
  stackOne.push(t);
  memoryDeleteStack.push(t);
  calCount=0;
  expCount++;
}
void Parser::TOKEN_FRACTION_f_option2(){
  Token * bye = stackTwo.pop();
  stackOne.push(bye);
}
void Parser::TOKEN_FRACTION_f(){
  calCount++;
  (this->*whatToDo[(calCount==3)+11])();
}
void Parser::TOKEN_EXP_f_option1(){
  Token * bye = stackTwo.pop();
  (stackTwo.size()<2 ) && throwing_INPUT_ERROR();
  for(unsigned int i=0; i<2;i++){
      bye = stackOne.pop();
  }
  Token * t = new Exp(TOKEN_EXP,'E');
  stackOne.push(t);
  memoryDeleteStack.push(t);
  calCount=0;
  expCount++;
}

void Parser::TOKEN_EXP_f(){
  calCount++;
  (this->*whatToDo[(calCount==3)+13])();
}
void Parser::TOKEN_OP_f_opetion1(){
  stackOne.push(stackTwo.pop());
  calCount++;
}

void Parser::TOKEN_OP_f(){
  (this->*whatToDo[(stackOne.empty()==false
                    &&
                     (stackOne.top()->getType()==TOKEN_EXP || stackOne.top()->getType()==TOKEN_FACTION)
                    )+15])();
}
void Parser::TOKEN_RIGHT_f(){
  stackOne.push(stackTwo.pop());
  expCount++;
}
void Parser::TOKEN_THROW_f(){
  throw INCORECT_INPUT;
}

bool Parser::validAlg(){
  calCount = 0;
  expCount = 0;
  while(stackTwo.size()>0)
  {
      (this->*validFptr[
           stackTwo.top()->getType()
          ]
      )();
  }
  return true;
}

string Parser::MISSING_PARENTHESIS_f(){
    return "Error: algebraically incorrect -- missing parenthesis";
}

string Parser::DENOM_NEGATIVE_f(){
    return "Error: the fraction have a negative sign in denominator";
}

string Parser::INCORECT_INPUT_f(){
    return "Error: input incorrectly";
}

string Parser::NO_MEMORY_STORED_f(){
  stringstream ss;
  ss<<this->memory_spot;
   return "Error: No memory stored under this char<"+ss.str()+">";
}
string Parser::EMPTYINPUT_f(){
  return "";
}
string Parser::INPUT_CANNT_DISPLAY_f(){
  return "Sorry, the result is overflow or underflow as the number is too large to display";
}

bool Parser::buildOutput(){
  input += stackTwo.top()->getResult();
  isMemoryProcess&&processMem();
  return true;
}


string Parser::calReult()
{
  Token *pba;
  while(!que.empty()){
      que.dequeue(pba);
      (this->*output[
          static_cast<int>((pba->getType()==TOKEN_OPERATOR)?pba->getStr()[0]:'3')
          ]
      )
      (pba);
  }
  (!stackTwo.empty())&&buildOutput();
  return input;
}
bool Parser::addQtoSone(){
    que.enqueue(stackOne.pop());
    return true;
}
bool Parser::processStoreMem(){
  (temp.size()>1)&&throwing_INPUT_ERROR();
    input.erase(0,1);
  (memory[toupper(temp[0])-65]==NULL)&&throwing_NO_MEMORY_STORED();
  input = memory[toupper(temp[0])-65]->getStr() + input;
  return true;
}
bool Parser::processStoreMem2(){
 // (temp.size()>1)&&throwing_INPUT_ERROR();
  memory_spot=input[0];
  this->memory_spot_v.push_back(input[0]);
  isMemoryProcess = true;
  input.erase(0, 3);
  return true;
}
bool Parser::processMem(){
    fraction *  temp = static_cast<fraction* >(stackTwo.top());
    stringstream ss;
    input += " is now stored in memory location <";
    string adding = "";
   for(size_t i = 0; i<memory_spot_v.size(); ++i){
        memory_spot = memory_spot_v[i];
        memory[toupper(memory_spot)-65]= new mixed(*temp);
        ss<<toupper(memory_spot);
        //memory_spot_v.pop_back();
        adding += memory_spot;
        adding +=", ";
    }
    while(!memory_spot_v.empty()){
       memory_spot_v.pop_back();
    }
    adding.erase(adding.find_last_of(','), adding.size()-1);
    input += adding+ ">";
    isMemoryProcess = false;
    ss.str(string());
    ss.clear();
    return true;
}

bool Parser::throwing_INPUT_ERROR()
{
  cout<<"call throw"<<endl;
  throw INCORECT_INPUT;
  return true;
}
bool Parser::throwing_EMPTY()
{
  throw EMPTYINPUT;
  return true;
}
bool Parser::throwing_MISSING_PAR()
{
  throw MISSING_PARENTHESIS;
  return true;
}
void Parser::isThrowToken(Token * pba){
      pba = NULL;
      throw INCORECT_INPUT;
}
bool Parser::throwing_NO_MEMORY_STORED(){
  memory_spot = temp[temp.size()-1];
   throw NO_MEMORY_STORED;
  return true;
}

void Parser::Add(Token * pba){
  try{
    for(unsigned int i =0; i<=1; ++i){
      (stackTwo[i]->getType()!=TOKEN_FACTION ) && throwing_INPUT_ERROR();
    }
  }
  catch(STACK_ERRORS_LINK_JW e){
    throw INCORECT_INPUT;
  }
  pba = new fraction(
        *(static_cast<fraction*>(stackTwo.pop()))
            +
        *(static_cast<fraction*>(stackTwo.pop()))
        );
  stackTwo.push(pba);
}
void Parser::Min(Token * pba){
  try{
    for(unsigned int i =0; i<=1; ++i){
      (stackTwo[i]->getType()!=TOKEN_FACTION ) && throwing_INPUT_ERROR();
    }
  }
  catch(STACK_ERRORS_LINK_JW e){
    throw INCORECT_INPUT;
  }
  pba = new fraction(
        *(static_cast<fraction*>(stackTwo.pop()))
            -
        *(static_cast<fraction*>(stackTwo.pop()))
        );
  stackTwo.push(pba);
}
void Parser::Mult(Token * pba){
  try{
    for(unsigned int i =0; i<=1; ++i){
      (stackTwo[i]->getType()!=TOKEN_FACTION ) && throwing_INPUT_ERROR();
    }
  }
  catch(STACK_ERRORS_LINK_JW e){
    throw INCORECT_INPUT;
  }
  pba = new fraction(
        *(static_cast<fraction*>(stackTwo.pop()))
            *
        *(static_cast<fraction*>(stackTwo.pop()))
        );
  stackTwo.push(pba);
}
void Parser::Div(Token * pba){
  try{
    for(unsigned int i =0; i<=1; ++i){
      (stackTwo[i]->getType()!=TOKEN_FACTION ) && throwing_INPUT_ERROR();
    }
  }
  catch(STACK_ERRORS_LINK_JW e){
    throw INCORECT_INPUT;
  }
  pba = new fraction(
        *(static_cast<fraction*>(stackTwo.pop()))
            /
        *(static_cast<fraction*>(stackTwo.pop()))
        );
  stackTwo.push(pba);
}
void Parser::Power(Token * pba){
  try{
    for(unsigned int i =0; i<1; ++i){
      (stackTwo[i]->getType()!=TOKEN_FACTION ) && throwing_INPUT_ERROR();
    }
  }
  catch(STACK_ERRORS_LINK_JW e){
    throw INCORECT_INPUT;
  }
  pba = new fraction(
        *(static_cast<fraction*>(stackTwo.pop()))
            ^
        *(static_cast<fraction*>(stackTwo.pop()))
        );
  stackTwo.push(pba);
}
void Parser::Number(Token * pba){
  stackTwo.push(pba);
}
void Parser::READ(string &line){
    int index = 0;
    line.erase(0,1);
           string part1 = line.substr(0, line.find(':'));
           stringstream ss;
           ss<<part1;
           ss>>index;
           line.erase(0, part1.size()+1);
           temp= line;
//           int w;
           int n;
           int d;
            //http://stackoverflow.com/questions/18534036/checking-the-int-limits-in-stoi-function-in-c
           try {
             string placer = temp.substr(0, temp.find('/'));
             n = std::atoi(placer.c_str());
                temp.erase(0, placer.size());
                temp.erase(0, 1);
                temp.erase(temp.size()-1, 1);
                 d = atoi(temp.c_str());
                  memory[index]=new mixed(0, n, d);
           cout <<"number  " << n <<"/"<< d << endl;
           }
                 catch(std::invalid_argument& e){
                   throw INPUT_CANNT_DISPLAY;
                 }
                 catch(std::out_of_range& e){
                   throw INPUT_CANNT_DISPLAY;
                 }catch(fraction_error e){
                   throw DENOM_NEGATIVE;
                 }catch(...) {
                   throw INPUT_CANNT_DISPLAY;
                 }
                 temp="";
           file.close();
           for(unsigned int i=0; i<26; ++i){
               if(memory[i]!=NULL)
                   cout<<i<<": " <<*memory[i]<<endl;
           }
}
bool Parser::writeOutput(){
  return true;
}
void Parser::WRITE(){
  outputFile.open("mapdata.txt");
  for(unsigned int i=0; i<26; ++i){
      (memory[i]!=NULL)&&writeProcess(i);
  }
  outputFile.close();
}
//changed
bool Parser::writeProcess(int i){
    outputFile<<"["<<i<<":"<<(*memory[i]).getNume()<<"/"<<(*memory[i]).getDenom()<<"]"<<std::endl;
    return true;
}

void Parser::run(char type)
{
       (this->*whatToDo[static_cast<int>(type)])();
}


void Parser::printStackOne(){
   stackOne.print();
}
string Parser::printQue(){
     return que.printAlgStr();
}

void Parser::processDec(){

  temp = input.substr(0, input.find_first_of(' '));
  (temp.find('-')!=string::npos && temp.find('(')!=string::npos)&&processNegSign();
  temp = input.substr(0, input.find_first_not_of("-.0123456789"));
(temp.find_first_of('.')!=temp.find_last_of('.'))&&throwing_INPUT_ERROR();
(temp.find_first_of('-')!=temp.find_last_of('-'))&&throwing_INPUT_ERROR();
  Token * t;
//http://stackoverflow.com/questions/20026385/trying-to-convert-a-string-to-double-under-conditions
  try {
      double d = std::stod(temp.c_str());
        t = new fraction(d);
  }
  catch (const std::invalid_argument&) {
      std::cerr << "Argument is invalid\n";
      throw INPUT_CANNT_DISPLAY;
  }
  catch (const std::out_of_range&) {
      std::cerr << "Argument is out of range for a double\n";
      throw INPUT_CANNT_DISPLAY;
  }
  catch(fraction_error e){
        throw DENOM_NEGATIVE;
  }
  catch(...){
    throw INPUT_CANNT_DISPLAY;
  }

  que.enqueue(t);
  stackTwo.push(t);
    temp.erase(temp.size());
  input.erase(0, temp.size());

}

void Parser::processFrac_fra(){
    (temp.find('-')!=string::npos && temp.find('(')!=string::npos)&&processNegSign();
    Token * t;
    try{
          temp = input.substr(0, input.find_first_not_of("-/.0123456789"));
          (temp.find_first_of('-')!=temp.find_last_of('-'))&&throwing_INPUT_ERROR();
          (temp.find_first_of('/')!=temp.find_last_of('/'))&&throwing_INPUT_ERROR();
          string placer = temp.substr(0, temp.find('/'));
          int nom = std::atoi(temp.substr(0, temp.find('/')).c_str());
          temp.erase(0, placer.size()+1);
          temp.erase(temp.size());
          int denom = atoi(temp.c_str());
         (denom<0)&&throwing_INPUT_ERROR();
          t = new fraction(nom, denom);
     }catch(fraction_error e){
        if(e == fraction_overflow)
            throw INPUT_CANNT_DISPLAY;
        if(e == fraction_underflow)
            throw INPUT_CANNT_DISPLAY;
        if(e == fraction_denom_zeor_error)
            throw DENOM_NEGATIVE;
      }
    que.enqueue(t);
    stackTwo.push(t);
    input.erase(0, input.find_first_not_of("-./0123456789 "));
}
bool Parser::spcParser(){
  for(unsigned int i=0; i<temp.size(); i++){
      if(i!=temp.find_first_of(' ')&&temp[i]==' '){
          temp = temp.substr(0, i);
          return true;
        }
  }
  return false;
}

void Parser::processFrac_mixed(){
  (temp.find('-')!=string::npos && temp.find('(')!=string::npos)&&processNegSign();
  Token * t;
  int whole;
  int nom;
  int denom;
//http://stackoverflow.com/questions/18534036/checking-the-int-limits-in-stoi-function-in-c
  try {
    whole = std::stoi(temp.substr(0, temp.find(' ')).c_str());
    temp = temp.substr(temp.find(' ')+1, temp.size()-1);
    string placer = temp.substr(0, temp.find('/'));
    nom = std::stoi(temp.substr(0, temp.find('/')).c_str());
    (nom<0)&&throwing_INPUT_ERROR();
    temp.erase(0, placer.size()+1);
    temp.erase(temp.size());
    denom = stoi(temp.c_str());
    (denom<0)&&throwing_INPUT_ERROR();
    t = new mixed(whole, nom, denom);
  }
  catch(std::invalid_argument& e){
    throw INCORECT_INPUT;
  }
  catch(std::out_of_range& e){
    throw INPUT_CANNT_DISPLAY;
  }catch(fraction_error e){
//    if(e == fraction_overflow)
//        throw INPUT_CANNT_DISPLAY;
//    if(e == fraction_underflow)
//        throw INPUT_CANNT_DISPLAY;
//    if(e == fraction_denom_zeor_error)
        throw DENOM_NEGATIVE;
  }catch(...) {
    throw INCORECT_INPUT;
  }
  que.enqueue(t);
  stackTwo.push(t);
  input.erase(0, input.find_first_not_of("-./0123456789 "));
}

void Parser::processFrac(){

  (this->*whatToDo[
      static_cast<int>('#')
      ]
  )();
  (temp[temp.size()-1]=='-')&&throwing_INPUT_ERROR();
  (this->*whatToDo[
      (temp.find(' ')==string::npos)+7
      ]
  )();
}
//changed
void Parser::isMemory_c_ALL(){
  for(unsigned int i=0; i<26; ++i){
        delete (memory[i]);
         memory[i] = NULL;
  }
   input.erase(0, temp.size());
   temp = "";
}
//changed
void Parser::isMemory_c_single(){
  memory[toupper(temp[temp.size()-1])-65]==NULL&&throwing_NO_MEMORY_STORED();
  delete (memory[toupper(temp[temp.size()-1])-65]);
  memory[toupper(temp[temp.size()-1])-65] = NULL;
   input.erase(0, temp.size());
   temp = "";
}
bool Parser::isMemory_c(){
  string temp = input.substr(0, input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ= "));
  (this->*whatToDo[
      static_cast<int>('#')
      ]
  )();
  (this->*whatToDo[
      (int)(temp == "CLEAR")
      ]
  )();
  return true;
}
//changed
void Parser::isMemory(){
   temp = input.substr(0, input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ= "));
   (this->*whatToDo[
       static_cast<int>('#')
       ]
   )();
   string tempCheck = input.substr(0, input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"));
   (tempCheck.size()>1 && temp.find("CLEAR")==string::npos)&&throwing_INPUT_ERROR();
   (temp.find("CLEAR")!=string::npos)&&isMemory_c();
   (temp.find('=')==string::npos && temp.find_last_of('=')!=3 && temp!="CLEAR" && temp.find("CLEAR")==string::npos)&&processStoreMem();

   (temp.find('=')!=string::npos && temp.find_last_of('=')!=3 && temp.find("CLEAR")==string::npos)&&processStoreMem2();
   //(temp.find("CLEAR")!=string::npos)&&isMemory_c();
}
void Parser::processOnlyNumber_option1(){
  Token * t = new fraction(-1, 1);
  que.enqueue(t);
  stackTwo.push(t);
  t = new Op(TOKEN_OPERATOR, '*');
  stackTwo.push(t);
  stackOne.push(t);
  input.erase(0, 1);
}
bool Parser::processNegSign(){
    //add
    cout<<"call ..."<<endl;
  Token * t = new fraction(-1, 1);
  que.enqueue(t);
  stackTwo.push(t);
  t = new Op(TOKEN_OPERATOR, '*');
  stackTwo.push(t);
  stackOne.push(t);
  input.erase(0, 1);
  temp.erase(0, 1);
  leftP();
  return true;
}
bool Parser::processNegSign2(){
    //add
    cout<<"call ..."<<endl;
  Token * t = new fraction(-1, 1);
  que.enqueue(t);
  stackTwo.push(t);
  t = new Op(TOKEN_OPERATOR, '*');
  stackTwo.push(t);
  stackOne.push(t);

  input.erase(0, 1);
  //temp.erase(0, 1);
  cout<<"input: "<<input<<endl;
  cout<<"temp: "<<temp<<endl;
  //leftP();
  return true;
}
void Parser::processOnlyNumber_option2(){
  (temp.find(" ")!=string::npos)&&reParser2();
  (temp[temp.size()-1]=='-')&&throwing_INPUT_ERROR();
  //http://stackoverflow.com/questions/18534036/checking-the-int-limits-in-stoi-function-in-c
  int x;
  try {
    x = stoi(temp);
  }
  catch(std::invalid_argument& e){
    throw  INCORECT_INPUT;
  }
  catch(std::out_of_range& e){
    throw INPUT_CANNT_DISPLAY;
  }catch(fraction_error e){
        throw DENOM_NEGATIVE;
  }
  catch(...) {
    throw INCORECT_INPUT;
  }
  Token * t = new fraction(std::atoi(temp.c_str()), 1);
  que.enqueue(t);
  stackTwo.push(t);
  input.erase(0, temp.size());
}
void Parser::processOnlyNumber(){
    (temp[temp.size()-1]=='-')&&throwing_INPUT_ERROR();
  (this->*whatToDo[(temp.find("(")!=string::npos && temp[0]=='-') + 17])();
}
void Parser::processNumber(){
  char check = (temp.find('.')!=string::npos)?4:(temp.find('/')!=string::npos && isdigit(temp[temp.find('/')-1])==true)?5:6;
    (temp=="-")&&throwing_INPUT_ERROR();
  (temp[temp.size()-1]=='-')&&throwing_INPUT_ERROR();
  (this->*whatToDo[static_cast<int>(check)])();
}
void Parser::isThrow(){
  throw INCORECT_INPUT;
}
bool Parser::reParser(){
  temp = input.substr(0, input.find_first_not_of(".0123456789 ("));
  return true;
}
bool Parser::reParser3(){
  temp = input.substr(0, input.find_first_not_of("-.0123456789 ("));
  (temp[temp.size()-1]=='-')&&throwing_INPUT_ERROR();
  // (temp.find_first_of('-')!=temp.find_last_of('-'))&&throwing_INPUT_ERROR();
  return true;
}
bool Parser::reParser2(){
  temp = input.substr(0, input.find_first_not_of("-0123456789"));
  (temp[temp.size()-1]=='-')&&throwing_INPUT_ERROR();
   (temp.find_first_of('-')!=temp.find_last_of('-'))&&throwing_INPUT_ERROR();
  return true;
}
void Parser::isNumber(){
    temp = input.substr(0, input.find_first_not_of("-./0123456789 ("));
    //add
    cout<<"..."<<temp<<endl;
    (this->*whatToDo[static_cast<int>('#')])();
    (temp.find('/') && temp.find('-')!=string::npos && temp.find('-')!=0 && temp.find_first_of('-')!=temp.find_last_of('-'))&&reParser3();
    (temp.find('/')!=string::npos && temp.find('-')!=string::npos && temp.find('-')!=0 && temp.find_first_of('-')!=temp.find_last_of('-') && temp.find('-')!=0)&&reParser();
    (temp.find('/')!=string::npos && temp.find('-')!=string::npos && temp.find('-')!=0 && temp.find_first_of('-')!=temp.find_last_of('-'))&&reParser2();
    processNumber();
}
void Parser::isTrimS(){
  while(temp[0]==' '){
      temp.erase(0, 1);
  }
  while(temp[temp.size()-1]==' '){
      temp.erase(temp.size()-1, 1);
  }
}
void Parser::isDec(){
  temp = input.substr(0, input.find_first_not_of(".0123456789 ")-1);
  input.erase(0, input.find_first_not_of(".0123456789 "));
}
void Parser::leftP(){
  Token * t = new Paren(TOKEN_PERENTHESE_LEFE);
  stackOne.push(t);
  stackTwo.push(t);
  input.erase(0, 1);
  temp.erase(0, 1);
}
void Parser::rightP(){
  Token * g;
   Token * t = new Paren(TOKEN_PERENTHESE_RIGHT);
   stackTwo.push(t);

  while(!stackOne.empty() && (g = stackOne.pop())->getType() != TOKEN_PERENTHESE_LEFE){
      que.enqueue(g);
  }
  (stackOne.empty() && g->getType()!= TOKEN_PERENTHESE_LEFE)&&throwing_MISSING_PAR();
  g = NULL;
  input.erase(0, 1);
}
void Parser::operPower(){
  Token * t = new Op(TOKEN_OPERATOR, input[0]);
  stackTwo.push(t);
  while((!stackOne.empty() && stackOne.top()->getType()==TOKEN_OPERATOR)
          &&
        4 < static_cast<Op*>(stackOne.top())->getP())
  {
      que.enqueue(stackOne.pop());

  }
  stackOne.push(t);
  input.erase(0, 1);
}
void Parser::operAdd(){
  Token * t = new Op(TOKEN_OPERATOR, input[0]);
  stackTwo.push(t);
  while((!stackOne.empty() && stackOne.top()->getType()==TOKEN_OPERATOR)
          &&
        2 <= static_cast<Op*>(stackOne.top())->getP())
  {
      que.enqueue(stackOne.pop());

  }

  stackOne.push(t);
  input.erase(0, 1);
}
void Parser::operMin(){
  if(input[1]==' '){
      Token * t = new Op(TOKEN_OPERATOR, input[0]);
      stackTwo.push(t);
          while((!stackOne.empty() && stackOne.top()->getType()==TOKEN_OPERATOR)
                  &&
                2 <= static_cast<Op*>(stackOne.top())->getP())
          {
              que.enqueue(stackOne.pop());

          }

      stackOne.push(t);
      input.erase(0, 1);
  }else{
      cout<<"input: "<<input<<endl;
      cout<<"here"<<endl;

      cout<<"input: "<<input<<endl;
      //here
        (isalpha(input[1])&&this->processNegSign2())?isMemory():isNumber();
  }
}
void Parser::operMult(){
     Token * t = new Op(TOKEN_OPERATOR, input[0]);
     stackTwo.push(t);

     while((!stackOne.empty() && stackOne.top()->getType()==TOKEN_OPERATOR)
             &&
           3 <= static_cast<Op*>(stackOne.top())->getP())
     {
         que.enqueue(stackOne.pop());
     }

     stackOne.push(t);
     input.erase(0, 1);
}
void Parser::operDiv(){
   Token * t = new Op(TOKEN_OPERATOR, input[0]);
   stackTwo.push(t);
   while((!stackOne.empty() && stackOne.top()->getType()==TOKEN_OPERATOR)
           &&
         3 <= static_cast<Op*>(stackOne.top())->getP())
   {
       que.enqueue(stackOne.pop());

   }
  stackOne.push(t);
  input.erase(0, 1);
}
void Parser::isSpace(){
  input.erase(0, 1);
}

string Parser::getUserInput2(string line){
    try{
          input = line;
          size_t resize = (input.size()<2)?3:input.size();
          que.resize(resize*2);
          stackOne.resize(resize*2);
          stackTwo.resize(resize*2);
          memoryDeleteStack.resize(resize*2);
          input.size()==0&&throwing_EMPTY();
          while(input.size()!=0){
                  run(isdigit(input[0])==true?'3':input[0]);
          }
          while(!stackOne.empty()){
              (stackOne.top()->getType() == TOKEN_PERENTHESE_LEFE || stackOne.top()->getType() == TOKEN_PERENTHESE_RIGHT)&&throwing_MISSING_PAR();
              (stackOne.top()->getType() == TOKEN_OPERATOR)&&addQtoSone();
          }
//          validAlg();
          while(!stackTwo.empty())
            stackTwo.pop();
          input = printQue();
          return calReult();
   }catch(INPUT_ERROR e){
      return(this->*errorFptr[e])();
   }catch(fraction_error e){
     return(this->*errorFptr[INPUT_CANNT_DISPLAY])();
   }
}


#endif // PARSER

