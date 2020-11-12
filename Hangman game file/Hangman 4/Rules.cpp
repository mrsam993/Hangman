//include the header file to access all needed libraries and functions 
#include"Header.h"

//function that displays the rules to the user, after they have entered 3 on the main menu
void rules()
{
	//clear the screen removing the main menu, then display the different sections of the rules, wait for the user to press enter giving them time to read the rules then clear the screen and go back to the menu function allowing the menu to be displayed again
	system("cls");
	std::cout << "Hangman rules:\nThere is a hidden word that you must guess, you have six lives and you can guess one letter at a time, if the letter is not in the hidden word it will be displayed and you will lose a life, if the letter is in the word, you will not lose a life and the position of the letter in the word and all instances of the letter within the word will be displayed to you, if you lose all six of you're lives without guessing every letter in the word you lose but if you manage to guess every letter in the word before you lose all of you're lives you win.\nScore:\nYou will gain points for every letter guessed correctly and you will gain bonus points for guessing multiple letters in a row, additionally you will gain bonus points at the end for any remaining lives you have left.\nHints:\nWhen you have two lives remaining a hint will be given to you to help you guess the word if you are struggling, be aware that although hints are still provided in hard mode they will be more difficult to decipher. The only exception to this is cryptic clue mode which is presented more like a riddle where the hint is provided from the start.\nDebug mode:\nIn debug mode you will be able to see the hidden word and the hint from the very beginning of the game, to enter and exit debug mode enter the number 9 in the main menu.\n";
	system("pause");
	system("cls");
}