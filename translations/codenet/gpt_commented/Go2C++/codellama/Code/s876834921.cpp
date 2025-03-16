
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Declare a string variable to hold user input
    string s;
    
    // Read input from the user
    cin >> s;
    
    // Replace occurrences of "dream" with "D"
    replace(s.begin(), s.end(), "dream", "D");
    
    // Replace occurrences of "erase" with "E"
    replace(s.begin(), s.end(), "erase", "E");
    
    // Remove occurrences of "Der" from the string
    s.erase(remove(s.begin(), s.end(), "Der"), s.end());
    
    // Remove occurrences of "Er" from the string
    s.erase(remove(s.begin(), s.end(), "Er"), s.end());
    
    // Remove occurrences of "D" from the string
    s.erase(remove(s.begin(), s.end(), "D"), s.end());
    
    // Remove occurrences of "E" from the string
    s.erase(remove(s.begin(), s.end(), "E"), s.end());
    
    // Trim any leading or trailing whitespace from the string
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
        return !isspace(ch);
    }));
    s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), s.end());

    // Check if the resulting string is empty
    if (s.empty()) {
        // If the string is empty, print "YES"
        cout << "YES" << endl;
    } else {
        // If the string is not empty, print "NO"
        cout << "NO" << endl;
    }

    return 0;
}

