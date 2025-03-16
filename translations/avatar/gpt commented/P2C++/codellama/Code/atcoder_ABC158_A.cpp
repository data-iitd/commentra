#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Read input from the standard input (user input)
    string s;
    cin >> s;

    // Check if both 'A' and 'B' are present in the input string
    // If both are found, set result to "Yes", otherwise set it to "No"
    string result = (s.find("A") != string::npos && s.find("B") != string::npos) ? "Yes" : "No";

    // Print the result indicating whether both 'A' and 'B' were found
    cout << result << endl;

    return 0;
}

