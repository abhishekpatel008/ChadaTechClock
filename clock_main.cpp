/*
    File: clock_main.cpp
    Author: Abhishek Patel
    Date: 03/24/2024
    Description: This program demonstrates the use of time functions to display and manipulate time.
                 It includes functions to print the current time in both 12-hour and 24-hour formats,
                 display a menu for user interaction, and add one hour, minute, or second to the time.
*/

#include "time_functions.h"
#include <iostream>

int main() {
    setTimeFromUserInput(); // Set the time based on user input

    printClock(); // Print the current time display
    printMenu(); // Display the menu and handle user input

    return 0;
}