//include the header file to access all needed libraries and functions 
#include"Header.h"

//function that displays all the currently guessed letters that are incorrect, this is called during the game function after the gallows have been displayed
void displayIncorrectLetter(char(&incorrectArray)[26])
{
	//print a line notifying that this is displaying incorrect guesses and loop through every item in the array printing all of them with a space between each
	std::cout << "Incorrect guesses: ";
	for (int i = 0; i < strlen(incorrectArray); i++)
	{
		std::cout << incorrectArray[i] << " ";
	}
	//at the end of the function print a new line and return to the game function
	std::cout << "\n";
}