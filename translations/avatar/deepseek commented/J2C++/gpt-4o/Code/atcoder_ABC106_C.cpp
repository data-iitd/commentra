#include <iostream>
#include <string>

using namespace std;

int main() {
    string str; // Step 1: Read input from the user
    cin >> str; // Step 2: Read the input string
    long k; // Step 4: Read the value of k
    cin >> k; // Step 4: Read the value of k
    int n = str.length(); // Step 5: Initialize the length of the string

    for (int i = 0; i < k; i++) { // Step 6: Loop through the character array k times
        if (str[i] == '1') { // Step 7: Check if the character at the current index is '1'
            if (i == k - 1) { // Step 8: Check if the current index is the last index
                cout << 1 << endl; // Step 9: Print '1' and return
                return 0;
            }
        } else { // Step 10: If it is not '1'
            cout << str[i] << endl; // Step 11: Print the character and return
            return 0;
        }
    }
    return 0;
}

// <END-OF-CODE>
