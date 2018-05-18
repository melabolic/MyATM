//Lim Jie Wen : Course Project
//class definition and declaration for CheckBalance.h
#include <iostream>
#include <fstream>

class CheckBalance
{
	public:
		explicit CheckBalance(int amount) //receives the amount from outside this class
			: balance(amount) //sets the argument value to a local private variable
			{}
			
		int getBalance() const //returns the balance stored in the function
		{
			return balance; 
		}
		
	private:
		int balance;
};