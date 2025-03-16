#include <iostream>
#include <string>

using namespace std;

// Function to search the range of 'R' and 'L' in the given text
// S....M....E
// R...RL...LR
void searchRange(const string &text, int start, int limit, int &middle, int &end) {
    middle = -1; // Initialize middle to -1

    for (int i = start; i < limit; i++) {
        if (text[i] != 'R') { // Check if current character is not 'R'
            middle = i; // If not, then set middle to current index
            break; // and break the loop
        }
    }

    end = limit; // Initialize end to limit

    for (int i = middle; i < limit; i++) {
        if (text[i] != 'L') { // Check if current character is not 'L'
            end = i; // If not, then set end to current index
            break; // and break the loop
        }
    }
}

// Function to print the answer
void answer() {
    string text; // Initialize text as empty string
    cin >> text; // Read text from standard input
    int limit = text.length(); // Get length of text

    int start = 0; // Initialize start index to 0
    int middle = 0; // Initialize middle index to 0
    int end = 0; // Initialize end index to 0
    bool firstPrinted = false; // Initialize firstPrinted to false

    while (end < limit) { // Loop until end is less than limit
        searchRange(text, start, limit, middle, end); // Call searchRange function to find the range of 'R' and 'L'

        int len1 = middle - start; // Calculate length of first substring
        int len2 = end - middle; // Calculate length of second substring

        // Print the first substring
        for (int i = start; i < middle; i++) {
            if (firstPrinted) { // Check if firstPrinted is true
                cout << " "; // Print a space if true
            }
            cout << "0"; // Print '0' for each character in the first substring
            firstPrinted = true; // Set firstPrinted to true
        }

        // Print the count of 'R' and 'L' in the first and second substrings
        if (firstPrinted) { // Check if firstPrinted is true
            cout << " "; // Print a space if true
        }
        cout << (len1 / 2 + len2 / 2) << " " << (len1 / 2 + (len2 + 1) / 2); // Print the count of 'R' and 'L' in the first and second substrings
        firstPrinted = true; // Set firstPrinted to true

        // Print the second substring
        for (int i = middle + 1; i < end; i++) {
            if (firstPrinted) { // Check if firstPrinted is true
                cout << " "; // Print a space if true
            }
            cout << "0"; // Print '0' for each character in the second substring
            firstPrinted = true; // Set firstPrinted to true
        }
        start = end; // Set start to end
        firstPrinted = true; // Set firstPrinted to true
    }
    cout << endl; // Print newline at the end
}

// Main function to call answer function
int main() {
    answer(); // Call answer function
    return 0;
}

// <END-OF-CODE>
