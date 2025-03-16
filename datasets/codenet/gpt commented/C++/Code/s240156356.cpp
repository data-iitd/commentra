#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Declare two strings to hold the input
    string str1, str2;
    
    // Read two strings from the standard input
    cin >> str1 >> str2;

    // Sort the first string in ascending order
    sort(str1.begin(), str1.end());
    
    // Sort the second string in descending order
    sort(str2.rbegin(), str2.rend());

    // Determine the length of the shorter string for the loop
    int loop = str1.length() > str2.length() ? str2.length() : str1.length();
    
    // Initialize a flag to track if the condition is met
    bool flag = false;

    // Loop through the characters of both strings up to the length of the shorter one
    for (int i = 0; loop > i; i++) {
        char ch1 = str1[i]; // Get the character from the first string
        char ch2 = str2[i]; // Get the character from the second string

        // Check if the characters are equal
        if (ch1 == ch2) {
            // If we are at the last character of the shorter string and str1 is shorter
            if (loop == i + 1 && str1.length() < str2.length()) {
                flag = true; // Set the flag to true
                break; // Exit the loop
            } else {
                continue; // Continue to the next iteration
            }
        } else {
            // If the character from str2 is greater than that from str1
            if (ch2 > ch1) {
                flag = true; // Set the flag to true
                break; // Exit the loop
            } else {
                break; // Exit the loop if ch1 is greater
            }
        }
    }

    // Output the result based on the flag's value
    if (flag) {
        cout << "Yes" << endl; // Condition met
    } else {
        cout << "No" << endl; // Condition not met
    }
}
