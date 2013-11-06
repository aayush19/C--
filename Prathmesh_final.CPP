#include <fstream.h>
#include <ctype.h>
#include <iomanip.h>
#include <conio.h>
#include <stdio.h>

/*
	This class will handle all the details related to a persons account
*/

class account
{
	int account_no;
	char name[50];
	int deposit;
	char type; 		// saving(S) or current(C)
	
	public:
		/*
			Creates a new account for the User
		*/
		void create_account()
		{
			cout<<"\n Enter an account number(We let you choose the account number of your choice) : ";
			cin>>account_no;
			account_no = (int)account_no;
			cout<<"\n Enter the name of account holder : ";
			gets(name);		//We use this cause of the evil spaces!
			do
			{
				cout<<"\n Enter type of account (C/S) : ";
				cin>>type;
				
				type = toupper(type);
				//Handling Idiot people!
				switch(type)
				{
					case "C":
					case "S":
					break;
					default:
					cout<<"Seriously! Do I have to repeat?"
					break;
				}
			}while(type != "C" || type != "S");
			cout<<"\nEnter the initial deposit amount";
			cin<<deposit;
			cout<<"\nAccount Created";
		}
		/*
			Displays the account details for the given 
		*/
		void display_account()
		{
			cout<<"\nAccount No. : "<<account_no;
			cout<<"\nAccount Holder Name : "<<name;
			cout<<"\nType of Account : "<<type;
			cout<<"\nBalance Amount : "<<deposit;
		}
		/*
			Modifies the account info
		*/
		void modify()
		{
			cout<<"\nNew Account No."<<account_no;
			account_no = (int)account_no;
			cout<<"\n Enter the name of account holder : ";
			gets(name);		//We use this cause of the evil spaces!
			do
			{
				cout<<"\n Enter type of account (C/S) : ";
				cin>>type;
				
				type = toupper(type);
				//Handling Idiot people!
				switch(type)
				{
					case "C":
					case "S":
					break;
					default:
					cout<<"Seriously! Do I have to repeat?"
					break;
				}
			}while(type != "C" || type != "S");
			cout<<"\nEnter the account balance:";
			cin<<deposit;
		}
		/*
			Deposit into bank account
				@params: 
						(int) amount => The amount of money deposited
		*/
		void deposit(int amount)
		{
			deposit += amount;
		}
		/*
			Withdraw from the bank!
				@params:
						(int) amount => The amount of money which will get withdrawn
		*/
		void withdraw(int amount)
		{
			deposit -= amount;
		}
		/*
			Generates a report for all the bank managers to see all accounts at one glance!
		*/
		void generate_report()
		{
			cout<<account_no<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
		}
		/*
			Getters/Mutators whatever you may call them!
		*/
		int get_account_no()
		{
			return account_no;
		}

		int get_deposit()
		{
			return deposit;
		}

		char get_type()
		{
			return type;
		}
};
/* End of class! */

/*
	Prototypes
*/
void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);

int main()
{
	char ch;
	int num;
	do{
		clrscr();
		switch(ch)
		{
			case 1:
				write_account();
		}
	}while(ch!=8);
}