
#include <iostream> // Step 1: Include necessary headers

int main() // Step 2: Define the main function
{
    int S; // Step 3: Declare an integer variable S

    std::cin >> S; // Step 4: Read an integer value from the user and store it in S

    std::cout << (int)(S / 3600) << ":" << (int)((S % 3600) / 60) << ":" << S % 60 << std::endl; // Step 5: Calculate hours, minutes, and seconds from the total seconds S
                                                                                                     // Step 6: Print the calculated hours, minutes, and seconds in the format "HH:MM:SS"

    return 0; // Step 7: Return 0 to indicate successful execution
}

