#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    // Read input from the user
    string l;
    cin >> l;

    // Split the input string into two parts using '.' as the delimiter
    stringstream ss(l);
    string s, p;
    getline(ss, s, '.');
    getline(ss, p, '.');

    // Convert the first part of the input into a list of characters
    vector<char> s_list(s.begin(), s.end());

    // Convert the second part of the input into a list of characters
    vector<char> p_list(p.begin(), p.end());

    // Extract the first character from the second part and convert it to an integer
    int i = p_list[0] - '0';

    // Check if the last character of the first part is '9'
    if (s_list[s_list.size() - 1] == '9')
    {
        // If it is '9', print the message "GOTO Vasilisa."
        cout << "GOTO Vasilisa." << endl;
    }
    // Check if the last character is not '9' and the integer i is less than 5
    else if (s_list[s_list.size() - 1] != '9' && i < 5)
    {
        // If both conditions are true, join the list of characters into a string and print it
        string s = "";
        for (int i = 0; i < s_list.size(); i++)
        {
            s += s_list[i];
        }
        cout << s << endl;
    }
    else
    {
        // If the last character is not '9' and i is 5 or more
        // Join the list of characters into a string, convert it to an integer, increment it by 1, and convert it back to a string
        string s = "";
        for (int i = 0; i < s_list.size(); i++)
        {
            s += s_list[i];
        }
        int s_int = stoi(s);
        s_int++;
        s = to_string(s_int);
        // Print the incremented value
        cout << s << endl;
    }

    return 0;
}

