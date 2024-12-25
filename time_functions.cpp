/*
    File: time_functions.cpp
    Author: Abhishek Patel
    Date: 03/24/2024
    Description: This file contains the implementation of various time-related functions.
                 These functions include printing the current time display, displaying a menu for user interaction,
                 determining if it's morning or night, checking and updating time, and adding one second to the clock.
*/

#include "time_functions.h"  // Include custom time functions header
#include <iostream>
#include <iomanip>
#include <thread>
#include <sstream>

int dataEdit;
int hour;
int militaryHour;
int minute;
int second;

void setTimeFromUserInput() {
    int userHour, userMinute, userSecond; // Change variable names to avoid redefinition
    char meridian[3]; // Variable to store AM/PM input

    bool isValidTime = false;

    while (!isValidTime) {
        // Prompt user to input the time format and time
        std::cout << "Enter the current time format and time (format: HH:MM:SS AM/PM): ";
        std::cin >> userHour; // Read hours
        std::cin.ignore(); // Ignore the colon
        std::cin >> userMinute; // Read minutes
        std::cin.ignore(); // Ignore the colon
        std::cin >> userSecond >> meridian; // Read seconds and meridian

        // Convert the hour to 24-hour format
        if (strcmp(meridian, "PM") == 0 && userHour != 12) {
            userHour += 12;
        }
        else if (strcmp(meridian, "AM") == 0 && userHour == 12) {
            userHour = 0;
        }

        // Validate the input
        if (userHour >= 0 && userHour <= 23 && userMinute >= 0 && userMinute <= 59 && userSecond >= 0 && userSecond <= 59) {
            isValidTime = true; // Set flag to true if input is valid
        }
        else {
            std::cout << std::endl;
            std::cerr << "Invalid time entered. Please enter a valid time..." << std::endl;
            std::cout << std::endl;
        }
    }

    // Assign user input to global variables
    hour = userHour;
    minute = userMinute; 
    second = userSecond;

    // Determine if it's AM or PM
    militaryHour = hour;
}

// Function to print the time display
void printClock() {
    asteriskPrint(27, 2); // Print decorative stars
    std::cout << std::endl;
    std::cout << "*       12-Hour Clock     *  *      24-Hour Clock      *" << std::endl; // Print clock labels
    std::cout << "*       ";
    show12HourTime(); // Print 12-hour time
    std::cout << "       *" << "  *        ";
    show24HourTime(); // Print 24-hour time
    std::cout << "         *" << std::endl;
    asteriskPrint(27, 2); // Print decorative stars
    std::cout << std::endl;
    }

// Function to display the menu and handle user input
void printMenu() {
    while (true) { // Infinite loop until break statement
        std::cout << std::endl;// Print empty line before displaying menu
        std::cout << std::endl;
        std::cout << "           Menu           " << std:: endl;
        std::cout << std::endl;
        asteriskPrint(27, 1); // Print decorative stars
        std::cout << std::endl << "*    1 - Add One Hour     *" << std::endl;
        std::cout << "*    2 - Add One Minute   *" << std::endl;
        std::cout << "*    3 - Add One Second   *" << std::endl;
        std::cout << "*    4 - Exit Program     *" << std::endl;
        asteriskPrint(27, 1); // Print decorative stars
        std::cout << std::endl; // Print empty line after displaying menu

        std::cin >> dataEdit; // Read user input

        switch (dataEdit) { // Switch based on user input
        case 1: // Add one hour
            hour++;
            militaryHour++;
            printClock(); // Update and print time
            break;
        case 2: // Add one minute
            minute++;
            printClock(); // Update and print time
            break;
        case 3: // Add one second
            addOneSecond();
            printClock(); // Update and print time
            break;
        case 4: // Exit program
            std::cout << std::endl; 
            std::cout << "Goodbye...!" << std::endl;
            return; // Exit the function if option 4 is selected
        default: // Invalid option
            std::cout << std::endl;
            std::cout << "Invalid option. Please try again..." << std::endl;
        }
    }
}

// Function to determine if it's AM or PM
std::string amORpm() {
    if ((militaryHour >= 12) && (militaryHour <= 23)) { // Check if it's PM
        return "PM";
    }
    else { // Otherwise, it's AM
        return "AM";
    }
}

// Function to print a row of stars
void asteriskPrint(int j, int k) {
    for (int m = 0; m < k; m++) {
        for (int i = 0; i < j; i++) {
            std::cout << '*'; // Print stars
        }
        std::cout << "  "; // Print spaces
    }
}

// Function to check and update time
std::tuple<int, int, int, int> timeCheck() {
    if (second >= 60) {
        second = 0;
        minute++;
    }
    if (minute >= 60) {
        hour++;
        militaryHour++;
        minute = 0;
    }
    if ((hour == 12) && (second > 59)) {
        hour = 1;
    }
    if (militaryHour >= 24) {
        militaryHour = 0;
    }
    return std::make_tuple(hour, minute, second, militaryHour); // Return updated time
}

// Function to add One second in the clock
void addOneSecond() {
    second++; // Increment seconds
    if (second >= 60) { // If seconds exceed 59
        second = 0; // Reset seconds to 0
        minute++; // Increment minutes
        if (minute >= 60) { // If minutes exceed 59
            hour++; // Increment hours
            militaryHour++; // Increment military hours
            minute = 0; // Reset minutes to 0
            if (hour == 12 && second > 59) { // If hours reach 12 and seconds exceed 59
                hour = 1; // Reset hours to 1
            }
            if (militaryHour >= 24) { // If military hours reach 24
                militaryHour = 0; // Reset military hours to 0
            }
        }
    }
}

// Function to display the 12-hour time
void show12HourTime() {
    int hour12 = std::get<0>(timeCheck());
    std::string meridian = amORpm();

    if (hour12 == 0) {
        hour12 = 12;
    } else if (hour12 > 12) {
        hour12 -= 12;
    }

    std::cout << std::setfill('0') << std::setw(2) << hour12 << ":"; // Print hour
    std::cout << std::setfill('0') << std::setw(2) << std::get<1>(timeCheck()) << ":"; // Print minute
    std::cout << std::setfill('0') << std::setw(2) << std::get<2>(timeCheck()) << " " << meridian; // Print second and AM/PM
}
// Function to display the 24-hour time
void show24HourTime() {
    std::cout << std::setfill('0') << std::setw(2) << std::get<3>(timeCheck()) << ":"; // Print hour
    std::cout << std::setfill('0') << std::setw(2) << std::get<1>(timeCheck()) << ":"; // Print minute
    std::cout << std::setfill('0') << std::setw(2) << std::get<2>(timeCheck()); // Print second
}