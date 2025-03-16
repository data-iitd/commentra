#include <iostream>

int main() {
	// Declare a variable to hold the day of the month
	int day;
	
	// Read an integer input from the user representing the day
	std::cin >> day;

	// Use a switch statement to determine the holiday based on the day
	switch (day) {
	case 25:
		// If the day is 25, print "Christmas"
		std::cout << "Christmas" << std::endl;
		break;
	case 24:
		// If the day is 24, print "Christmas Eve"
		std::cout << "Christmas Eve" << std::endl;
		break;
	case 23:
		// If the day is 23, print "Christmas Eve Eve"
		std::cout << "Christmas Eve Eve" << std::endl;
		break;
	case 22:
		// If the day is 22, print "Christmas Eve Eve Eve"
		std::cout << "Christmas Eve Eve Eve" << std::endl;
		break;
	}
}

