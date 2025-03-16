#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Ask the user for a string input
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    // Initialize an empty string variable to store the binary string
    string my_str = "";

    // Iterate through each character in the user input string
    for (int i = 0; i < s.length(); i++)
    {
        // If the character is '0' or '1', append it to the binary string
        if (s[i] == '0' || s[i] == '1')
        {
            my_str += s[i];
        }
        // If the character is 'B', remove the last character from the binary string before 'B' was encountered
        else if (s[i] == 'B' && my_str.length() != 0)
        {
            my_str = my_str.substr(0, my_str.length() - 1);
        }
    }

    // Print the final binary string
    cout << my_str << endl;

    return 0;
}

