#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

class Main {
public:
    Main() {
        // Constructor for creating an instance of Main class and setting output stream to cout
        out = &cout;
        autoFlush = true;
    }

    void print(const vector<char>& cc) {
        for (char c : cc) {
            *out << c;
        }
        if (autoFlush) {
            flush();
        }
    }

    void println(const vector<char>& cc) {
        print(cc);
        *out << endl;
    }

    void flush() {
        *out << flush;
    }

private:
    ostream* out;
    bool autoFlush;
};

int compare(const vector<char>& aa, int i, const vector<char>& bb, int j, int m) {
    // Iterating through the character arrays until the length m is reached
    while (m-- > 0) {
        char a = toupper(aa[i]); // Converting the characters to uppercase
        char b = toupper(bb[j]);

        if (a != b) // If characters are not equal, return the difference of their ASCII values
            return a - b;

        i++; // Incrementing the index i in aa
        j++; // Incrementing the index j in bb
    }

    // If all characters match, return 0
    return 0;
}

int main() {
    Main o; // Creating an instance of Main class
    int n;
    cin >> n; // Reading the number of character arrays to be processed
    vector<vector<char>> ss(n); // Creating a 2D vector to store the character arrays

    // Reading the character arrays and storing them in the 2D vector
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ss[i] = vector<char>(s.begin(), s.end());
    }

    vector<char> cc(256); // Reading the character array to be compared with the input character arrays
    cin >> cc[0];
    int m = cc.size(); // Finding the length of the character array cc

    char c;
    cin >> c; // Reading the character to be matched with the character array cc
    char c_ = toupper(c); // Converting the character to uppercase
    char a = c == 'a' ? 'b' : 'a'; // Determining the character a based on the character c
    char a_ = toupper(a); // Converting the character a to uppercase

    vector<bool> lucky(m, false); // Creating a boolean vector to keep track of the matching indices in cc

    // Iterating through each character in cc and comparing it with all characters in each character array in ss
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int l = ss[i].size(); // Finding the length of the character array in ss at the current index i

            if (m - j >= l && compare(cc, j, ss[i], 0, l) == 0) { // If the length of cc minus the current index j is greater than or equal to the length of the character array in ss at the current index i, and if the comparison of the substrings starting from the current indices in cc and ss returns 0, then set the boolean value at the current index j in lucky to true
                for (int h = 0; h < l; h++) { // Iterating through each character in the character array in ss at the current index i
                    lucky[j + h] = true; // Setting the boolean value at the current index j+h in lucky to true
                }
            }
        }
    }

    // Iterating through each character in cc and updating it based on the boolean values in lucky
    for (int j = 0; j < m; j++) {
        if (lucky[j]) { // If the boolean value at the current index j in lucky is true
            if (tolower(cc[j]) == c) { // If the character at the current index j in cc is equal to the character c in lowercase
                cc[j] = isupper(cc[j]) ? a : a_; // Update the character at the current index j in cc based on the character a
            } else {
                cc[j] = isupper(cc[j]) ? c_ : c; // Update the character at the current index j in cc based on the character c
            }
        }
    }

    // Printing the updated character array cc
    o.println(cc);

    return 0;
}
