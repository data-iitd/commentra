
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int pya; // Number of strings to be processed
    cin >> pya; // Read the number of strings to be processed

    string oString; // Original string
    cin >> oString; // Read the original string

    string letter1; // First letter of the original string
    cin >> letter1; // Read the first letter of the original string

    string letter2 = 'a'; // Second letter based on the first letter
    if (letter1.lower()!= 'a') {
        letter2 = 'b';
    }

    string x; // Current string
    set<int> setcito; // Set to store the indices of the strings in the original string
    for (int i = 0; i < pya; i++) {
        cin >> x; // Read the next string
        for (int j = 0; j < oString.length(); j++) {
            if (oString.substr(j, x.length()) == x) {
                for (int k = j; k < j + x.length(); k++) {
                    setcito.insert(k); // Add the index to the set
                }
            }
        }
    }

    string temp = oString; // Copy the original string
    for (auto it = setcito.begin(); it!= setcito.end(); it++) {
        char letter = letter1[0]; // Determine the letter to replace based on the first letter
        if (temp[*it] >= 'a' && temp[*it] <= 'z') {
            if (letter1[0] >= 'a' && letter1[0] <= 'z') {
                letter = letter1[0];
            } else {
                letter = letter1[0] - 32;
            }
        } else {
            if (letter1[0] >= 'a' && letter1[0] <= 'z') {
                letter = letter1[0] - 32;
            } else {
                letter = letter1[0];
            }
        }
        temp[*it] = letter; // Replace the letter with the determined letter
    }

    cout << temp << endl; // Print the modified string

    return 0;
}
