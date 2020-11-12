//include the header file to access all needed libraries and functions 
#include"Header.h"

void mainGame(int themeChoice, bool debugMode)
{
	//use the current time as a seed to determine the randomness for the program
	srand(time(0));
	//define an integer to store the random number generated on the programs start, an array to store correctly entered letters, an array to store incorrectly entered letters, an integer for the score and an integer to track how many guesses the user has gotten correct in a row
	int random = rand() % 10;
	char correctGuesses[26] = { 0 };
	char falseGuesses[26] = { 0 };
	int score = 0;
	int streak = 1;
	//define ten variables one for each theme, the themeChoice int is what is used to select the category and the random integer determines the word in said category
	char general[10][10] = { "flower", "ocean", "drum", "circle", "mattress", "shallow", "music", "cartoon", "years", "little" };
	char generalHard[10][10] = { "haiku", "haphazard", "memento", "sphinx", "zealous", "yacht", "abruptly", "embezzle", "jaundice", "pneumonia" };
	char food[10][10] = { "salad", "kebab", "yoghurt", "meatloaf", "sandwich", "popcorn", "curry", "nachos", "burger", "potatoes" };
	char foodHard[10][10] = { "fajita", "jambalaya", "omelette", "bolognese", "oysters", "caviar", "tripe", "sashimi", "haggis", "vegemite" };
	char sports[10][10] = { "football", "snooker", "rugby", "tennis", "golf", "baseball", "darts", "hockey", "cricket", "running" };
	char sportsHard[10][10] = { "frisbee", "karate", "triathlon", "quidditch", "decathlon", "bobsleigh", "curling", "skeleton", "archery", "shooting" };
	char cities[10][10] = { "london", "paris", "berlin", "tokyo", "rome", "stockholm", "amsterdam", "madrid", "warsaw", "brussels" };
	char citiesHard[10][10] = { "reykjavik", "tallin", "dodoma", "seoul", "cairo", "helsinki", "abudhabi", "ahgabat", "bangkok", "jerusalem" };
	char celebrations[10][10] = { "birthday", "christmas", "halloween", "summer", "easter", "valentine", "mardigras", "advent", "stdavids", "wedding" };
	char celebrationsHard[10][10] = { "kwanzaa", "hanukkah", "solstice", "lent", "diwali", "ramadan", "passover", "purim", "yule", "candlemas" };
	char crypticClues[10][10] = { "footsteps", "piano", "egg", "nothing", "stamp", "candle", "name", "button", "water", "sponge" };
	//define ten variables to store the hints for each category and word, the position of the word and its hint are the same and the random integer and themeChoice integer do not change between selecting the word and hint, as they are in the same position the correct hint is always selected for the correlating word 
	char generalHints[10][70] = { "This is something you would find a lot outside", "Lots of little and big things live here", "These used to be made from animal or human skin", "Clocks and wheels and holes", "You use this every single day, or maybe day isn't the right word", "Puddles not oceans", "Good on the ears", "Makes Saturday morning so much better", "Not quite decades", "Fantasy romance movie from 2019" };
	char generalHardHints[10][70] = { "5 7 5", "Strongly disorganised", "A nice little keepsake", "Not the pyramids", "A person of strong conviction", "Big big boat", "This is a hint about", "A fancy way of stealing", "What the Simpsons probably have", "Dont stay outside to long" };
	char foodHints[10][70] = { "Greens, egg or potatoes", "I find it best as a gyro", "Has a lot of culture", "Also a band", "Ruben, club and submarine", "Butter and salt yummy", "Should really be spicy but it isn’t most of the time", "What do you call cheese when it doesn't belong to you?", "What do Vince and Jewel love to talk about?", "Boil em mash em put em in a stew" };
	char foodHardHints[10][70] = { "TexMex classic", "Big in Spain and in Boston", "You've got to break a few eggs", "Named after the city it was made", "Part of the Ostreoidea super family", "I'll sadly be to poor to eat it", "Stomach inception", "Sushi without the rice", "No part of the sheep is wasted", "The famous Australian spread" };
	char sportsHints[10][70] = { "Every four years", "The best pub sport", "Better than the American alternative", "Back and forth, back and forth", "Scoring more points is somehow worse", "Once Americas favourite sport", "The sport with the least leg movement possible", "Home of the Canucks", "Unifying the two opposite of the world with rivalry", "The sport with the most leg movement possible" };
	char sportsHardHints[10][70] = { "Round and flat", "Originally from Japan", "Bang for your buck", "Viktor Krum", "Also included in academia", "Cool Runnings (1994)", "Almost shuffleboard", "Barebones sport", "You must be Brave to do it", "Most of the time this isn't a sport" };
	char citiesHints[10][70] = { "Home of the scotch egg", "Hunchback", "No wall anymore", "Most populated city in the world", "Salad and treachery", "Villain from The Incredibles", "Primary colour", "Winner of the 2016 world cup", "Target in WW2", "Sprout" };
	char citiesHardHints[10][70] = { "Lots of Viking history", "Capital of Estonia", "Its name means 'it has sunk'", "Home of K-pop", "Located on the world's longest river", "Capital of Finland", "Capital of the United Arab Emirates", "Capital of Turkmenistan", "Founded in 1972", "Between the Mediterranean and the red sea" };
	char celebrationsHints[10][70] = { "A very personal holiday", "Red and white", "In this town of", "Very seasonal holiday", "Death and rebirth", "Named after the saint", "Famous Mexican holiday", "Its about the journey not the destination", "1st of March", "A binding contract" };
	char celebrationsHardHints[10][70] = { "Celebrated near Christmas", "Famous Jewish holiday", "Comes twice a year", "The season of giving", "Lamps aren't just for genies", "Fastest holiday", "A week in April", "Triangle shaped foods are eaten during this time", "Pre-Christian Scandinavia", "Feast of the presentation of Christ" };
	char crypticCluesHints[10][70] = { "The more you take, the more you leave behind", "What has many keys, but can't open a single door", "What is more useful when it is broken", "Poor people have it and rich people need it", "What travels the world from a single place", "I'm tall when i'm young and short when i'm old", "You carry it everywhere you go but it has no weight", "Flat as a leaf, round as a ring, has two eyes but can't see a thing", "What runs without legs", "It can hold water despite having holes" };
	//define an array to store the word and the correlating hint that are selected
	char hiddenWord[10] = { 0 };
	char hint[70] = { 0 };
	//depending on what the themeChoice was select the correlating case selecting the right array for the word and hint and assign a word and hint from said arrays to the hiddenWord and hint array so it can be used in the game
	switch (themeChoice)
	{
	case 1:
		strcpy(&hiddenWord[0], general[random]);
		strcpy(&hint[0], generalHints[random]);
		break;
	case 2:
		strcpy(&hiddenWord[0], generalHard[random]);
		strcpy(&hint[0], generalHardHints[random]);
		break;
	case 3:
		strcpy(&hiddenWord[0], food[random]);
		strcpy(&hint[0], foodHints[random]);
		break;
	case 4:
		strcpy(&hiddenWord[0], foodHard[random]);
		strcpy(&hint[0], foodHardHints[random]);
		break;
	case 5:
		strcpy(&hiddenWord[0], sports[random]);
		strcpy(&hint[0], sportsHints[random]);
		break;
	case 6:
		strcpy(&hiddenWord[0], sportsHard[random]);
		strcpy(&hint[0], sportsHardHints[random]);
		break;
	case 7:
		strcpy(&hiddenWord[0], cities[random]);
		strcpy(&hint[0], citiesHints[random]);
		break;
	case 8:
		strcpy(&hiddenWord[0], citiesHard[random]);
		strcpy(&hint[0], citiesHardHints[random]);
		break;
	case 9:
		strcpy(&hiddenWord[0], celebrations[random]);
		strcpy(&hint[0], celebrationsHints[random]);
		break;
	case 10:
		strcpy(&hiddenWord[0], celebrationsHard[random]);
		strcpy(&hint[0], celebrationsHardHints[random]);
		break;
	case 11:
		strcpy(&hiddenWord[0], crypticClues[random]);
		strcpy(&hint[0], crypticCluesHints[random]);
		break;
	}
	//define a boolean to see if the user has won the game as well an integer to track user lives 
	bool winCondition = false;
	int lives = 6;

	//use a for loop to run the game, it runs once for every life the user has and every time the loop is run the user loses one life
	for (lives; lives > 0; lives--)
	{
		//runs displayGallows functions putting the gallows in its current state, the word in its current state and the score
		displayGallows(lives, score, winCondition, hiddenWord, correctGuesses, hint, debugMode, themeChoice);
		//run the function to display already guessed letters that are incorrect
		displayIncorrectLetter(falseGuesses);
		//if the user has not yet won the game, allow the user to guess again
		if (winCondition == false)
		{
			userGuessing(hiddenWord, correctGuesses, falseGuesses, lives, score, streak);
		}
		//if the user has won the game decrease the lives by 10 in order to break out of the loop 
		else
		{
			lives -= 10;
		}
		system("cls");
	}
	//if lives is equal to zero it means the user has lost as their lives have dropped from 1 to 0
	if (lives == 0)
	{
		//the user has lost so the gallows will be displayed with the updated stats as well as a message to display that the user has lost, after the user has pressed enter the scrren will be cleared and you will be returned to the main menu
		displayGallows(lives, score, winCondition, hiddenWord, correctGuesses, hint, debugMode, themeChoice);
		std::cout << "------------------------------------------\n|Commiserations, this time you didn't win|\n------------------------------------------\n";
		system("pause");
		system("cls");
	}
	//if the user has won, their lives will be less than zero as they will have been subtracted by 10
	if (lives < 0)
	{
		//as the lives have been subtracted by 10 they first need to be restored to their proper state, then the gallows will be displayed with the accurate information, as well as a message to display that the user has one, after the user has pressed enter the scrren will be cleared and you will be returned to the main menu
		lives += 11;
		displayGallows(lives, score, winCondition, hiddenWord, correctGuesses, hint, debugMode, themeChoice);
		std::cout << "**************************\n*Congratulations you won!*\n**************************\n";
		system("pause");
		system("cls");
	}
}