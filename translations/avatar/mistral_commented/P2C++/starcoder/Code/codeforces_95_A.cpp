#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    // Initialize variables
    int pya = 0; // Get the number of strings to be processed
    vector<string> arre; // Initialize an empty list to store the strings
    string oString; // Get the original string
    string letter1; // Get the first letter of the original string in lowercase
    string letter2; // Get the second letter of the original string in lowercase
    vector<int> valid; // Initialize a list of zeros with the length of the original string
    set<int> setcito; // Initialize an empty set

    // Process strings input
    cin >> pya; // Get the number of strings to be processed
    while (pya) {
        pya--; // Decrement pya by 1
        string x; // Initialize a string
        cin >> x; // Get the next string as a lowercase string
        arre.push_back(x); // Append the string to the list
    }

    // Get the original string and its first letter
    cin >> oString; // Get the original string
    cin >> letter1; // Get the first letter of the original string in lowercase

    // Determine the second letter based on the first letter
    letter2 = 'a' if letter1.lower()!= 'a' else 'b'; // If the first letter is not 'a', set the second letter to 'b'

    // Initialize a list of valid indices and a set to store the indices of the strings in the original string
    valid = vector<int>(oString.length(), 0); // Initialize a list of zeros with the length of the original string
    setcito = set<int>(); // Initialize an empty set

    // Find the indices of the strings in the original string
    for (string x : arre) {
        if (oString.find(x) >= 0) { // If the original string contains the current string
            for (int i = oString.find(x); i < oString.length(); i++) { // Iterate through the indices of the string in the original string
                setcito.insert(i); // Add the index to the set
            }
        }
    }

    // Replace the letters in the original string based on the indices of the strings
    for (int i : setcito) {
        letter1 = tolower(letter1[0]); // Convert the first letter to lowercase
        letter2 = tolower(letter2[0]); // Convert the second letter to lowercase
        if (oString[i] == letter1) {
            oString[i] = letter2; // Replace the letter with the second letter, preserving the case
        } else if (oString[i] == letter2) {
            oString[i] = letter1; // Replace the letter with the first letter, preserving the case
        }
    }

    // Print the modified string
    for (char x : oString) {
        cout << x; // Print each character of the modified string
    }
    cout << endl; // Print a newline after the modified string

    return 0;
}

