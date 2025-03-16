#include <iostream>
using namespace std;

int main()
{
    // Read two integers from input and assign them to variables a and b
    int a, b;
    cin >> a >> b;

    // Initialize the variable 'hole' to represent the current hole position
    int hole = 1;

    // Initialize a counter 'i' to track the number of iterations
    int i = 0;

    // Set a flag 'check' to control the while loop
    bool check = true;

    // Continue looping until the condition is met
    while (check)
    {
        // Check if the current hole position is greater than or equal to b
        if (hole >= b)
        {
            // If so, exit the loop
            check = false;
        }
        else
        {
            // Calculate the new hole position based on the formula
            hole = a * (i + 1) - i;

            // Increment the iteration counter
            i += 1;
        }
    }

    // Print the total number of iterations (i) when the loop ends
    cout << i << endl;

    return 0;
}

