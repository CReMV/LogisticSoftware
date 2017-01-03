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
    else if(exit=='Y'||exit=='y')
     {
     rclose=false;
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
    //If check in order to ensure no errors occur when there are no employees
    if(pcount>0)
     {
     //Vector that saves the index of the found employees
     vector<int>pfound;
     cout<<"Give the first,last name or part of the name of the employees you want to find: ";
     cin>>fname;
     //Here I use the Boyer-Moore search algorithm,basically the search info we gave is compared to a substring of the full name
     //That is the same size as the info we provided in terms of characters, after that we move it till it is compared with the last
     //substring that it is possible to create from the name
     for(int i=0;i<pcount;i++)
      {
      //We get the name of the employee we want to find
      string sfname,slname;
      bool ffound=false,lfound=false;
      sfname=pc[i].getFName();
      slname=pc[i].getLName();
      //Since we want the substring to be the same size us our info we only go up to the max string size - the size of the info provided
      //That way we got the last characters we need for full sized substring since there will be leftover characters
      for(int j=0;j<sfname.size()-fname.size()+1;j++)
       {
       //Now we check from the character position we are in plus with the same number of characters the info have
       if(fname==sfname.substr(j,j+fname.size()-1))
	{
	//We raise the found boolean flags
	ffound=true;
	}
       }
      for(int j=0;j<slname.size()-fname.size()+1;j++)
       {
       //Now we check from the character position we are in plus with the same number of characters the info have
       if(fname==slname.substr(j,j+fname.size()-1))
	{
	//We raise the found boolean flags
	lfound=true;
	}
       }
      if(ffound==true||lfound==true)
       {
       found=true;
       //After an employee is found it is added to the index list we made before to store our found employees compactly
       pfound.push_back(i);
       }
      }
     //Since we have found our employees we go to the option of if we want to change their info or delete them after their info
     //Have been displayed one after another
     if(found==true)
      {
      cout<<"Employee(s) found!"<<'\n';
      //We use the iterator to get from the 1st index position of found employees in sequential order as they have been found
      //To the next employee and so on till we go through them all
      for(vector<int>::iterator it=pfound.begin();it!=pfound.end();it++)
       {
       char fchoice;
       //By using the special symbol * we get the content of the memory block that the iterator points to since an iterator
       //Basically works like a memory pointer, we do that because pfound can't be used itself as the employee vector's index
       int pos=pfound[*it];
       //We use the PersonClass function getFields that prints all the info of the object on the screen
       cout<<pc[pos].getFields()<<'\n';
       //Modification Verification
       cout<<"Do you want to modify this entry?[Y/N]:";
       cin>>fchoice;
       //Sanity Control
       while(fchoice!='Y'&&fchoice!='y'&&fchoice!='N'&&fchoice!='n')
	{
	cout<<"Do you want to modify this entry?[Y/N]:";
	cin>>fchoice;
	}
       if(fchoice=='Y'||fchoice=='y')
	{
	//The modification choices provided to the user
	int mchoice=0;
	cout<<"Choose the modification you want to make:"<<'\n';
	cout<<"1.Delete"<<'\n';
	cout<<"2.Edit"<<'\n';
	cout<<"3.Exit"<<'\n';
	cout<<"Select:";
	cin>>mchoice;
	//Sanity Control
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
	//Delete Employee
	if(mchoice==1)
	 {
	 //Since after deleting an employee we no longer need the last element of the vector that includes a now empty employee card
	 //We only go up to the second from the end position that is pcount(The total number of employees) - 1 and start from the employee
	 //We are deleting
	 for(int i=pfound[*it];i<pcount-1;i++)
	  {
	  string fname,lname,phone;
	  int age;
	  //1st we get the info from the next employee and transfer it to the position we are removing an employee from
	  fname=pc[pfound[*it+1]].getFName();
	  lname=pc[pfound[*it+1]].getLName();
	  phone=pc[pfound[*it+1]].getPhone();
	  age=pc[pfound[*it+1]].getAge();
	  //And set it as the deleted employee's new info to replace it with the next one
	  pc[pfound[*it]].setName(fname,lname);
	  pc[pfound[*it]].setPhone(phone);
	  pc[pfound[*it]].setAge(age);
	  //After that we remove the position from the found vector and move the vector elements one position backwards in line
	  for(vector<int>::iterator mit=it+1;mit!=pfound.end();mit++)
	   {
	   pfound[*mit]=pfound[*mit+1];
	   }
	  //Then we delete the last element since it is unneeded
	  pfound.erase(pfound.end()-1);
	  }
	 //Then we delete the last element of the employees vector since it is now a useless duplicate
	 pc.erase(pc.end()-1);
	 //We reduce the max amount of employees by one
	 pcount--;
	 }
	else if(mchoice==2)
	 {
	 string name,fname,lname,phone;
	 int age;
	 char echoice;
	 //Extracts the info of the employee so they can be left intact from changes later on
	 name=pc[pfound[*it]].getFName();
	 phone=pc[pfound[*it]].getPhone();
	 age=pc[pfound[*it]].getAge();
	 //Name Change
	 cout<<"Do you want to change the name?[Y/N]:";
	 cin>>echoice;
	 cin.clear();
	 cin.ignore(256,'\n');
	 //Sanity Control
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
	  //Sanity Control: Checks the whole string for numerical/special characters and a maximum size of 20 and minimum of 2 so names only include letters
	  while(fi<fname.size())
	   {
	   //Basically we only go forward in the loop if no illegal character is found in the string till this point
	   if((fname[fi]>='A'&&fname[fi]<='Z')||(fname[fi]>='a'&&fname[fi]<='z')&&fname.size()<20&&fname.size()>2)
	    {
	    fi++;
	    }
	    //If one is found the check is reset
	    //We use the same algorithm for the last name and phone as well
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
	  //Sanity Control: Checks the whole string for numerical/special characters and a maximum size of 20 and minimum of 2 so names only include letters
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
	  pc[pfound[*it]].setName(fname,lname);
	  }
	 //Phone Change
	 cout<<"Do you want to change the phone?[Y/N]:";
	 cin>>echoice;
	 cin.clear();
	 cin.ignore(256,'\n');
	 //Sanity Control
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
	  //Since the phone is a string in order to have the country code as well we need a check to ensure only numeric characters are included
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
	  //Age Change
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
     else if(found==false)
      {
      cout<<"No employees found!"<<'\n';
      }
     }
     //If no employees are registered it exits here after turning the loop exit flag to true
    else
     {
     cout<<"No employees!"<<'\n';
     sclose=true;
     }
    }
   while(sclose=false);
   }
   //We go to the next employee or exit the search function if no others are in line by changing the exit flag to true
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