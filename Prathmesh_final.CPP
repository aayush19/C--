#include <fstream.h>
#include <ctype.h>
#include <iomanip.h>
#include <conio.h>
#include <stdio.h>

/*
	This class will handle all the details related to a persons account
*/

class Account
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
void balance_enquiry(int);
void modify_account(int);
void close_account(int);
void transaction(int, int);
void generate_list();

int main()
{
	char ch;
	int account_number;
	do{
		clrscr();
		display_menu();
		cin>>ch;
		switch(ch)
		{
			case 1:
				write_account();
			break;
			case 2:
				cout<<"\n\tEnter account number:";
				cin>>account_number;
				balance_enquiry(account_number);
			break;
			case 3:
				cout<<"\n\tEnter account number:";
				cin>>account_number;
				//1 => deposit
				transaction(account_number, 1);
			break;
			case 4:
				cout<<"\n\tEnter account number:";
				cin>>account_number;
				//1 => withdraw
				transaction(account_number, 2);
			break;
			case 5:
				cout<<"\n\tEnter account number:";
				cin>>account_number;				
				modify_account(account_number);
			break;
			case 6:
				cout<<"\n\tEnter account number:";
				cin>>account_number;				
				close_account(account_number);
			break;
			case 7:				
				generate_list();
			break;
		}
	}while(ch!=8);
	return 0;
}
/*
	Displays the menu for the app
*/
void display_menu()
{
	cout<<"\n\tMain Menu";
	cout<<"____________________________________";
	cout<<"\n\t1. Create a new account";
	cout<<"\n\t2. Balance Enquiry";
	cout<<"\n\t3. Deposit Amount";
	cout<<"\n\t4. Withdraw Amount";
	cout<<"\n\t5. Modify an existing account";
	cout<<"\n\t6. Close an account";
	cout<<"\n\t7. Generate account list";
	cout<<"\n\t8. Exit";
	cout<<"Select an option from 1 to 8";
	
}
/*
	Writes an account
*/
void write_account()
{
	Account a;
	ofstream o;
	o.open("account.dat", ios::binary|ios::app);
	a.create_account();
	o.write((char *) &a, sizeof(Account));
	o.close();
}
/*
	Gets the balance of the user
		@params:
				(int) account_no => Account number of the person
*/
void balance_enquiry(int account_no)
{
	Account a;
	int flag=0;
	ifstream i;
    ii.open("account.dat",ios::binary);
	if(!i)
	{
		cout<<"File could not be opened!! Press any key to continue...";
		return;
	}
	cout<<"\nBalance Details \n";
	
    while(i.read((char *) &a, sizeof(Account)))
	{
		if(a.get_account_no()==account_no)
		{
			a.display_account();
			flag=1;
		}
	}
    i.close();
	if(flag==0)
		cout<<"\n\nAccount number does not exist";
}
void modify_account(int n)
{
	int found=0;
	account ac;
	fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.get_account_no()==n)
		{
			ac.display_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*sizeof(account);
			File.seekp(pos,ios::cur);
		    File.write((char *) &ac, sizeof(account));
		    cout<<"\n\n\t Record Updated";
		    found=1;
		  }
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}

void close_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.get_account_no()!=n)
		{
			outFile.write((char *) &ac, sizeof(account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
}

void generate_list()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"====================================================\n";
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}

void transaction(int n, int option)
{
	int amt;
	int found=0;
	account ac;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.get_account_no()==n)
		{
			ac.display_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw";
				cin>>amt;
				int bal=ac.get_deposit()-amt;
				if((bal<500 && ac.get_type()=='S') || (bal<1000 && ac.get_type()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)* sizeof(ac);
			File.seekp(pos,ios::cur);
			File.write((char *) &ac, sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=1;
	       }
	 }
    File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}