#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    string my_str;

    // Ask the user for a string input
    cin >> s;

    // Iterate through each character in the user input string
    for (char c : s) {
        // If the character is '0' or '1', append it to the binary string
        if (c == '0' || c == '1') {
            my_str += c;
        }
        // If the character is 'B', remove the last character from the binary string before 'B' was encountered
        else if (c == 'B' && !my_str.empty()) {
            my_str.pop_back();
        }
    }

    // Print the final binary string
    cout << my_str << endl;

    return 0;
}
