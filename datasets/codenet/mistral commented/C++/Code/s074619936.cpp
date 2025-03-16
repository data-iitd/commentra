#include <iostream>
#include <stdlib.h>
using namespace std;

// Main function starts here
int main()
{
    // Initialize variables
    string str;
    string tmp;
    int sum;

    // Start an infinite loop
    while(1)
    {
        // Read a string from the user input
        cin >> str;

        // Check if the user wants to exit by entering "0"
        if(str == "0")
        {
            // Exit the loop if user enters "0"
            break;
        }

        // Initialize sum variable to zero
        sum = 0;

        // Iterate through each character in the string
        for(int i=0;i<str.size();i++)
        {
            // Get the character as a string
            tmp = str[i];

            // Convert the character to an integer and add it to the sum
            int num = atoi(tmp.c_str());
            sum += num;
        }

        // Print the sum of the digits in the string
        cout << sum << endl;
    }

    // Return 0 to indicate successful execution
    return 0;
}
