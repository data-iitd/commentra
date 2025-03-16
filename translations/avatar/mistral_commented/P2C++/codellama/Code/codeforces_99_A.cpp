#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    // Get the input string from the user
    string l;
    cin >> l;

    // Split the input string using '.' as delimiter and store the list in 'l'
    stringstream ss(l);
    string s, p;
    getline(ss, s, '.');
    getline(ss, p, '.');

    // Extract the first and second parts of the list and store them in 's' and 'p' respectively
    stringstream ss1(s);
    stringstream ss2(p);
    string s1, p1;
    getline(ss1, s1, '.');
    getline(ss2, p1, '.');

    // Get the last character of the string 's' and store it in a variable 'last_char'
    char last_char = s1[s1.length() - 1];

    // Check if the last character of the string 's' is '9'
    if (last_char == '9')
    {
        // If yes, print the message "GOTO Vasilisa."
        cout << "GOTO Vasilisa." << endl;
    }

    // Else, if the last character is not '9' and the integer value of the first part of 'p' is less than 5
    else if (last_char != '9' && stoi(p1) < 5)
    {
        // Concatenate all the characters of 's' to form a string
        string s2 = s1;
        // Print the string 's'
        cout << s2 << endl;
    }

    // Else, if the last character is not '9' and the integer value of the first part of 'p' is greater than or equal to 5
    else
    {
        // Concatenate all the characters of 's' to form a string
        string s2 = s1;
        // Increment the last character of the string 's' by 1
        s2[s2.length() - 1] = s2[s2.length() - 1] + 1;
        // Print the updated string 's'
        cout << s2 << endl;
    }

    return 0;
}

