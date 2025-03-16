#include <iostream>

int main()
{
    // Initialize a counter variable 'i' to track the case number and an 'Input' variable to store user input
    int i = 1, Input;

    // Start an infinite loop to continuously accept user input
    while(1)
    {
        // Read an integer input from the user
        std::cin >> Input;

        // Check if the input is zero, which indicates the end of input
        if(Input == 0)
        {
            // Exit the loop if the input is zero
            break;
        }

        // Print the case number and the input value
        std::cout << "Case " << i << ": " << Input << std::endl;

        // Increment the case number for the next iteration
        i++;
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}

