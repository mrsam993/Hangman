//include the header file to access all needed libraries and functions 
#include"Header.h"

//function that starts the program
int main()
{
	//define the integer that allows the program to end as well as the theme which needs to be referenced between different functions, an array to take the user input and a boolean to enter debug mode 
	int exit = 0;
	int theme = 1;
	char menuOption[100] = { 0 };
	bool debug = false;
	//all the menu options are in a do while loop that only breaks if the user presses the number 4 to exit the program, this way i can have the menu loop allowing the user to play multiple rounds in a row until they choose to exit
	do
	{
		//present the user with the menu options and gather their input into the array
		std::cout << "What would you like to do? Please input a number and press enter to pick an option:\n(1) Play hangman\n(2) Select the difficulty or change the theme of hangman\n(3) Read the rules\n(4) Quit the game\n";
		std::cin.getline(menuOption, 100);
		//if the user input is over 100 characers or causes an error with the array in any other way, clear and repair the buffer to prevent storing extra inputs or crashing the program
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		//test the users input against the 4 menu options, if none of these are the users input run the default case
		switch (menuOption[0])
		{
		//if the user entered the number 1 clear the screen and run the game function, after this function is complete break from the switch statement
		case '1':
			system("cls");
			mainGame(theme, debug);
			break;
		//if the user entered the number 2 clear the screen and run the theme selection function and assign the return of the function to the theme integer, after this function is complete break from the switch statement
		case '2':
			system("cls");
			theme = themeSelection();
			break;
		//if the user entered the number 3 clear the screen and run the rules function, after this function is complete break from the switch statement
		case '3':
			system("cls");
			rules();
			break;
		//if the user entered the number 4 clear the screen and set the exit integer to be 1 allowing the do while loop to end and for the program to close
		case '4':
			system("cls");
			exit = 1;
			break;
		//if the user entered the number 9 clear the screen and check if the user is in debug mode, if they are enable the debug boolean and inform the user they have entered debug more, if they are already in debug mode, disable the boolean and inform the user, after either if these take place break from the switch statement
		case '9':
			system("cls");
			if (debug == false)
			{
				debug = true;
				std::cout << "You have entered debug mode, to exit debug mode, type 9 into the main menu\n";
				system("pause");
			}
			else
			{
				debug = false;
				std::cout << "You have exited debug mode, to enter debug mode again, type 9 into the main menu\n";
				system("pause");
			}
			system("cls");
			break;
		//if the users input does not match any of theses cases, present an error message, wait for the user to press enter then clear the screen and repeat the loop
		default:
			std::cout << "This is not a valid option please enter a single number (1), (2), (3) or (4)\n";
			system("pause");
			system("cls");
			break;
		}
	//break from the while loop after the user the user has pressed 4 to confirm their exit
	} while (exit == 0);
}