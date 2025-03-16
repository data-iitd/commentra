#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Read input from the user and convert it to a string
    string s;
    cin >> s;

    // Initialize an empty string to store the resulting characters
    string my_str = "";

    // Iterate through each character in the input string
    for (int i = 0; i < s.length(); i++)
    {
        // Check if the character is '0' or '1'
        if (s[i] == '0' || s[i] == '1')
        {
            // If it is, append it to the result string
            my_str += s[i];
        }
        // Check if the character is 'B' and the result string is not empty
        else if (s[i] == 'B' && my_str.length() != 0)
        {
            // If it is, remove the last character from the result string
            my_str = my_str.substr(0, my_str.length() - 1);
        }
    }

    // Print the final result string
    cout << my_str << endl;

    return 0;
}

