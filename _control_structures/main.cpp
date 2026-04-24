#include <iostream>

int main(void)
{
	double account_balance;
	std::cout << "enter account balance: ";
	std::cin >> account_balance;

	do {
		double withdraw_amount;
		std::cout << "enter withdrawal amount (0000 to quit): ";
		std::cin >> withdraw_amount;

		if(withdraw_amount == 0000)
		{
			std::cout << "Transaction ended" << std::endl;
			std::cout << "Final Balance is: " << account_balance << std::endl;
			break;
		}

		else if(withdraw_amount > account_balance)
		{
			std::cout << "Insufficient balance" << std::endl;
		}

		else if(withdraw_amount < 0)
		{
			std::cout << "Invalid amount" << std::endl;
		}
		
		else
		{
			account_balance -= withdraw_amount;
			std::cout << "Current balance: " << account_balance << std::endl;
			
			if(account_balance == 0) break;

			else if(withdraw_amount == 0) break;
		} 
	} while(true);
}


