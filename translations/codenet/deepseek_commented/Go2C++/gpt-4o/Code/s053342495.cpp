#include <iostream>

int main() {
    // Declare a variable to store the day of Christmas
    int day;
    // Read an integer input from the user
    std::cin >> day;

    // Use a switch statement to determine the day of Christmas
    switch (day) {
        case 25:
            // If the day is Christmas (December 25), print "Christmas"
            std::cout << "Christmas" << std::endl;
            break;
        case 24:
            // If the day is Christmas Eve (December 24), print "Christmas Eve"
            std::cout << "Christmas Eve" << std::endl;
            break;
        case 23:
            // If the day is Christmas Eve Eve (December 23), print "Christmas Eve Eve"
            std::cout << "Christmas Eve Eve" << std::endl;
            break;
        case 22:
            // If the day is Christmas Eve Eve Eve (December 22), print "Christmas Eve Eve Eve"
            std::cout << "Christmas Eve Eve Eve" << std::endl;
            break;
        default:
            // Optional: Handle cases where the day is not recognized
            std::cout << "Not a special day" << std::endl;
            break;
    }

    return 0;
}

// <END-OF-CODE>
