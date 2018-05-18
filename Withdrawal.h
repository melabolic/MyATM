//Lim Jie Wen : Course Project
//class definition and declaration for Withdrawal.h
#include <iostream>

class Withdrawal
{
	public:
		void withdraw(int balance) //gets the balance and stores it in the function
		{
			system("cls"); //aesthetics
			std::cout << "\n\n\tMyATM Bank\n\n\tMoney Withdrawal Service\n";
			std::cout << "\n\tCurrent Balance: $" << balance;
			std::cout << "\n\tHow much do you want to withdraw from your account?\n\n\t~ $";
			std::cin >> amount; //prompts user for input
			
			if (amount > balance) //doesn't let user withdraw if the amount requested 
			{					  //exceeds the account balance
				std::cout << "\n\tThe amount entered is greater than your current balance.\n"
					 << "\tNothing was withdrawn." << std::endl;
			}
			
			else if (amount < 0) //doesn't change balance if a negative amount is entered
			{
				std::cout << "\tNegative amount detected, account balance not changed."
						  << std::endl;
			}
			
			else //deducts the amount from the balance, and prints the new balance
			{
				newBalance = balance - amount;
				std::cout << "\n\tYour new balance is $" << newAccBalance() << std:: endl;
			}
		}
		
		int newAccBalance() const //function that returns the account balance
		{
			return newBalance;
		}
	private: //variable declarations
		int newBalance;
		int amount;
};