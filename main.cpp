#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct patient
{
    /*now we will have many patient that all of them have
    the same information so we need stact to use the same
     information for many patients*/
    long long ID;   // the firstname , Id ,lastname,age
	string firstname;//bloo and gender will be the data.
	string lastname;
	int age;
	char blood[5];
	char gender;
    patient*next; // we the use the patient here as Node
    // so Node have to mention to "next"
};
class linkedqueue
{
	patient *head,*last;
	public:
	linkedqueue() //constructor
	{
		head=NULL;
		last=NULL;
	}
    patient input();
    void insertatend(); // add patient
    void insertatbeg(); //if there is the critically patient, get it first
    void getpatientout(); // Remove patient
    void listofpatients(); //Display list of patients
    int search(int);// Search about specific patient
    char departmentname[50]; // array of all depatments'names
};
int readnumber()
{
   char b[20];
   cin.getline(b, sizeof(b));
   return atoi(b);
}

patient linkedqueue :: input() //taking input of the patient1353
{
    int flag=0;
   patient *p=new patient();
   cout << "\n\tPlease enter data for patient\n";
   cout<<"\n\tFirst name     : ";
   getline(cin,p->firstname);
   cout << "\tLast name      : ";
   getline(cin,p->lastname);
   again :
   cout << "\tBlood Group    : ";
   cin>>p->blood;
   if((strcmp(p->blood,"A+")==0)||(strcmp(p->blood,"a+")==0)||(strcmp(p->blood,"A-")==0)||(strcmp(p->blood,"a-")==0)||
      (strcmp(p->blood,"B+")==0)||(strcmp(p->blood,"b+")==0)||(strcmp(p->blood,"B-")==0)||(strcmp(p->blood,"b-")==0)||
      (strcmp(p->blood,"O+")==0)||(strcmp(p->blood,"o+")==0)||(strcmp(p->blood,"O-")==0)||(strcmp(p->blood,"o-")==0)||
      (strcmp(p->blood,"AB+")==0)||(strcmp(p->blood,"ab+")==0)||(strcmp(p->blood,"AB-")==0)||(strcmp(p->blood,"ab-")==0))
             flag=1;
    if(flag==0)
    {
        cout<<"\nWrong Entry...Enter a valid Blood Group..Try Again..";
        goto again;

    }
   cout<<"\tGender           : (m/f)";
   cin>>p->gender;
   cout<<"\tAge              : ";
   cin>>p->age;
   cout<<"\tMobile number    : ";
   cin>>p->ID;//=readnumber()1353;

	return *p;
}

void output(patient *p)
{
	cout<<"\n**********************************";
	cout<<"\n\nPatient data:";
	cout<<"\n\nFirst Name       : "<<p->firstname;
	cout<<"\nLast Name          : "<<p->lastname;
	cout<<"\nGender             : "<<p->gender;
	cout<<"\nAge                : "<<p->age;
	cout<<"\nBlood Group        : "<<p->blood;
	cout<<"\nMobile Number      : "<<p->ID;
	cout<<"\n\n**********************************";
}
void linkedqueue :: insertatbeg()
{
     patient*p=new patient();// Creat the new Node in the memory.
     *p=input();// we add in that new Node the data from input funcation
     if(p->ID==0)
     return;

     if(head==NULL)// that means that list is empty

     {
         head=p;// that special casse that new Node the first Node is added
         last=p;// So the last and head mention to this Node
         p->next=NULL;//beacuse it is the last node
     }
     else
     {
        p->next=head; // the adress of the new node mention to head
        head=p; // head mention to the new node
     }
     system("cls");
     cout << "\n\tPatient added:";
     output(p);
}
void linkedqueue:: insertatend()
{
     patient*p=new patient();// Creat the new Node in the memory
     *p=input();//we add in that new Node the data from input funcation
     if(p->ID==0)
     return;

     if(head==NULL)// that means list is Empty
     {
     	head=p; // that special casse that new Node the first Node is added
        last=p;// So the last and head mention to this Node
        p->next=NULL; //beacuse it is the last node
     }
     else
     {
     	p->next=NULL;
        last->next=p; //the last node mention the new one
        last=p; // last  mention to now node
     }
     system("cls");
     cout << "\n\tPatient added:";
     output(p);
}
void linkedqueue :: getpatientout()
{
	 system("cls");
     if(head==NULL)
     {
     	cout<<"\n\tNo Patient to operate"; // the list is empty
     }
     else
     {
     	patient*p=new patient();
     	p=head; // the p helps us to delete the element that finished
     	head=head->next; //head mention the next element
 	    cout << "\n\tPatient to operate:";
        output(p);
 	 }
}

void linkedqueue :: listofpatients()
{
     if(head==NULL)// the list is empty , no data founded
     {
     	cout<<"\n\tNo patient";
 	 }
     patient*p=new patient;
     p=head;
     while(p!=NULL)// there are patients
     {
        cout<<"\nPatient data:";
		cout<<"\nFirst Name       : "<<p->firstname;
		cout<<"\nLast Name        : "<<p->lastname;
		cout<<"\nGender           : "<<p->gender;
        cout<<"\nAge              : "<<p->age;
        cout<<"\nBlood Group      : "<<p->blood;
		cout<<"\nMobile Number    : "<<p->ID;
		cout<<"\n**********************************\n";
        p=p->next;//mention to next one
     }
     cout<<"\n";
}


void departmentmenu (linkedqueue * q)
{
    int choice = 0, success;
    patient p;
    while (choice != 5)
	{
    system("cls");
	cout<<"\n\n\tWelcome To Department : " << q->departmentname;
	cout<<"\n\t\t[1] Add normal patient\n";
	cout<<"\t\t[2] Add critically ill patient\n";
	cout<<"\t\t[3] Take patient to Doctor\n";
	cout<<"\t\t[4] Display list\n";
	cout<<"\t\t[5] Change department or exit\n";
	cout<<"\n\tPlease enter your choice : ";
	choice=readnumber();

    switch (choice)
	{
	  case 1:	q->insertatend();
				cout << "\n\tPress any key";
	    		_getch();
	 			break;

      case 2:	q->insertatbeg();
	    		cout << "\n\tPress any key";
	    		_getch();
				break;

      case 3:	q->getpatientout();
	 			cout<<"\n\tPress any key";
     			_getch();
	      		break;

      case 4:	system("cls");
	 			q->listofpatients();
	 			cout<<"\n\tPress any key";
	 			_getch();
				break;
	 }
    }
}
int mainbage()
{
    int i, choice = 0;
	linkedqueue departments[4];
	while(choice!=5)
	{
		strcpy(departments[0].departmentname,"General Clinic\n");
		strcpy(departments[1].departmentname,"Heart Clinic\n");
		strcpy(departments[2].departmentname,"Lung Clinic\n");
		strcpy(departments[3].departmentname,"Plastic Surgery\n");
		system("cls");
		cout<<"\n\t>>>>>>>>>>>>>>>>>>>>>>>>>>";
		cout<<"\n\tHOSPITAL MANAGEMENT SYSTEM\t";
		cout<<"\n\t<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
		for (i = 0; i < 4; i++)
		{
			cout<<"\t"<<(i+1)<<": "<<departments[i].departmentname;
		}
		cout<<"\t5: Exit";
		cout<<"\n\n\tPlease enter your choice : ";
		choice=readnumber();
		if(choice>=1 && choice<=4)
		{
			departmentmenu(&departments[choice-1]);
		}

	}
	if(choice==5)
	cout<<"\n\t\tThanks \n";
	exit(0); //system end cp
}



class three
{
	public:
		void total()
      {
      		long userId; //for user id of administrator

			d:
			cout<<"\n\n\n\n\n\n\n\n\t\t\t\---------------------";
			cout<<"\n\t\t\t\ Enter Login Id = ";
			cin>>userId;
			cout<<"\t\t\t\---------------------";
			if(userId!=1907)
			{
				cout<<"\n\t\t\t\Don't try to be smart.....Enter correct id\n";
                system("PAUSE");
                system("CLS");
				goto d;
			}
			else
			z:
			string pass="sara";  //password
			string pass="";  //empty string
			char c;
				cout<<"\n\n\n\t\t\t\Password = ";
				p:
				c=_getch();
				cout<<"*";   //for printing * instead for password
				if(c!=13)
				{
					pass=pass+c;//for concatenating the string
					goto p;
				}

      			{
      			if(pass== pass)
      			{
      				cout<<"\n\n\t\t\ Access Granted. Welcome to our HOSPITAL MANAGEMENT SYSTEM \n\n\n";
      				system("PAUSE");
      				system("CLS");
      				mainbage();
				}
				else
				{
				cout<<"\nWrong Password\n";
                system("PAUSE");
                system("CLS");
				goto z;
				}
			}
		}
};



int main ()
{
    system("COLOR 5F");
    three ob;
    ob.total();
    _getch();

}


