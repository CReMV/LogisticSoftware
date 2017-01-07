#include "ClassesLib.h"
using namespace std;
//Global Variables
int pcount=0,vcount=0,ocount=0,whcount=0;
vector<PersonClass>pc;
vector<WareHouseClass>whc;
vector<FinanceClass>fc;
vector<VehicleClass>vc;
vector<OrderClass>oc;
vector<int>pfound;
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
  //Department Selection
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
  //Sanity Control
  while(selection!=1&&selection!=2&&selection!=3&&selection!=4&&selection!=5&&selection!=6)
   {
   cout<<"The selection you made is not valid!"<<'\n';
   cout<<"Choose the department you want to manage:"<<'\n';
   cout<<"1.Human Resources"<<'\n';
   cout<<"2.Vehicle Fleet"<<'\n';
   cout<<"3.Warehouse Logistics"<<'\n';
   cout<<"4.Order Logistics"<<'\n';
   cout<<"5.Finance Department"<<'\n';
   cout<<"6.Exit"<<'\n';
   cout<<"Selection:";
   cin>>selection;
   }
  //Human Resources
  if(selection==1)
   {
   personmenu();
   }
   //Vehicle Fleet
  else if(selection==2)
   {
   vehiclemenu();
   }
   //Warehouse Logistics
  else if(selection==3)
   {
   warehousemenu();
   }
   //Order Logistics
  else if(selection==4)
   {
   ordermenu();
   }
   //Finance Department
  else if(selection==5)
   {
   financemenu();
   }
   //Exit
  else if(selection==6)
   {
   close=true;
   }
  }
 while(close==false);
 //Check on exit for errors. Will be used later to be sure the garbage collector works.
 return EXIT_SUCCESS;
 }
//Human Resources Menu
void personmenu(void)
 {
 int choice=0;
 bool close=false;
 do
  {
  //Main Menu
  cout<<"!Employee Registry!"<<'\n';
  cout<<"1.Register new employee"<<'\n';
  cout<<"2.Search for employee info"<<'\n';
  cout<<"3.Exit to main menu"<<'\n';
  cout<<"Select:";
  cin>>choice;
  cin.clear();
  cin.ignore(256,'\n');
  //Sanity Control
  while(choice!=1&&choice!=2&&choice!=3)
   {
   cout<<"The selection you made is not valid!"<<'\n'<<"Select:";
   cin>>choice;
   cin.clear();
   cin.ignore(256,'\n');
   }
  //Register Employee
  if(choice==1)
   {
   bool rclose=false;
   do
    {
    char exit;
    void RegisterEmployee();
    RegisterEmployee();
    cout<<"Do you want to add another employee?[Y/N]:";
    cin>>exit;
    cin.clear();
    cin.ignore(256,'\n');
    //Sanity Control
    while(exit!='Y'&&exit!='y'&&exit!='N'&&exit!='n')
     {
     cout<<"Invalid Selection!"<<'\n';
     cout<<"Do you want to add another employee?[Y/N]:";
     cin>>exit;
     cin.clear();
     cin.ignore(256,'\n');
     }
    if(exit=='N'||exit=='n')
     {
     rclose=true;
     }
    else
     {
     rclose=false;
     }
    }
   while(rclose==false);
   }
   //Search Employee
  else if(choice==2)
   {
   bool sclose=false;
   char exit;
   do
    {
    int SearchEmployee();
    int found;
    SearchEmployee();
    }
   while(sclose=false);
   }
   //We go to the next employee or exit the search function if no others are in line by changing the exit flag to true
  else if(choice==3)
   {
   close=true;
   }
  }
 while(close=false);
 }
//Register Employee
void RegisterEmployee()
 {
 char exit;
 cout<<"Fill the employee info below!"<<'\n';
 pc.resize(pcount+1);
 pc[pcount].setFields(pcount);
 pcount++;
 }
//Search Employee
int SearchEmployee()
 {
 bool sclose=false;
 int sfound=0;
 do
  {
  string fstring;
  for(vector<PersonClass>::iterator it=pc.begin();it!=pc.end();it++)
   {
   auto pos=distance(pc.begin(),it);
   string fname,lname;
   fname=pc[pos].getFName();
   lname=pc[pos].getLName();
   for(int i=0;i!=fname.size()-fstring.size()-1;i++)
    {
    if(fstring==fname.substr(i,i+fstring.size()-1))
     {
     sfound=true;
     }
    }
   for(int i=0;i!=lname.size()-fstring.size()-1;i++)
    {
    if(fstring==lname.substr(i,i+fstring.size()-1))
     {
     sfound=true;
     }
    }
   if(sfound==true)
    {
    pfound.push_back(pos);
    sclose=true;
    }
   else
    {
    cout<<"No employees Found!"<<'\n';
    sclose=true;
    }
   }
  }
 while(sclose=false);
 return sfound;
 }
void SearchResults()
 {
 string select;
 for(vector<int>::iterator it=pfound.begin();it!=pfound.end();it++)
  {
  auto position=distance(pfound.begin(),it);
  int sel=0;
  cout<<pc[pfound[position]].getFields()<<'\n';
  cout<<"Do you want to modify this entry?[Y/N/Exit]:";
  cin>>select;
  cin.clear();
  cin.ignore(256,'\n');
  do
   {
   cout<<"Do you want to modify this entry?[Y/N/Exit]:";
   cin>>select;
   cin.clear();
   cin.ignore(256,'\n');
   }
  while(select!="Y"||select!="y"||select!="N"||select!="n");
  if(select=="N"||select=="n")
   {
   continue;
   }
  cout<<"Select Modification:"<<'\n';
  cout<<"1.Delete"<<'\n';
  cout<<"2.Modify"<<'\n';
  do
   {
   cout<<"Invalid Selection!"<<'\n';
   cout<<"Select Modification:"<<'\n';
   cout<<"1.Delete"<<'\n';
   cout<<"2.Modify"<<'\n';
   }
  while(sel<1||sel>3);
  if(sel==1)
   {
   char ssel;
   cout<<"This action can not be reversed!Do you want to continue?[Y/N]";
   cin>>ssel;
   cin.clear();
   cin.ignore(256,'\n');
   do
    {
    cout<<"This selection is invalid!"<<'\n';
    cout<<"This action can not be reversed!Do you want to continue?[Y/N]";
    cin>>ssel;
    cin.clear();
    cin.ignore(256,'\n');
    }
   while(ssel!='Y'||ssel!='y'||ssel!='N'||ssel!='n');
   if(ssel=='Y'||ssel=='y')
    {
    string fname,lname,phone;
    int age;
    for(vector<PersonClass>::iterator k=pc.begin();k!=pc.end();k++)
     {
     auto pos=distance(pc.begin(),k);
     if(pos>=position)
      {
      pc[pos]=pc[pos+1];
      }
     }
    pc.erase(pc.end()-1);
    pcount--;
    }
   }
  else if(sel==2)
   {
   char ssel;
   cout<<"This action can not be reversed!Do you want to continue?[Y/N]";
   cin>>ssel;
   cin.clear();
   cin.ignore(256,'\n');
   do
    {
    cout<<"This selection is invalid!"<<'\n';
    cout<<"This action can not be reversed!Do you want to continue?[Y/N]:";
    cin>>ssel;
    cin.clear();
    cin.ignore(256,'\n');
    }
   while(ssel!='Y'||ssel!='y'||ssel!='N'||ssel!='n');
   string fname;
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
   string lname;
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
   pc[position].setName(fname,lname);
   int age;
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
   pc[position].setAge(age);
   string phone;
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
   pc[position].setPhone(phone);
   }
  }
 pfound.clear();
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