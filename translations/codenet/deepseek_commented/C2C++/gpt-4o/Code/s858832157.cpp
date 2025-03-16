#include <iostream> // Include the iostream library for input/output

int main()
{
    int i = 1, Input; // Declare and initialize variables i and Input

    // Start an infinite loop
    while (true)
    {
        std::cin >> Input; // Read an integer from the user
        if (Input == 0)    // Check if the input is 0
        {
            break;         // Exit the loop if the input is 0
        }
        std::cout << "Case " << i << ": " << Input << std::endl; // Print the current case number and input value
        i++;               // Increment the case number
    }
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
