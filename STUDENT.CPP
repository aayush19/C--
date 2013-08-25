#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
fstream f;
class student
{
 int admno;
 char name[20];
 char mobile[11];
 char email[30];
 public:
  student() {admno=0;
	strcpy(name,NULL);
	strcpy(mobile,NULL);
	strcpy(email,NULL);
	}
   void getd();
   void show();
   int retadmno() {return admno;}
   char *retname() {return name;}
     ~student(){};
  }s;
  void student::getd()
  {
  cin>>admno; gets(name); gets(mobile); gets(email);
  }

  void student::show()
  {
   cout<<admno<<" "<<name<<" "<<mobile<<" "<<email<<endl;
    }

    void searchbyadmno()
    {
    int a; int flag=0;
    cout<<"enter admission no to be searched:";
    cin>>a;
    f.open("stud.dat",ios::in);
    while(f.read((char*)&s, sizeof(s)))
    {
     if(s.retadmno()==a)
     { s.show();
     flag++;
     }
     }
     if(flag==0)
     cout<<"No such record exists";
    f.close();

    }
    void searchbyname()
    {
    char n[20]; int flag=0;
    cout<<"enter name to be searched:";
    gets(n);
    f.open("stud.dat",ios::in);
    while(f.read((char*)&s, sizeof(s)))
    {
     if(strcmpi(s.retname(),n)==0)
     { s.show();
     flag++;
     }
     }
     if(flag==0)
     cout<<"No such record exists";
    f.close();

    }
    void main()
    {

    char ch;
     do{
     clrscr();
     cout<<"1. Add data \n2. Display all \n3. Search";
     int c;
     cout<<"\nEnter ur choice:";
     cin>>c;
     switch(c)
     {
      case 1:   s.getd();

		f.open("stud.dat",ios::binary | ios::app);
		f.write((char*)&s, sizeof(s));
		f.close();
		break;
      case 2:   f.open("stud.dat",ios::in);
		while(f.read((char*)&s, sizeof(s)))
		{s.show();
		 }
		 f.close();
		break;
      case 3:   cout<<"1. Search by admno \n2. Search by name";
		cout<<"\nEnter your choice:";
		int n;
		cin>>n;
		switch(n)
		{
		 case 1: searchbyadmno();
		 break;
		 case 2: searchbyname();
		 break;
		}
		break;

     }

     cout<<"Wish to continue (y/n):";cin>>ch;
     }while(ch=='y' ||ch=='Y');
     getch();
     }






