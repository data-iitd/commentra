#include <iostream>  // Including necessary libraries
#include <unordered_map>  // For using unordered_map
#include <string>  // For using string
using namespace std;

int main() {
    int N;  // Variable to store the number of strings
    cin >> N;  // Reading the number of strings from the input

    unordered_map<int, string> map;  // Creating an empty unordered_map to store strings

    for (int i = 0; i < N; i++) {  // Loop to read strings from the input and store them in the unordered_map
        string str;
        cin >> str;
        map[i] = str;
    }

    bool ans = true;  // Initializing a boolean variable to store the result of the check
    unordered_map<int, string> past;  // Creating an empty unordered_map to store the previous strings
    string next = "";  // Initializing a string variable to store the next character of the current string

    for (int i = 0; i < N; i++) {  // Loop to check for the condition
        if (past.count(i) > 0 && past[i] == map[i]) {  // Checking if the current string is already in the unordered_map
            ans = false;
            break;
        }
        past[i] = map[i];  // Storing the current string in the unordered_map

        if (i != 0) {  // Checking if it's not the first iteration of the loop
            if (next != map[i].substr(0, 1)) {  // Checking if the current string starts with the same character as the previous string
                ans = false;
                break;
            }
        }
        next = map[i].substr(map[i].length() - 1, 1);  // Storing the last character of the current string in the next variable
    }

    if (ans) {  // Printing "Yes" if the condition is satisfied
        cout << "Yes" << endl;
    } else {  // Printing "No" if the condition is not satisfied
        cout << "No" << endl;
    }

    return 0;  // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
