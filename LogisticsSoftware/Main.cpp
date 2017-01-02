#include "ClassesLib.h"
using namespace std;
//Global Variables
int pcount=0,vcount=0,ocount=0,whcount=0;
vector<PersonClass>pc;
vector<WareHouseClass>whc;
vector<FinanceClass>fc;
vector<VehicleClass>vc;
vector<OrderClass>oc;
//Main Menu
int main(int argc,char *argv[])
 {
 int selection=0;
 bool close=false,intro=true;
 void personmenu();
 void vehiclemenu();
 void ordermenu();
 void warehousemenu();
 void financemenu();
 do
  {
  if(intro==true)
   {
   cout<<"Welcome to the CReMV Logistics Software!"<<'\n';
   intro=false;
   }
  cout<<"Choose the department you want to manage:"<<'\n';
  cout<<"1.Human Resources"<<'\n';
  cout<<"2.Vehicle Fleet"<<'\n';
  cout<<"3.Warehouse Logistics"<<'\n';
  cout<<"4.Order Logistics"<<'\n';
  cout<<"5.Finance Department"<<'\n';
  cout<<"6.Exit"<<'\n';
  cout<<"Selection:";
  cin>>selection;
  cin.clear();
  cin.ignore(256,'\n');
  if(selection==1)
   {
   personmenu();
   }
  else if(selection==2)
   {
   vehiclemenu();
   }
  else if(selection==3)
   {
   warehousemenu();
   }
  else if(selection==4)
   {
   ordermenu();
   }
  else if(selection==5)
   {
   financemenu();
   }
  else if(selection==6)
   {
   close=true;
   }
  }
 while(close==false);
 return EXIT_SUCCESS;
 }
//Human Resources Menu
void personmenu(void)
 {
 int choice=0;
 bool close=false;
 do
  {
  cout<<"!Employee Registry!"<<'\n';
  cout<<"1.Register new employee"<<'\n';
  cout<<"2.Search for employee info"<<'\n';
  cout<<"3.Exit to main menu"<<'\n';
  cout<<"Select:";
  cin>>choice;
  cin.clear();
  cin.ignore(256,'\n');
  while(choice!=1&&choice!=2&&choice!=3)
   {
   cout<<"The selection you made is not valid!"<<'\n'<<"Select:";
   cin>>choice;
   cin.clear();
   cin.ignore(256,'\n');
   }
  if(choice==1)
   {
   bool rclose=false;
   do
    {
    char exit;
    cout<<"Fill the employee info below!"<<'\n';
    pc.resize(pcount+1);
    pc[pcount].setFields(pcount);
    pcount++;
    cout<<"Do you want to add another employee?[Y/N]:";
    cin>>exit;
    cin.clear();
    cin.ignore(256,'\n');
    if(exit=='N'||exit=='n')
     {
     rclose=true;
     }
    }
   while(rclose=false);
   }
  else if(choice==2)
   {
   bool sclose=false;
   do
    {
    bool found=false;
    string fname;
    if(pcount>0)
     {
     vector<int>pfound;
     cout<<"Give the first,last name or part of the name of the employees you want to find: ";
     cin>>fname;
     for(int i=0;i<pcount;i++)
      {
      string sname;
      sname=pc[i].getName();
      for(int j=0;j<sname.size()-fname.size();j++)
       {
       if(fname==sname.substr(j,j+fname.size()))
	{
	pfound.push_back(i);
	found=true;
	}
       }
      }
     if(found==true)
      {
      for(vector<int>::iterator it=pfound.begin();it!=pfound.end();it++)
       {
       char fchoice;
       int pos=pfound[*it];
       cout<<"Employee found!"<<'\n';
       cout<<pc[pos].getFields()<<'\n';
       cout<<"Do you want to modify this entry?[Y/N]:";
       cin>>fchoice;
       while(fchoice!='Y'&&fchoice!='y'&&fchoice!='N'&&fchoice!='n')
	{
	cout<<"Do you want to modify this entry?[Y/N]:";
	cin>>fchoice;
	}
       if(fchoice=='Y'||fchoice=='y')
	{
	int mchoice=0;
	cout<<"Choose the modification you want to make:"<<'\n';
	cout<<"1.Delete"<<'\n';
	cout<<"2.Edit"<<'\n';
	cout<<"3.Exit"<<'\n';
	cout<<"Select:";
	cin>>mchoice;
	while(mchoice!=1&&mchoice!=2&&mchoice!=3)
	 {
	 cout<<"Invalid Selection!"<<'\n';
	 cout<<"Choose the modification you want to make:"<<'\n';
	 cout<<"1.Delete"<<'\n';
	 cout<<"2.Edit"<<'\n';
	 cout<<"3.Exit"<<'\n';
	 cout<<"Select:";
	 cin>>mchoice;
	 }
	if(mchoice==1)
	 {
	 for(int i=pfound[*it];i<pcount-1;i++)
	  {
	  string name,phone;
	  int age;
	  name=pc[pfound[*it+1]].getName();
	  phone=pc[pfound[*it+1]].getPhone();
	  age=pc[pfound[*it+1]].getAge();
	  pc[pfound[*it]].setName(name);
	  pc[pfound[*it]].setPhone(phone);
	  pc[pfound[*it]].setAge(age);
	  for(vector<int>::iterator mit=it+1;mit!=pfound.end();mit++)
	   {
	   pfound[*mit]=pfound[*mit+1];
	   }
	  pfound.erase(pfound.end()-1);
	  }
	 pc.erase(pc.end()-1);
	 pcount--;
	 }
	else if(mchoice==2)
	 {
	 string name,fname,lname,phone;
	 int age;
	 char echoice;
	 name=pc[pfound[*it]].getName();
	 phone=pc[pfound[*it]].getPhone();
	 age=pc[pfound[*it]].getAge();
	 cout<<"Do you want to change the name?[Y/N]:";
	 cin>>echoice;
	 cin.clear();
	 cin.ignore(256,'\n');
	 while(echoice!='Y'&&echoice!='y'&&echoice!='N'&&echoice!='n')
	  {
	  cout<<"Do you want to change the name?[Y/N]:";
	  cin>>echoice;
	  }
	 if(echoice=='Y'||echoice=='y')
	  {
	  cout<<"Give the first name of the person: ";
	  cin>>fname;
	  cin.clear();
	  cin.ignore();
	  int fi=0;
	  while(fi<fname.size())
	   {
	   if((fname[fi]>='A'&&fname[fi]<='Z')||(fname[fi]>='a'&&fname[fi]<='z')&&fname.size()<20&&fname.size()>2)
	    {
	    fi++;
	    }
	   else
	    {
	    cout<<"The first name should be between 1-20 characters long and only have Latin characters!"<<'\n'<<"Give the first name of the person: ";
	    cin>>fname;
	    cin.clear();
	    cin.ignore();
	    fi=0;
	    }
	   }
	  cout<<"Give the last name of the person: ";
	  cin>>lname;
	  cin.clear();
	  cin.ignore();
	  int li=0;
	  while(li<lname.size())
	   {
	   if((lname[li]>='A'&&lname[li]<='Z')||(lname[li]>='a'&&lname[li]<='z')&&lname.size()<20&&lname.size()>2)
	    {
	    li++;
	    }
	   else
	    {
	    cout<<"The last name should be between 1-20 characters long and only have Latin characters!"<<'\n'<<"Give the last name of the person: ";
	    cin>>lname;
	    cin.clear();
	    cin.ignore();
	    li=0;
	    }
	   }
	  name=fname+" "+lname;
	  pc[pfound[*it]].setName(name);
	  }
	 cout<<"Do you want to change the phone?[Y/N]:";
	 cin>>echoice;
	 cin.clear();
	 cin.ignore(256,'\n');
	 while(echoice!='Y'&&echoice!='y'&&echoice!='N'&&echoice!='n')
	  {
	  cout<<"Do you want to change the phone?[Y/N]:";
	  cin>>echoice;
	  }
	 if(echoice=='Y'||echoice=='y')
	  {
	  cout<<"Give the phone of the person: ";
	  cin>>phone;
	  cin.clear();
	  cin.ignore();
	  int pi=0;
	  while(pi<phone.size())
	   {
	   if(phone[pi]>='0'&&phone[pi]<='9'&&phone.size()==10)
	    {
	    pi++;
	    }
	   else
	    {
	    cout<<"The phone should only be numbers and 10 digits long!"<<'\n'<<"Give the phone of the person: ";
	    cin>>phone;
	    cin.clear();
	    cin.ignore();
	    pi=0;
	    }
	   }
	  pc[pfound[*it]].setPhone(phone);
	  cout<<"Do you want to change the age?[Y/N]:";
	  cin>>echoice;
	  cin.clear();
	  cin.ignore(256,'\n');
	  while(echoice!='Y'&&echoice!='y'&&echoice!='N'&&echoice!='n')
	   {
	   cout<<"Do you want to change the age?[Y/N]:";
	   cin>>echoice;
	   }
	  if(echoice=='Y'||echoice=='y')
	   {
	   cout<<"Give the age of the person: ";
	   cin>>age;
	   cin.clear();
	   cin.ignore();
	   while(age<18||age>60)
	    {
	    cout<<"The age should be between 18-60!"<<'\n'<<"Give the age of the person: ";
	    cin >> age;
	    cin.clear();
	    cin.ignore();
	    }
	   }
	  pc[pfound[*it]].setAge(age);
	  }
	 }
	}
       else
	{
	sclose=true;
	}
       }
      }
     }
    else
     {
     cout<<"No employees!"<<'\n';
     sclose=true;
     }
    }
   while(sclose=false);
   }
  else if(choice=3)
   {
   close=true;
   }
  }
 while(close=false);
 }
//Orders Management Menu
void ordermenu()
 {
 bool close=false;
 cout<<"Under Construction!"<<'\n';
 }
//Vehicles Fleet Menu
void vehiclemenu()
 {
 bool close=false;
 cout<<"Under Construction!"<<'\n';
 }
//Finance Department Menu
void financemenu()
 {
 bool close=false;
 cout<<"Under Construction!"<<'\n';
 }
//Warehouse Logistics Menu
void warehousemenu()
 {
 bool close=false;
 cout<<"Under Construction!"<<'\n';
 }