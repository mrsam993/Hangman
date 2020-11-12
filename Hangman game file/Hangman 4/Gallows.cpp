//include the header file to access all needed libraries and functions 
#include"Header.h"

//a function that displays the gallows as well as the score and current progress on the word, it is called in the game function
void displayGallows(int livesLeft, int totalScore, bool& won, char(&wordArray)[10], char(&correctArray)[26], char hint[70], bool debugMode, int themeChoice)
{
	//create an integer to determine how much of the gallows to display (each line of the gallows is 16 characters so for each line that is lost display another 16 characters or one new line of the man in the gallows), print the top of the gallows as that is always displayed, define an array that contains the full gallows art and define an integer that can be a buffer of 0's for the score 
	int amountOfMan = (6 - livesLeft) * 16;
	std::cout << "__________\n";
	char man[97] = { "|        |     \n|      {0~0}   \n|    ---[-]--- \n|       [-]    \n|       / \\    \n|      /   \\   \n" };
	int numberBuffer = 0;
	//print a line (16 characters) of the gallows man for every life lost
	for (int x = 0; x < amountOfMan; ++x)
	{
		std::cout << man[x];
	}
	//for every life the user still has remaining (and for every line of the gallows man that hasn't been printed) print a vertical bar on the side to ensure that the gallows takes up the same amount of lines
	for (int y = 0; y < livesLeft; y++)
	{
		std::cout << "|" << "\n";
	}
	//after the top part of the gallows have been displayed, display the current state of the hidden word to the user
	displayWord(won, wordArray, correctArray);
	//the score is calculated before it is displayed as the amount of 0's needed to buffer it is important to printing to ensure no matter what size score is, it always takes up 5 characters 
	//if the game has been won the user is awarded 1000 points for every remaining life they have left
	if (won == true)
	{
		totalScore += 1000 * livesLeft;
	}
	//if the score is less than 10 and is therefore 1 character long, 4 zeros need to buffer it (e.g) 00009
	if (totalScore < 10)
	{
		numberBuffer = 4;
	}
	//if the score is less than 100 and is therefore 2 characters long, 3 zeros need to buffer it (e.g) 00099
	else if (totalScore < 100)
	{
		numberBuffer = 3;
	}
	//if the score is less than 1000 and is therefore 3 characters long, 2 zeros need to buffer it (e.g) 00999
	else if (totalScore < 1000)
	{
		numberBuffer = 2;
	}
	//if the score is less than 10000 and is therefore 4 characters long, 1 zero need to buffer it (e.g) 09999
	else if (totalScore < 10000)
	{
		numberBuffer = 1;
	}
	//if the score is 5 characters long (which is the maximum) no zeros need to be displayed to buffer it (e.g) 99999
	//print first half of the box displaying the score, up until the score and buffer need to be printed
	std::cout << "o=================o\n|   score:";
	//print a zero before the score for every digit in the number buffer (calculated above)
	for (int i = 0; i < numberBuffer; i++)
	{
		std::cout << "0";
	}
	//after the buffer has been printed, print the score integer and the rest of the score display box
	std::cout << totalScore << "   |\n|lives remaining:" << livesLeft << "|\no=================o\n";
	//if the user is in debug mode, display the word and the hint from the beginning
	if (debugMode == true)
	{
		std::cout << "DEBUG MODE WORD: " << wordArray << "\nDEBUG MODE HINT: " << hint << "\n";
	}
	//if the user has two remaining lives, also print out the hint to help the user guess the word (unless the user is playing on cryptic clue mode which is theme 11)
	if (livesLeft <= 2 && themeChoice != 11)
	{
		std::cout << "Hint: " << hint << "\n";
	}
	//if the user is playing on cryptic clue mode the hint is displayed from the start and presented as a clue
	if (themeChoice == 11)
	{
		std::cout << "Clue: " << hint << "\n";
	}
	//after the gallows have been fully printed return to the game function to allow the user to guess a letter

	/*
	a visual example of what the completed gallows would look like
	__________
	|        ¦
	|      {0~0}
	|    ---[-]---
	|       [-]
	|       / \
	|      /   \
	|
	|______
	o=================o
	|   score:00000   |
	|lives remaining:6|
	o=================o
	*/
}