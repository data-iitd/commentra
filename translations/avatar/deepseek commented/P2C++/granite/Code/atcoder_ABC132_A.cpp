

#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;  // Take a string input from the user
    map<char, int> c;  // Create a map to store the frequency of each character
    set<char> Sa;  // Create a set to store the unique characters in the string S

    // Iterate over the string S and count the frequency of each character
    for (char i : S) {
        c[i]++;
        Sa.insert(i);
    }

    // Check if the number of unique characters is not equal to 2
    if (Sa.size()!= 2) {
        cout << "No" << endl;  // Print "No" and exit if the condition is true
        return 0;  // Exit the program
    }

    // Iterate over the set of unique characters and check if the frequency of each character is not equal to 2
    for (char i : Sa) {
        if (c[i]!= 2) {
            cout << "No" << endl;  // Print "No" and exit if the condition is true
            return 0;  // Exit the program
        }
    }

    cout << "Yes" << endl;  // Print "Yes" if all characters have a frequency of 2

    return 0;
}
