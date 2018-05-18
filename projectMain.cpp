//Lim Jie Wen : Course Project
//main program to run the classes that make up MyATM Bank
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "ATMAdmin.h"
#include "CheckBalance.h"
#include "Withdrawal.h"
#include "SecurityCodes.h"

using namespace std;

//declarations for functions used
void loginScreen(int& accNumber);
int accountValidity(int accNumber, int accountNo[]);
void mainDisplay(int& choice);
void decisionFilter(int decision, int index, int pinArray[], int balanceArray[]);
void delayedResponse();

int main()
{
	int accountNo[5], balance[5], pinCode[5]; // initialization for fstream input
	string lastName[5];
	int accNum, option, flag, singlePin[7]; //intialization for used variables
	char ans;
	
	ATMAdmin pin; //declares a new object for class ATMAdmin called pin
		
	fstream accDetails; //creates an object for the fstream
	
	accDetails.open("user.txt"); //taps into the information hardcoded in user.txt file
	
	for (int x = 0; x < 5; x++) //sorts the information into their respective arrays
	{
		for (int y = 0; y < 4; y++)
		{
			if (y == 0)
				accDetails >> accountNo[x];
			else if (y == 1)
				accDetails >> lastName[x];
			else if (y == 2)
				accDetails >> balance[x];
			else
				accDetails >> pinCode[x];				
		}
	}
	
	loginScreen(accNum); //prints the login screen
	int temp = accountValidity(accNum, accountNo); //stores 1 value from the function
	
	if (temp < 5) //checks the value/condition number
	{ //this condition is for when the account number entered is valid
		cout << "\n\tAuthorisation successful. ";
		cout << "Welcome, Mr/Mrs." << lastName[temp] << endl << endl;
		
		delayedResponse();
		pin.intToArray(temp, pinCode, singlePin); //configures the pin into an array
		pin.mainChecker(singlePin, flag); //evaluates the PIN number: If right/wrong
		
		if (flag != 0) //'flag' represents the tries remaining after checking the pin
		{
			do
			{
				mainDisplay(option); //prints the main directory if conditions are met
				
				if (option == -1)
					break;
				else
				{	
					decisionFilter(option, temp, pinCode, balance);	//function filter	
					cout << "\n\tDo you wish to continue? (Y/N) ";
					cin >> ans;
				}
			} while (ans == 'Y' || ans == 'y');
		
			system("cls");
			cout << "\n\tExiting account" << endl;
			delayedResponse();
		}
		
		else
			cout << endl;		
	}
	
	else //shuts down if the account number provided is invalid
	{
		cout << "\n\n\tShutting down.." << endl;
		delayedResponse();
	}
	
	//check if account number entered is valid
	//if valid, proceed to the PIN request screen, else ask if the user wants to try again
		
}

void loginScreen(int& accNumber) //prints a default login screen, and detects one input value
{
	system("cls");
	cout << "\n\tMyATM Bank" << "\n\n\t" << "Enter Account Number: ";
	cin >> accNumber;
}

int accountValidity(int accNumber, int accountNo[]) //checks to see if account is valid
{
	int x;
	
	for (x = 0; x < 5; x++)
	{
		if (accNumber == accountNo[x])
			break;
		else if (x == 4)
		{
			cout << "\n\n\tThe account number you entered was invalid.." << endl;
			x = 5;
		}			
		else
			cout << "";
	}
	return x;
}
			
void mainDisplay(int& choice) //prints the main directory
{
	system("cls");
	cout << "\n\tMyATM Bank\n\n\n";
	cout << "\t1. Balance\t\t\t2. Withdrawal\n\n\n";
	cout << "\t3. Security Token\t\t4. Change PIN\n\n\n\n\n\n\n\n\n\n";
	
	cout << "\tWhat action would you like to perform? (-1 to exit) ";
	cin >> choice; //prompts the user for an input
}			
	
void decisionFilter(int decision, int index, int pinArray[], int balanceArray[])
{ //function that filters through the user's decision
	CheckBalance totalAccount(balanceArray[index]); //gets acc balance from array[index]
	Withdrawal transaction; //creates a new object for Withdrawal
	SecurityCodes mobile2u; //initializes new object for SecurityCodes
	ATMAdmin pin; //sets a new object for ATMAdmin class
		
	if (decision == 1)
	{
		system("cls");
		cout << "\n\n\tMyATM Bank";
		cout << "\n\n\n\n\tYour account balance is $" << totalAccount.getBalance() << endl;
	}
	
	else if (decision == 2)
		transaction.withdraw(totalAccount.getBalance());
		
	else if (decision == 3)
 		mobile2u.getSecurityCode();
	
	else if (decision == 4)
		pin.changePin(index, pinArray);
		
}

void delayedResponse() //aesthetic function
{
	for (int x = 0; x <= 720000000; x++)
	{
		if (x == 720000000)
			system("cls");
	}
}