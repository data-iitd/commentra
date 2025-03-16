
#include <iostream>

int main() {
	// Declare a variable named day of type int
	int day;

	// Read an integer value from the standard input using std::cin
	std::cin >> day;

	// Use a switch statement to determine the name of the day based on the given day number
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

	return 0;
}

