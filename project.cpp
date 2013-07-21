#include <iostream>
#include <fstream>

using namespace std;

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
	
}
void insert_record()
{
	
}
void search_record()
{
	
}
void dev_info()
{
	cout<<"Dev Info";
}
void generate_menu()
{
	cout<<"Functions available:- \n"<<"1. Display All Records\n"<<"2. Insert a Record\n"<<"3. Search a Record\n"<<"4. Developer Info\n";
}
int main(int argc, char *argv[]) {
	/*
		Variables
	*/
	int ch = 0;
	
	/*
		Function options available
		1. Display All records
		2. Insert a record
		3. Search a record
		4. Developer Information
	*/
	
	
	//Function that will prints a line with help of dashes
	lines(1);
	//Some welcoming stuff
	cout<<"Welcome to a program by Prathmesh Ranaut"<<endl;
	lines(1);
	generate_menu();
	cout<<"Please input the number of the function you would like to call.";
	cin>>ch;
	cout<<endl;
	//First get the user to select from the available options
	switch(ch)
	{
		/*
			Display all records
		*/
		case 1:
			display_records();
			break;
		case 2:
			insert_record();
			break;
		case 3:
			search_record();
			break;
		case 4:
			dev_info();
			break;
		default:

			break;
	}
}