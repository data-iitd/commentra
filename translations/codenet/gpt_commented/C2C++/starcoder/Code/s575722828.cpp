#include <iostream>

using namespace std;

int main()
{
    // Declare an integer variable to store the total seconds
    int S;

    // Read the total seconds from user input
    cin >> S;

    // Calculate hours, minutes, and seconds from the total seconds
    // and print them in the format HH:MM:SS
    cout << (int)(S / 3600) << ":" << (int)((S % 3600) / 60) << ":" << S % 60 << endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}

