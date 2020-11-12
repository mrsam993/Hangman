//include the header file to access all needed libraries and functions 
#include"Header.h"

//function that allows the user to change the theme and select the difficulty, after they have entered 2 on the main menu
int themeSelection()
{
	//define the theme option integer that will be returned, as well as an array for the users input and an integer to define what error the user has caused with their input 
	int themeOption = 1;
	char themeArray[100] = { 0 };
	int validGuess = 0;
	//similar to the main menu and guessing functions, most of the function is wrapped in a do while loop, but the loop only stops once the user has entered a valid input, this prevents invalid inputs getting to other parts of the program and potentially causing crashes 
	do
	{
		//test the validGuess integer to test if the user input is valid or not
		switch (validGuess)
		{
		//for the first loop it presents the default message as nothing has been input and the default state of validGuess is 0, after the message has been presented, break from the switch statement 
		case 0:
			std::cout << "Please enter a number to select a theme and difficulty:\n(1)General\n(2)General-Hardmode\n(3)Food\n(4)Food-Hardmode\n(5)Sports\n(6)Sports-Hardmode\n(7)Cities\n(8)Cities-Hardmode\n(9)Celebrations\n(10)Celebrations-Hardmode\n(11)Cryptic clues\n";
			break;
		//if there are subsequent loops there must have been an error so it will display the correlating error message, however in this function there is only one error message, after it has been displayed break from the switch statement
		case 1:
			std::cout << "Please enter a number to select a theme and difficulty:\n(1)General\n(2)General-Hardmode\n(3)Food\n(4)Food-Hardmode\n(5)Sports\n(6)Sports-Hardmode\n(7)Cities\n(8)Cities-Hardmode\n(9)Celebrations\n(10)Celebrations-Hardmode\n(11)Cryptic clues\n(this must be a number between 1 and 10)\n";
			break;
		}
		//by setting validGuess to zero the program assumes the users input is valid and this only changes if certain criteria is met and is proven invalid
		validGuess = 0;
		//get the users input and assign it to the input array 
		std::cin.getline(themeArray, 100);
		//if the user input is over 100 characters or causes an error with the array in any other way, clear and repair the buffer to prevent storing extra inputs or crashing the program
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		//test every character in the users input, if any of these are not digits between 0 and 9 if changes validGuess to 1 flagging the users input as invalid
		for (int i = 0; i < strlen(themeArray); i++)
		{
			if (isdigit(themeArray[i]) == false)
			{
				validGuess = 1;
			}
		}
		//if the users input is still valid at this point (and therefor only consisting of numbers from 0 to 9) convert the input into an integer and test if it is greater than 11, as there are only 11 options to choose from if it is greater than 11 we can flag it as an error by changing validGuess to 1
		if (validGuess == 0)
		{
			themeOption = atoi(themeArray);
			if (themeOption > 11)
			{
				validGuess = 1;
			}
		}
		//clear the screen incase a new message needs to be displayed (if the input is invalid) or the main menu needs to be displayed (if the input is valid)
		system("cls");
	//if the loop completes without the input being flagged as invalid the loop breaks and the integer of the users input can be returned
	} while (validGuess != 0);
	return themeOption;
}
