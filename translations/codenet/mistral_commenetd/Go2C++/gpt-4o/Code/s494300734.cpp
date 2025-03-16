// Include necessary headers
#include <iostream>
#include <string>

using namespace std;

// Entry point of the program
int main() {
    // Initialize a variable s of type string and read a string input from the standard input
    string s;
    cin >> s;

    // Initialize a variable ans with the string value "No"
    string ans = "No";

    // Check if the index of the substring "C" in the string s is less than the index of the substring "F"
    size_t indexC = s.find("C");
    size_t indexF = s.rfind("F");
    
    if (indexC != string::npos && indexC < indexF) {
        // If it is, then change the value of ans to "Yes"
        ans = "Yes";
    }

    // Check if the index of the substring "C" in the string s is less than 0
    if (indexC == string::npos) {
        // If it is, then do not change the value of ans
    }

    // Print the value of ans to the standard output
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
