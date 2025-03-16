#include <iostream>

using namespace std;

int main()
{
    int S; // Declare an integer variable named S

    // Initialize an integer variable named S with a value read from the standard input
    cin >> S;

    // Print the hours, minutes, and seconds of the given number of seconds
    cout << (int)(S / 3600) << ":" << (int)((S % 3600) / 60) << ":" << S % 60 << endl;

    // Return 0 to indicate successful execution of the program
    return 0;
}

