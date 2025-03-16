
#include <iostream>

// Include the standard input/output library

int main()
{
    int S; // Declare an integer variable named S

    // Initialize an integer variable named S with a value read from the standard input
    std::cin >> S;

    // Print the hours, minutes, and seconds of the given number of seconds
    std::cout << (int)(S / 3600) << ":" << (int)((S % 3600) / 60) << ":" << S % 60 << std::endl;

    // Return 0 to indicate successful execution of the program
    return 0;
}


