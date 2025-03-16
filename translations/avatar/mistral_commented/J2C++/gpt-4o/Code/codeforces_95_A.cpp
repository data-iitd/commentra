#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Main {
public:
    // Method to compare two character arrays aa and bb starting from their respective indices i and j
    int compare(const string& aa, int i, const string& bb, int j, int m) {
        // Iterating through the character arrays until the length m is reached
        for (int k = 0; k < m; ++k) {
            char a = toupper(aa[i + k]); // Converting the characters to uppercase
            char b = toupper(bb[j + k]);

            if (a != b) // If characters are not equal, return the difference of their ASCII values
                return a - b;
        }
        // If all characters match, return 0
        return 0;
    }

    // Main method to read input and process it
    void main() {
        int n;
        cin >> n; // Reading the number of character arrays to be processed
        vector<string> ss(n); // Creating a vector to store the character arrays

        // Reading the character arrays and storing them in the vector
        for (int i = 0; i < n; i++) {
            cin >> ss[i];
        }

        string cc;
        cin >> cc; // Reading the character array to be compared with the input character arrays
        int m = cc.length(); // Finding the length of the character array cc

        char c;
        cin >> c; // Reading the character to be matched with the character array cc
        char c_ = toupper(c); // Converting the character to uppercase
        char a = (c == 'a') ? 'b' : 'a'; // Determining the character a based on the character c
        char a_ = toupper(a); // Converting the character a to uppercase

        vector<bool> lucky(m, false); // Creating a boolean vector to keep track of the matching indices in cc

        // Iterating through each character in cc and comparing it with all characters in each character array in ss
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int l = ss[i].length(); // Finding the length of the character array in ss at the current index i

                if (m - j >= l && compare(cc, j, ss[i], 0, l) == 0) { // Comparison logic
                    for (int h = 0; h < l; h++) { // Iterating through each character in the character array in ss at the current index i
                        lucky[j + h] = true; // Setting the boolean value at the current index j+h in lucky to true
                    }
                }
            }
        }

        // Iterating through each character in cc and updating it based on the boolean values in lucky
        for (int j = 0; j < m; j++) {
            if (lucky[j]) { // If the boolean value at the current index j in lucky is true
                if (tolower(cc[j]) == tolower(c)) { // If the character at the current index j in cc is equal to the character c in lowercase
                    cc[j] = isupper(cc[j]) ? a_ : a; // Update the character at the current index j in cc based on the character a
                } else {
                    cc[j] = isupper(cc[j]) ? c_ : c; // Update the character at the current index j in cc based on the character c
                }
            }
        }

        // Printing the updated character array cc
        cout << cc << endl;
    }
};

int main() {
    Main o; // Creating an instance of Main class
    o.main(); // Calling the main method of Main class
    return 0;
}

// <END-OF-CODE>
