#include <iostream>
#include <cstdlib>

// Main function starts here
int main()
{
    int a, c, k, b; // Declare variables a, c, k, and b of type int

    // Loop to read input values from the standard input
    while(~std::cin >> a)
    {
        // Initialize c and k to zero
        c = 0;
        k = 0;

        // Check if the input value is less than 3
        if (a < 3)
        {
            // If yes, print 0 and exit the loop
            std::cout << "0\n";
            break;
        }

        // Assign the value of input 'a' to variable 'b'
        b = a;

        // Loop to process each digit of the input number 'a'
        while (a--)
        {
            // Decrement the value of 'b' by 1
            b--;

            // Increment the value of 'c' by 1
            c++;

            // Check if the value of 'c' is equal to 3
            if (c == 3)
            {
                // If yes, increment the value of 'k' by 1 and reset the value of 'c' to zero
                k++;
                c = 0;
            }
        }

        // Print the value of 'k' as the output
        std::cout << k << "\n";
    }

    // Main function ends here
    return 0;
}

