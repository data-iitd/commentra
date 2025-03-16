#include <iostream>
#include <string>
#include <cmath>
#include <bitset>

using namespace std;

int main()
{
    // Declare a string variable to hold the input
    string source = "";
    // Read input from the user
    cin >> source;

    // Check if the input length is valid (between 1 and 10 characters)
    if(source.length() > 10 || source.length() < 1)
    {
        // Return -1 if the input length is invalid
        return -1;
    }

    // Calculate the maximum number of combinations of '+' placements
    int max_i = static_cast<int>(pow(2, source.length() - 1));

    // Initialize a variable to hold the cumulative sum of the evaluated expressions
    double sum = 0;

    // Iterate through all possible combinations of '+' placements
    for (int i = 0; i < max_i; ++i)
    {
        // Create a bitset to represent the current combination of '+' placements
        bitset<100> plus(i);

        // Initialize a variable to hold the current number being evaluated
        double number = 0;

        // Create a working copy of the source string to manipulate
        string working = source;
        // While there are still '+' placements to evaluate
        while(plus.any())
        {
            int i = 0;
            // Find the next position of a '1' in the bitset
            while(!plus[i]) ++i;
            // Convert the substring up to the current position to a double and add to sum
            sum += atof(working.substr(0, i + 1).c_str());
            // Shift the bitset to the right to evaluate the next segment
            plus >>= i + 1;
            // Update the working string to remove the processed segment
            working = working.substr(i + 1);
        }
        // Add the remaining part of the working string to the sum
        sum += atof(working.c_str());
    }

    // Set the precision for output and print the final sum
    cout.precision(0);
    cout << fixed << sum << endl;

    return 0;
}
