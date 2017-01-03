#ifndef PERSONCLASS_H
#define PERSONCLASS_H
#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
#include <limits>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;
class PersonClass
 {
private:
 string fname,lname,phone,address,amka,b_account;
 int age,v_hour,s_hour;
 double rate;
 string myConvert(int x)
  {
  ostringstream convert;
  convert<<x;
  return convert.str();
  }
public:
 string f_name,l_name,c_phone;
 int c_age;
 void setFields(int);
 string getFields();
 string getFName();
 string getLName();
 string getPhone();
 int getAge();
 void setName(string,string);
 void setPhone(string);
 void setAge(int);
 };
class OrderClass
 {
private:
 map<int,string> ord_content;
 int ord_id;
 string myConvert(int x)
  {
  ostringstream convert;
  convert<<x;
  return convert.str();
  }
public:
 };
class VehicleClass
 {
private:

public:
 };
class FinanceClass
 {
private:

public:
 };
class WareHouseClass
 {
private:

public:
 };
#endif

