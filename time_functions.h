/*
   File: time_functions.h
   Author: Abhishek Patel
   Date: 03/24/2024
   Description: Header file for time-related functions.
*/

#pragma once
#ifndef TIME_FUNCTIONS_H
#define TIME_FUNCTIONS_H

#include <tuple>
#include <string>

// Constant for the width of decorative stars
const int BOX_WIDTH = 27;

// Function declarations for time-related functions
void printClock();            // Print the current time display
void printMenu();            // Display the menu and handle user input
std::string amORpm();// Determine if it's AM or PM
void asteriskPrint(int j, int k);// Print a row of stars
std::tuple<int, int, int, int> timeCheck(); // Check and update time
void show12HourTime();       // Display the 12-hour time
void show24HourTime();       // Display the 24-hour time 

// External declarations for variables used in the functions
extern int dataEdit;  // Variable for user input in menu
extern int hour;      // Hour component of time
extern int militaryHour;   // Hour component of time in 24-hour format
extern int minute;    // Minute component of time
extern int second;    // Second component of time

// Function declarations for additional time-related functions
void addOneSecond();        // Add one second to the clock
void setTimeFromUserInput();// Set the time based on user input
void printClock(); // Print current time display

#endif // TIME_FUNCTIONS_H