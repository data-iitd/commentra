#include <iostream>
#include <string>

using namespace std;

// Function to read a single integer from standard input
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read a single string from standard input
string readString() {
    string s;
    cin >> s;
    return s;
}

// Main function
int main() {
    // Reading input string and number of occurrences of '1' required
    string s = readString();
    int k = readInt();

    // Finding the length of the substring consisting only of '1's
    int l = 0;
    for (char c : s) {
        if (c != '1') {
            // If the length of the substring is greater than or equal to the required number of occurrences, return 1
            if (l >= k) {
                cout << 1 << endl;
                return 0;
            }
            break;
        }
        l++;
    }

    // If the length of the substring is less than the required number of occurrences, return the character after the substring
    cout << s[l] << endl;

    return 0;
}

// <END-OF-CODE>
