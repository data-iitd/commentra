#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main() {
    string S;
    cin >> S;  // Take a string input from the user
    unordered_map<char, int> c;  // Count the frequency of each character in the string S
    unordered_set<char> Sa;  // Convert the string S into a set of unique characters

    // Count the frequency of each character
    for (char ch : S) {
        c[ch]++;
    }

    // Convert the string to a set of unique characters
    for (char ch : S) {
        Sa.insert(ch);
    }

    // Check if the number of unique characters is not equal to 2
    if (Sa.size() != 2) {
        cout << "No" << endl;  // Print "No" and exit if the condition is true
        return 0;  // Exit the program
    }

    // Iterate over the set of unique characters and check if the frequency of each character is not equal to 2
    for (char ch : Sa) {
        if (c[ch] != 2) {
            cout << "No" << endl;  // Print "No" and exit if the condition is true
            return 0;  // Exit the program
        }
    }

    cout << "Yes" << endl;  // Print "Yes" if all characters have a frequency of 2
    return 0;  // Exit the program
}

