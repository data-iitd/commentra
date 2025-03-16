#include <iostream> // Including iostream for input and output
#include <unordered_map> // Including unordered_map for storing character and their frequency
#include <string> // Including string for using string class

using namespace std;

int main() {
    string s; // Declaring a string variable to store user input
    cin >> s; // Reading a string input from user

    unordered_map<char, int> map; // Creating an empty unordered_map to store character and their frequency

    for (char currentChar : s) { // Iterating through each character in the string
        map[currentChar]++; // Incrementing the frequency of the current character in the unordered_map
    }

    bool ok = true; // Initializing a boolean variable to check if all characters have frequency 2 or not

    for (const auto& c : map) { // Iterating through each entry in the unordered_map
        char key = c.first; // Assigning the character to a variable
        int value = c.second; // Assigning the frequency to a variable

        if (value != 2) { // Checking if the frequency of the current character is not 2
            ok = false; // Setting the boolean variable to false if any character has frequency other than 2
            break; // Exiting the loop if any character has frequency other than 2
        }
    }

    if (ok && map.size() == 2) { // Checking if all characters have frequency 2 and the size of the unordered_map is 2
        cout << "Yes" << endl; // Printing "Yes" if both conditions are true
    } else {
        cout << "No" << endl; // Printing "No" if any character has frequency other than 2 or the size of the unordered_map is not 2
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
