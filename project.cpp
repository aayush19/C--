#include <iostream>
#include <fstream>

using namespace std;
/*
Banking Management System
Version        : 0.1
Author         : Prathmesh Ranaut
Created Date   : 21 July 2013
*/
void lines(int count)
{
	for(int j = 0; j < count; j++)
	{
		for(int i = 0; i < 50; i++)
		{
			cout<<"-";
		}
		cout<<endl;
	}
}
void display_records()
{
	fstream f;
	f.open("banking.dat");
}
void insert_record()
{

}
void search_record()
{

}
void dev_info()
{
	lines(1);
	cout<<"Dev Info:\n";
	lines(1);
	cout<<"Software Developer:\n Prathmesh Ranaut\n Class : 12\n";
	lines(1);
}
void generate_menu()
{
	cout<<"Functions available:- \n"<<"1. Display All Accounts\n"<<"2. Make a transaction\n"<<"3. Search an Account\n"<<"4. Add an Account\n"<<"5. Delete an account\n"<<"6. Developer Info\n";
	lines(1);
}
int main(int argc, char *argv[]) {
	/*
	Variables
	*/
	int ch = 0;
	char yn;
	/*
		Function options available
			1. Display All records
			2. Make a transaction
			3. Search and account
			4. Add and Account
			5. Delete an account
			6. Developer Info			
	*/


	//Function that will prints a line with help of dashes
	lines(1);
	//Some welcoming stuff
	cout<<"Welcome to LiquidServe Bank."<<endl;
	//First get the user to select from the available options
	do
	{
		lines(1);
		generate_menu();
		cout<<"Please input the number of the function you would like to call.";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			/*
			Display all Accounts along with details
			*/
			case 1:
			display_records();
			break;

			/*
			Add an account to the database 
			*/
			case 4:
			insert_record();
			break;
			/*
			Search records in File
			*/
			case 3:
			search_record();
			break;
			/*
			Adds an account
			*/
			case 4:
			add_account();
			break;
			/*
			Deletes an account
			*/
			case 5:
			delete_account();
			break;
			/*
			Developer Information
			*/
			case 6:
			dev_info();
			break;
			default:

			break;
		}
		cout<<"Would you like to continue? (y/n)"<<endl;
		cin>>yn;
	}while(yn == 'Y' || yn == 'y');
}