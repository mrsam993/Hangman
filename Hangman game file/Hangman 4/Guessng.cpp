//include the header file to access all needed libraries and functions 
#include"Header.h"

//a function that allows the user to guess a letter, it is called in the game function
void userGuessing(char(&wordArray)[10], char(&correctArray)[26], char(&incorrectArray)[26], int& totalLives, int& score, int& streak)
{
	//define an integer to check if the users input is valid, a boolean to see if the users input was correct and an array to take the users input
	int validGuess = 0;
	bool correctGuess = false;
	char userGuess[100] = { 0 };

	//similar to the theme function, run a do while that can only be exited if the users input is valid to prevent invalid inputs getting to other parts of the program
	do
	{
		//test against the validGuess integer to see if the input was correct and what error message to display
		switch (validGuess)
		{
		//on the first loop the user hasn't input anything so there is no need for an error message and the default message is displayed, after the message has been displayed it breaks from the switch statement
		case 0:
			std::cout << "Enter a character: ";
			break;
		//if the program has looped and the users previous input was more than one character long it as flagged as error 1 and the appropriate message is displayed, after the message has been displayed it breaks from the switch statement
		case 1:
			std::cout << "Enter a character (cannot be more than one character long): ";
			break;
		//if the program has looped and the users previous input has already been entered it as flagged as error 2 and the appropriate message is displayed, after the message has been displayed it breaks from the switch statement
		case 2:
			std::cout << "Enter a character (cannot be an already entered character): ";
			break;
		//if the program has looped and the users previous input was not a letter it as flagged as error 3 and the appropriate message is displayed, after the message has been displayed it breaks from the switch statement
		case 3:
			std::cout << "Enter a character (this must be a letter): ";
			break;
		}
		//by setting validGuess to zero the program assumes the users input is valid and this only changes if certain criteria is met and is proven invalid
		validGuess = 0;
		//the users input is gathered and assigned to the allocating array 
		std::cin.getline(userGuess, 100);
		//if the user input is over 100 characers or causes an error with the array in any other way, clear and repair the buffer to prevent storing extra inputs or crashing the program
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		//the first character of the users guess (the only one that is processed) is converted into lower case to avoid confusion
		userGuess[0] = tolower(userGuess[0]);
		//if the users input is not a letter it is flagged as invalid and validGuess is set to 3 so the appropriate error message can be displayed when the do while loop loops again
		if (isalpha(userGuess[0]) == false)
		{
			validGuess = 3;
		}
		//if the users input is more than one character it is flagged as invalid and validGuess is set to 1 so the apropriate error message can be displayed when the do while loop loops again
		if (strlen(userGuess) > 1)
		{
			validGuess = 1;
		}
		//for every letter of the word run the loop, if the users guess is equal to any letter in the word, check to see if it has already been guessed 
		for (int i = 0; i < strlen(wordArray); i++)
		{
			if (wordArray[i] == userGuess[0])
			{
				for (int i = 0; i < strlen(correctArray); i++)
				{
					//if the users input has already been input it is flagged as invalid and validGuess is set to 2 so the apropriate error message can be displayed when the do while loop loops again
					if (userGuess[0] == correctArray[i])
					{
						validGuess = 2;
					}
				}
				//if the users input is in the hidden word and validGuess is still 0 (A.K.A it is also a letter that is one character long and has not been previously been guessed) a boolean has been flagged to true, a boolean is used here to prevent errors if a letter appears multiple times in a single word
				if (validGuess == 0)
				{
					correctGuess = true;
				}
			}
		}
		//if the boolean has been set to true, the letter is added to the correct guesses array (making it appear on the gallows), a life is added as a life is taken away with every loop of the game for loop, 500 point (times the users streak) is added and the streak is incresed by one
		if (correctGuess == true)
		{
			correctArray[strlen(correctArray)] = userGuess[0];
			totalLives++;
			score += 500 * streak;
			streak++;
		}
		//if the boolean has not been set to true, check if the letter has already been guessed but was not correct
		else
		{
			for (int i = 0; i < strlen(incorrectArray); i++)
			{
				//if the users input has already been input it is flagged as invalid and validGuess is set to 2 so the apropriate error message can be displayed when the do while loop loops again
				if (userGuess[0] == incorrectArray[i])
				{
					validGuess = 2;
				}
			}
			//if the users input is not in the hidden word and validGuess is still 0 (A.K.A it is also a letter that is one character long and has not been previously been guessed) the letter is added to the incorrect guesses array and the users streak is reset to zero
			if (validGuess == 0)
			{
				incorrectArray[strlen(incorrectArray)] = userGuess[0];
				streak = 1;
			}
		}
	//if the entire function runs and the users input has not been flagged as invalid, the loop breaks and the program returns to the game function
	} while (validGuess != 0);
}