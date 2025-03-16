
#include <iostream> // Include the standard input/output library

int main()
{
    int i=1, Input; // Declare and initialize variables i and Input

    // Start an infinite loop
    while(1)
    {
        std::cin >> Input; // Read an integer from the user
        if(Input == 0)       // Check if the input is 0
        {
            break;           // Exit the loop if the input is 0
        }
        std::cout << "Case " << i << ": " << Input << std::endl; // Print the current case number and input value
        i++;                   // Increment the case number
    }
    return 0; // Return 0 to indicate successful execution
}
