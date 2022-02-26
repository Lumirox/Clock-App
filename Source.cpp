// Name: Project1Clock
// Author: Kenneth Bryant
// Description: Clock to Display standard and military time

#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

using namespace std;

//functionn to add an hour
void AddHour(int& clock12Hour, int& clock24Hour, string& ampm) {

	if (clock12Hour < 12) {
		clock12Hour += 1;
		if (clock12Hour == 12) { // used to swap between am and pm
			if (ampm == "A M") {
				ampm = "P M";
			}
			else {
				ampm = "A M";
			}
		}
	}
	

	else if (clock12Hour == 12) {
		clock12Hour = 01;
	}

	if (clock24Hour < 23) {
		clock24Hour += 1;
	}

	else if (clock24Hour == 23) {
		clock24Hour = 00;
	}

}

//Function to add a minute
void AddMinutes(int& minutes,int& clock12Hour,int& clock24Hour,string ampm) {

	if (minutes < 59) {
		minutes += 1;
	}

	else if (minutes == 59) { //called the hours function to increment the hours
		minutes = 00;
		AddHour(clock12Hour, clock24Hour, ampm);
	}
}

//Function to add a second
void AddSecond(int& seconds, int& minutes, int& clock12Hour, int& clock24Hour, string ampm) {

	if (seconds < 59) {
		seconds += 1;
	}

	else if (seconds == 59) { //called the minutes function to increment the minutes
		seconds = 00;
		AddMinutes(minutes, clock12Hour, clock24Hour, ampm);
	}
}

//Function to display clock and menu
void DisplayClock(int& clock12Hour, int& clock24Hour, int& minutes, int& seconds, string& ampm) { //used setw and setfill to get double numbers

	cout << "**************************\t" << "**************************" << endl;
	cout << "*     12-Hour Clock      *\t" << "*      24-Hour Clock     *" << endl;
	cout << "*     " << setw(2) << setfill('0') << clock12Hour << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " " << ampm << "       *\t";
	cout << "*        " << setw(2) << setfill('0') << clock24Hour << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << "        *" << endl;
	cout << "**************************\t" << "**************************" << endl;
	cout << endl;
	cout << endl;
	cout << "**************************" << endl;
	cout << "* 1-Add One Hour         *" << endl;
	cout << "* 2-Add One Minute       *" << endl;
	cout << "* 3-Add One Second       *" << endl;
	cout << "* 4-Exit Program         *" << endl;
	cout << "**************************" << endl;
}
//Main program
int main() {
	int userInput;

	int clock12Hour = 11;
	int clock24Hour = 23;
	int minutes = 58;
	int seconds = 58;
	string ampm = "P M";

	while (true) { //using while to create a continues loop
		DisplayClock(clock12Hour, clock24Hour, minutes, seconds, ampm);
		cin >> userInput;
		switch (userInput) {
		case 1:
			AddHour(clock12Hour, clock24Hour, ampm);
			system("CLS");
			break;
		case 2:
			AddMinutes(minutes, clock12Hour, clock24Hour, ampm);
			system("CLS");
			break;
		case 3:
			AddSecond(seconds, minutes, clock12Hour, clock24Hour, ampm);
			system("CLS");
			break;
		case 4:
			cout << "Exit Successful";
			return EXIT_SUCCESS;
		default:
			cout << "Invalid input";
			break;
		}
	}
}