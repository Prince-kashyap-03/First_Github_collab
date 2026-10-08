#include <iostream>
using namespace std;

class ATM
{
private:
	int atmpin = 1;
	int balance = 0;

public:
	int validatePIN()
	{
		int pin;
		cout << "\nEnter your ATM PIN: ";
		cin >> pin;
		if (pin == atmpin)
		{
			return 1;
		}else{
			return 0; 
		}
	}

	void checkBalance()
	{
		cout << "Current balance = " << balance << endl;
	}

	void deposit(int x)
	{
		balance = balance + x;
		cout << "Current balance = " << balance << endl;
	}

	void withdraw(int x)
	{
		if (x <= 0)
		{
			cout << "\n\tInvalid amount." << endl;
			return;
		}
		else if (x > balance)
		{
			cout << "\n\tInsufficient balance." << endl;
			return;
		}
		else
		{
			balance -= x;
			cout << "Withdrawn: " << x << endl;
			cout << "Current balance = " << balance << endl;
		}
	}
};

int main()
{
	ATM a;
	int choice = -1;
	int amount;
	do
	{
		if (a.validatePIN())
		{
			cout << "\nEnter your choice: " << endl;
			cout << "1.Check balance." << endl;
			cout << "2.Deposit." << endl;
			cout << "3.Withdraw." << endl;
			cout << "0.Exit." << endl;
			cout << "\nChoice:";
			cin >> choice;
			switch (choice)
			{
			case 0:
			{
				cout << "\tEXITING...";
				return 1;
			}
			case 1:
			{
				a.checkBalance();
				break;
			}
			case 2:
			{
				cout << "Enter the amount you want to deposit: ";
				cin >> amount;
				a.deposit(amount);
				break;
			}
			case 3:
			{
				cout << "Enter the amount you want to withdraw: ";
				cin >> amount;
				a.withdraw(amount);
				break;
			}
			default:
			{
				cout << "Please enter a valid choice." << endl;
				break;
			}
			}
		}
		else
		{
			cout << "\n\tWRONG PASSWORD." << endl;
		}
	} while (choice != 0);

	return 0;
}
