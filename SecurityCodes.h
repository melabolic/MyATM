//Lim Jie Wen : Course Project
//class definition and declaration for SecurityCodes.h
#include <iostream>
#include <cstdlib>
#include <ctime>

class SecurityCodes
{
	public:
		void getSecurityCode() const
		{
			int codeArray[6], mobile; //defines one array to store the random 6 digits
									  //and another variable to store the mobile number
			
			system("cls");
			std::cout << "\n\n\tMyATM Bank\n\n\tSecurity Token Function\n";
			std::cout << "\n\tPlease enter your mobile number: ";
			std::cin >> mobile;
			
			srand(time(NULL)); //sets a random seed
			
			for (int x = 0; x < 6; x++)
			{
				codeArray[x] = rand() % 9 + 1; //initializes the array values
			}	
			
			std::cout << "\n\tThe security code ";
			for (int x = 0; x < 6; x++)
			{
				std::cout << codeArray[x]; //prints the array values and description
			}
			std::cout << " has been sent to your mobile (+60" << mobile 
					  << ")\n\tUse it to activate MyATMBanking2u.\n\n" 
					  << "\tActivate your code within 2 hours, or it expires." << std::endl;
		}				
};
		
			