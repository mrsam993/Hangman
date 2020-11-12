//include the header file to access all needed libraries and functions 
#include"Header.h"

//function that displays the hidden word in its current state to the user, this is called in the display gallows function
void displayWord(bool& won, char(&wordArray)[10], char(&correctArray)[26])
{
	//define a boolean  to test if a letter needs to be printed or not and set the won boolean to be true, this function assumes the user has won until a blank is displayed, if there are no blanks to display it can be assumed that the entire word has been guessed
	bool printRightLetter = false;
	won = true;
	//print a single vertical line to match the rest of the gallows
	std::cout << "|";
	//for every letter in the word run to see if it matches any of the letters in the word (A.K.A the correctArray)
	for (int i = 0; i < strlen(wordArray); i++)
	{
		for (int y = 0; y < strlen(correctArray); y++)
		{
			//if, after both for loops, an entered character matches a character in the word the print letter boolean is set to true, an extra boolean is used to prevent errors if the enetered character is found multiple times within the word
			if (wordArray[i] == correctArray[y])
			{
				printRightLetter = true;
			}
		}
		//after the second for loop has been run print the appropriate character, if it has been flagged as correct, the users character can be printed and the boolean can be reset
		if (printRightLetter == true)
		{
			std::cout << wordArray[i];
			printRightLetter = false;
		}
		//if the entered charcter was not flagged as correct a blank will be printed and the won boolean will be set to false as if there are any blanks it has not been fully guessed
		else
		{
			std::cout << "_";
			won = false;
		}
	}
	//after the first for loop is over the function can end and a new line is printed to prepare for the printing of the remainder of the gallows
	std::cout << "\n";
}
