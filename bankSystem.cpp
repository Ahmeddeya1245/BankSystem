#include<iostream>
#include<fstream>
#include<string>
#include<iostream>
#include<fstream>
#include <sstream>
#include<string>
using namespace std; 
struct Account // ستركت لتعريف المتغيرات 
{
	string accountnumber; 
	string name; 
	string password; 
	double balance; 
	Account* next; 

};
class BankManagmentSys
{
private:
	Account* head; 
	string datafile;
public:
	BankManagmentSys()
	{
		head = NULL;
		datafile = "accounts.txt"; 

	}

	
	void addAccount()
	{ 
		Account* newAccount = new Account; // created object from struct  and newaccount points to it 
		cout << "enter Account number : ";
		cin >> newAccount->accountnumber; 
		if(isAccountNumberUnique(newAccount -> accountnumber)) // if accountnumber is repeated 
		{
			cout << "enter name : ";
			cin.ignore(); 
			getline(cin, newAccount->name); 
			cout << "set password : "; 
			cin >> newAccount->password; 
			cout << "enter InitialBalance : "; 
			cin >> newAccount->balance; 
			newAccount->next = NULL; 
			if (head == NULL) // if there is no accounts in the list
			{
				head = newAccount; 
			}
			else
			{
				Account* current = head; 
				while (current->next != NULL) // when there is an existed account
				{
					current = current->next; // current is the next on in the list not the first 
				}
				current->next = newAccount; // which is the new account that will be added
			}
			cout << " Account Added ! " << endl;
			
			
		}
	}
	bool isAccountNumberUnique(const string &accountNumber) // check if the account number is taken  
	{
		Account* current = head; 
		while (current != NULL)
		{
			if (current->accountnumber == accountNumber)
				return false;
			current = current->next;
		}
		return true;
	}
	Account* findaccount(const string& accountnumber, const string& password) 
	{
		Account* current = head;
		while (current != NULL)
		{
			if (current->accountnumber == accountnumber && current->password == password) 
			{
				return current;
			}
			current = current->next; // to find account if its founded return it if its not will return null and check the next
		}
		return NULL;

	}
	void searchAccount()
	{
		string accountnumber; 
		cout << "Enter Account Number "; 
		cin >> accountnumber; 
		string password; 
		cout << "enter password "; 
		cin >> password;
		Account* account = findaccount(accountnumber, password); // enter pass and number to check its founded or not 
		if (account != NULL)
		{
				cout << "AccountNumber" << account->accountnumber << endl; 
		}
		else
		{
				cout << "Account Not founded" << endl; 
		}

	}
	void depositfunds()
	{
		string accountnumber;
		cout << "enter account number :  " << endl;
		cin >> accountnumber;
		string password;
		cout << "enter password" << endl;
		cin >> password;
		Account* account = findaccount(accountnumber, password);
		if (account != NULL)
		{
			double amount;
			cout << "Enter deposit";
			cin >> amount;
			account->balance += amount; // add balance on the amount  
			cout << " deposit succesfully done " << endl;
		
		}
		else
		{
			cout << "Account no found or invalid password " << endl;
		}
	}
	void withdraw()
	{
		string accountnumber;
		cout << "enter account number :  " << endl;
		cin >> accountnumber;
		string password;
		cout << "enter password" << endl;
		cin >> password;
		Account* account = findaccount(accountnumber, password);
		if (account != NULL)
		{
			double amount;
			cout << "enter withdraw ammount ";
			cin >> amount;
			if (account->balance >= amount)
			{
				account->balance -= amount;
				cout << "Withdraw successfull" << endl; // same like deposit but we subtract from the balance
				
			}

			else
			{
				cout << "insufficiant funds " << endl;
			}
		}
	
		else
		{
		cout<<"Account no found or invalid password " << endl;
		}
	}
	void displayaccounts()
	{
		cout << "All Accounts " << endl; 
		Account* current = head; 
		while (current != NULL)
		{
			cout << "\n Account Number : " << current->accountnumber << endl; 
			cout << "Name : " << current->name << endl;
			cout << "Balance : " << current->balance << endl; 
	
		current = current->next; 
		}
		cout << endl; 
	}
	void deleteAccount()
	{
		string accountnumber;
		cout << "enter account number :  " << endl;
		cin >> accountnumber;
		string password;
		cout << "enter password" << endl;
		cin >> password;
		if (head == NULL)
		{
			cout << "there is no accounts to delete" << endl ; 
			return; 
		}
		if (head->accountnumber == accountnumber && head->password == password)
		{
			Account* temp = head; 
			head = head->next;
			delete temp; 
			cout << "Acount deleted successfully" << endl; 
			return;
		}
	}
};
int main()
{
	string accountnumber;
	string name;
	string password;
	double balance;
	BankManagmentSys b; 
	int x; 
	while (true)
	{
		cout << "                                                Welcome To our Organization " << endl;
		cout << "                                                ___________________________ " << endl << endl;
		cout << "Please choose the the service you need by choosing the number...." << endl << endl;
		cout << "0-Exit" << endl;
		cout << "1-Create Account" << endl;
		cout << "2-Delete Account" << endl;
		cout << "3-Deposit Account" << endl;
		cout << "4-Withdraw Account" << endl;
		cout << "5-Check Account is founded" << endl;
		cout << "6-display" << endl;
		cout << endl;
		cin >> x;
		switch (x)
		{
		case 1:
			b.addAccount();
			break;
		case 2:
			b.deleteAccount();
			break;
		case 3:
			b.depositfunds();
			break;
		case 4:
			b.withdraw();
			break;
		case 5:
			b.searchAccount(); 
			break;
		case 6:
			b.displayaccounts();
			break;
		case 0:
			return false; 
			break;
		}
	}
}

