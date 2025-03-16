#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    // Declare variables to hold input string, temporary string for individual characters, and the sum of digits
    string str;
    string tmp;
    int sum;

    // Infinite loop to continuously accept input until "0" is entered
    while(1)
    {
        // Read input from the user
        cin >> str;

        // Check if the input is "0", if so, exit the loop
        if(str == "0") break;

        // Initialize sum to 0 for the new input string
        sum = 0;

        // Loop through each character in the input string
        for(int i = 0; i < str.size(); i++)
        {
            // Convert the character to a string
            tmp = str[i];

            // Convert the string character to an integer
            int num = atoi(tmp.c_str());

            // Add the integer value to the sum
            sum += num;
        }
        
        // Output the sum of the digits for the current input string
        cout << sum << endl;
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}
