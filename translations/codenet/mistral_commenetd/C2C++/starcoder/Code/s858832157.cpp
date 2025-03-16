#include <iostream>

using namespace std;

int main()
{
    // Declare and initialize variables
    int i = 1; // Initialize counter variable i to 1
    int Input; // Declare variable to store user input

    while(1)
    {
        // Read user input and store it in the Input variable
        cin >> Input;

        // Check if user input is 0
        if(Input == 0)
        {
            // If user input is 0, break out of the loop
            break;
        }

        // Print the case number and user input
        cout << "Case " << i << ": " << Input << endl;

        // Increment the counter variable i
        i++;
    }

    // Return 0 to indicate successful execution of the program
    return 0;
}

