#include <iostream>
#include <sstream>
using namespace std;

// This function's purpose is to ensure that all numbers on the clocks display as double digits.
string DisplayDoubleDigits(int theNumber) {
	// Utilizing strings for several reasons, but the biggest is because 08 as an integer causes it to read as an octal code.
	string doubleDigit = "";

	// Double digits are only needed if a number is less than 10, so an if statement is used.
	if (theNumber < 10) {
		doubleDigit = "0";
	}

	// The function returns any number less than 10 as a string with a 0 placed ahead of it.
	return doubleDigit + to_string(theNumber);
}


// I used the 24 hour time format as the base for my clocks. This function's purpose is simply to display the 24 time in my clock menu.
string Display24HourTime(int baseHours, int baseMins, int baseSecs) {

	// Tossed in some error codes incase someone tries to input negative time.
	if (baseHours < 00) {
		cout << "Error: Invalid Time" << endl;
	}
	if (baseMins < 00) {
		cout << "Error: Invalid Time" << endl;
	}
	if (baseSecs < 00) {
		cout << "Error: Invalid Time" << endl;
	}

	// 24 hour time will be displayed as a string, with the double digits function called to format it correctly.
	string twentyFourTime = DisplayDoubleDigits(baseHours) + ":" + DisplayDoubleDigits(baseMins) + ":" + DisplayDoubleDigits(baseSecs);

	return twentyFourTime;
}


// This is the 12 hour time conversion function. You might want to collapse this while viewing the rest of my code, it's long.
string Display12HourTime(int baseHours, int baseMins, int baseSecs) {
	string twelveHrs;
	string timeOfDay;

	// One big difference to be accounted for between the clocks is AM and PM time. These if statements determing whether or not the time is AM or PM for the clock display.
	if ((baseHours >= 00) && (baseHours <= 11)) {
		timeOfDay = "AM";
	}
	if ((baseHours >= 12) && (baseHours <= 23)) {
		timeOfDay = "PM";
	}

	// I left this out of my switch because... I don't know. I just did.
	if (baseHours == 00) {
		twelveHrs = 12;
	}

	// I used a switch case to convert 24 hour time to 12 hour. This was a lot smaller when I thought I only had to convert hours 13-23, but since I can't mix strings and integers, I ended up having to do them all. 
	switch (baseHours) {
	case 01:
		twelveHrs = "01";
		break;
	case 02:
		twelveHrs = "02";
		break;
	case 03:
		twelveHrs = "03";
		break;
	case 04:
		twelveHrs = "04";
		break;
	case 05:
		twelveHrs = "05";
		break;
	case 06:
		twelveHrs = "06";
		break;
	case 07:
		twelveHrs = "07";
		break;
	case 8:
		twelveHrs = "08";
		break;
	case 9:
		twelveHrs = "09";
		break;
	case 10:
		twelveHrs = "10";
		break;
	case 11:
		twelveHrs = "11";
		break;
	case 12:
		twelveHrs = "12";
		break;
	case 13:
		twelveHrs = "01";
		break;
	case 14:
		twelveHrs = "02";
		break;
	case 15:
		twelveHrs = "03";
		break;
	case 16:
		twelveHrs = "04";
		break;
	case 17:
		twelveHrs = "05";
		break;
	case 18:
		twelveHrs = "06";
		break;
	case 19:
		twelveHrs = "07";
		break;
	case 20:
		twelveHrs = "08";
		break;
	case 21:
		twelveHrs = "09";
		break;
	case 22:
		twelveHrs = "10";
		break;
	case 23:
		twelveHrs = "11";
		break;
	}

	// Same string deal as in the 24 hour function. This one is converted and includes AM/PM.
	string twelveHoursTime = twelveHrs + ":" + DisplayDoubleDigits(baseMins) + ":" + DisplayDoubleDigits(baseSecs) + " " + timeOfDay;

	return twelveHoursTime;
}


// Function for adding an hour to the clocks. Not much going on here.
void AddHour(int &hour) {

	hour += 1;

	return;
}


// Function for adding a minute to the clocks.
void AddMinute(int &hour, int &minute, int &second) {

	minute += 1;

	// In addition to adding a minute, calculations had to be done for a minute rolling into the next hour, and the next hour rolling into the next day. 
	if (hour > 23) {
		hour = 00;
		minute = 00;
		second = 00;
	}
	if (minute > 59) {
		hour += 1;
		minute = 00;
		second = 00;
	}

	return ;
}


// Function for adding a second to the clocks. Same idea as the minutes, but includes seconds rolling into the next minute, as well.
void AddSecond(int &hour, int &minute, int &second) {

	second += 1;

	if (hour > 23) {
		hour = 00;
		minute = 00;
		second = 00;
	}
	if (minute > 59) {
		hour += 1;
		minute = 00;
		second = 00;
	}
	if (second > 59) {
		minute += 1;
		second = 00;
	}

	return;
}

// the Display Menu function. This is what shows the menu of options for the user to select.
void DisplayMenu() {

	//These three blocks of variables and strings are all to determine math for spacing out my strings in the menu for proper placement.
    int consoleWidth = 80;
    int menuWidth = 26;
	int whiteSpace = (consoleWidth - menuWidth) / 2;

	string option1 = "* 1 - Add One Hour";
	string option2 = "* 2 - Add One Minute";
	string option3 = "* 3 - Add One Second";
	string option4 = "* 4 - Exit Program";

	int endSpace1 = (menuWidth - option1.length()) - 1;
	int endSpace2 = (menuWidth - option2.length()) - 1;
	int endSpace3 = (menuWidth - option3.length()) - 1;
	int endSpace4 = (menuWidth - option4.length()) - 1;

	// The actual output for the Display Menu. Used my variables to make strings of characters and whitespace to fill in.
	cout << string(whiteSpace, ' ') << string(menuWidth, '*') << endl;
	cout << string(whiteSpace, ' ') << "* 1 - Add One Hour" << string(endSpace1, ' ') << "*" << endl;
	cout << string(whiteSpace, ' ') << "* 2 - Add One Minute" << string(endSpace2, ' ') << "*" << endl;
	cout << string(whiteSpace, ' ') << "* 3 - Add One Second" << string(endSpace3, ' ') << "*" << endl;
	cout << string(whiteSpace, ' ') << "* 4 - Exit Program" << string(endSpace4, ' ') << "*" << endl;
	cout << string(whiteSpace, ' ') << string(menuWidth, '*') << endl;

	return;
}


// The Clock Display function. This shows both clocks side by side with the current, updating time.
void ClockDisplay(int consoleWidth, int menuWidth, int hours, int minutes, int seconds) {

	// Same things with the strings and variables. Using them for formatting math.
	string whiteColumn = string((consoleWidth - (menuWidth * 2)) / 3, ' ');

	string clockName1 = "12-Hour Clock";
	string clockName2 = "24-Hour Clock";
	string clockTime1 = "00:00:00 PM";
	string clockTime2 = "00:00:00";

	int inSpace1 = (menuWidth - clockName1.length()) / 2;
	int inSpace2 = (menuWidth - clockName2.length()) / 2;
	int inSpace3 = (menuWidth - clockTime1.length()) / 2;
	int inSpace4 = (menuWidth - clockTime2.length()) / 2;

	// The output for the display. Both my 12 and 24 hour clock functions are called here. Also had to manually adjust my formatting because the math wasn't perfect.
	cout << whiteColumn << string(menuWidth, '*') << whiteColumn << string(menuWidth, '*') << endl;
	cout << whiteColumn << "*" << string(inSpace1, ' ') << "12-Hour Clock" << string(inSpace1 - 1, ' ') << "*";
	cout << whiteColumn << "*" << string(inSpace2, ' ') << "24-Hour Clock" << string(inSpace2 - 1, ' ') << "*" << endl;
	cout << whiteColumn << "*" << string(inSpace3, ' ') << Display12HourTime(hours, minutes, seconds) << string(inSpace3 - 1, ' ') << "*";
	cout << whiteColumn << "*" << string(inSpace4, ' ') << Display24HourTime(hours, minutes, seconds) << string(inSpace4 - 2, ' ') << "*" << endl;
	cout << whiteColumn << string(menuWidth, '*') << whiteColumn << string(menuWidth, '*') << endl;

	return;
}

// Main function. Got it as small as I could!
int main() {

	// Variables needed to start off my clocks
	int startingHour;
	int startingMins;
	int startingSecs;

	// Prompts and input for the initial time.
	cout << "Enter Initial Hour (24-Hour Format):" << endl;
	cin >> startingHour;

	cout << "Enter Initial Minute(s):" << endl;
	cin >> startingMins;

	cout << "Enter Initial Second(s):" << endl;
	cin >> startingSecs;


	// Created an endless loop for the menu. It will loop forever until the user exits with 4.
	while (true) {

		// Displays the clocks and the menu beneath to show the time and options.
		ClockDisplay(80, 26, startingHour, startingMins, startingSecs);
		DisplayMenu();

		int selection;

		// Promptimg the user to make a selection from the menu.
		cout << "Select a Menu Option:" << endl;
		cin >> selection;


		// Another switch case, this time for the menu options. 1, 2, and 3 call the add time functions, 4 exits the program.
		switch (selection) {
		case 1:
			AddHour(startingHour);
			break;
		case 2:
			AddMinute(startingHour, startingMins, startingSecs);
			break;
		case 3:
			AddSecond(startingHour, startingMins, startingSecs);
			break;
		case 4:
			return 0;
			break;
		}
	}

	return 0;
}