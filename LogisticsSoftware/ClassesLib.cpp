#ifndef _CLASSESLIB_H_
#define _CLASSESLIB_H_
#include "ClassesLib.h"
using namespace std;
//PersonClass Functions
void PersonClass::setFields(int k)
 {
 cout<<"Give the first name of the person: ";
 cin>>f_name;
 cin.clear();
 cin.ignore();
 int fi=0;
 while(fi<f_name.size())
  {
  if((f_name[fi]>='A'&&f_name[fi]<='Z')||(f_name[fi]>='a'&&f_name[fi]<='z')&&f_name.size()<20&&f_name.size()>2)
   {
   fi++;
   }
  else
   {
   cout<<"The first name should be between 1-20 characters long and only have Latin characters!"<<'\n'<<"Give the first name of the person: ";
   cin>>f_name;
   cin.clear();
   cin.ignore();
   fi=0;
   }
  }
 cout<<"Give the last name of the person: ";
 cin>>l_name;
 cin.clear();
 cin.ignore();
 int li=0;
 while(li<l_name.size())
  {
  if((l_name[li]>='A'&&l_name[li]<='Z')||(l_name[li]>='a'&&l_name[li]<='z')&&l_name.size()<20&&l_name.size()>2)
   {
   li++;
   }
  else
   {
   cout<<"The last name should be between 1-20 characters long and only have Latin characters!"<<'\n'<<"Give the last name of the person: ";
   cin>>l_name;
   cin.clear();
   cin.ignore();
   li=0;
   }
  }
 name=f_name+" "+l_name;
 cout<<"Give the age of the person: ";
 cin>>c_age;
 cin.clear();
 cin.ignore();
 while(c_age<18||c_age>60)
  {
  cout<<"The age should be between 18-60!"<<'\n'<<"Give the age of the person: ";
  cin >> c_age;
  cin.clear();
  cin.ignore();
  }
 age=c_age;
 cout<<"Give the phone of the person: ";
 cin>>c_phone;
 cin.clear();
 cin.ignore();
 int pi=0;
 while(pi<c_phone.size())
  {
  if(c_phone[pi]>='0'&&c_phone[pi]<='9'&&c_phone.size()==10)
   {
   pi++;
   }
  else
   {
   cout<<"The phone should only be numbers and 10 digits long!"<<'\n'<<"Give the phone of the person: ";
   cin>>c_phone;
   cin.clear();
   cin.ignore();
   pi=0;
   }
  }
 phone=c_phone;
 }
string PersonClass::getFields()
 {
 cout<<"Full Name: "+name+", Age: "+myConvert(age)+", Phone: +30"+phone;
 return "";
 }
void PersonClass::setName(string x)
 {
 name=x;
 }
void PersonClass::setPhone(string x)
 {
 phone=x;
 }
void PersonClass::setAge(int x)
 {
 age=x;
 }
string PersonClass::getName()
 {
 return name;
 }
string PersonClass::getPhone()
 {
 return phone;
 }
int PersonClass::getAge()
 {
 return age;
 }
//OrderClass Functions
//VehicleClass Functions
//WareHouseClass Functions
//FinanceClass Functions
#endif
