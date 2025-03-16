#include <iostream> // Step 1: Include necessary headers

using namespace std; // Step 2: Use the standard namespace

int main() // Step 3: Define the main function
{
    int S; // Step 4: Declare an integer variable S

    cin >> S; // Step 5: Read an integer value from the user and store it in S

    cout << (int)(S / 3600) << ":" << (int)((S % 3600) / 60) << ":" << S % 60 << endl; // Step 6: Calculate hours, minutes, and seconds from the total seconds S
                                                                                        // Step 7: Print the calculated hours, minutes, and seconds in the format "HH:MM:SS"

    return 0; // Step 8: Return 0 to indicate successful execution
}

