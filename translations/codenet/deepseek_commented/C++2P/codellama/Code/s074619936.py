#include <iostream>
#include <stdlib.h> // Include the standard library for atoi function
using namespace std;

int main()
{
    string str; // Declare a string variable to store user input
    string tmp; // Declare a temporary string variable for character conversion
    int sum; // Declare an integer variable to store the sum of digits

    # Infinite loop that continues until the user inputs "0"
    while(1):
        cin >> str; // Read a string from the user
        if(str == "0"): break; // If the input string is "0", break the loop
        sum = 0; // Initialize sum to 0
        for(int i=0;i<str.size();i++):
            tmp = str[i]; // Convert the character to a string
            int num = atoi(tmp.c_str()); // Convert the string to an integer
            sum += num; // Add the integer to the sum
        
        cout << sum << endl; // Print the sum
    return 0; // Return 0 to indicate successful execution
}

