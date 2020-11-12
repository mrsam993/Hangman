//define and prototype everything needed in one header file
#pragma once
#ifndef _DELAY_MS_H_
#define _DELAY_MS_H_

//include all needed libraries for the program
#include<windows.h>
#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cctype>
//define all prototypes for funtions
void displayGallows(int livesLeft, int totalScore, bool& won, char(&wordArray)[10], char(&correctArray)[26], char hint[70], bool debugMode, int themeChoice);
void displayWord(bool& won, char(&wordArray)[10], char(&correctArray)[26]);
void displayIncorrectLetter(char(&incorrectArray)[26]);
void userGuessing(char(&wordArray)[10], char(&correctArray)[26], char(&incorrectArray)[26], int& totalLives, int& score, int& streak);
void mainGame(int themeChoice, bool debugMode);
int themeSelection();
void rules();

#endif