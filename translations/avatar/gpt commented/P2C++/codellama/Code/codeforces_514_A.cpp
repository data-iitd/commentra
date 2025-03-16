#include <iostream>
using namespace std;

int main()
{
    // Get user input
    string ip;
    cin >> ip;

    // Initialize an empty string to store the transformed number
    string st = "";

    // Check if the input length is not equal to 1
    if (ip.length() != 1)
    {
        // If the first character is '9', keep it and remove it from the input
        if (ip[0] == '9')
        {
            st = "9";  // Start the output string with '9'
            ip.erase(0, 1);  // Remove the first character from the input
        }

        // Iterate through each character in the remaining input
        for (int i = 0; i < ip.length(); i++)
        {
            // If the digit is greater than 4, calculate its complement to 9
            if (ip[i] > '4')
            {
                int n = 9 - ip[i];  // Calculate the complement
                st += to_string(n);  // Append the complement to the output string
            }
            else
            {
                // If the digit is 4 or less, keep it unchanged
                st += ip[i];  // Append the original digit to the output string
            }
        }
    }
    else
    {
        // If the input length is 1, simply assign it to the output
        st = ip;
    }

    // Print the final transformed number as an integer
    cout << stoi(st) << endl;

    return 0;
}

