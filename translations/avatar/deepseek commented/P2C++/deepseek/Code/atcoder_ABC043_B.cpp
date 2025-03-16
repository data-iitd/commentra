#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    string my_str;

    // Take a string input from the user
    cin >> s;

    // Iterate over each character in the input string `s`
    for (char c : s) {
        if (c == '0' || c == '1') {  // Check if the character is '0' or '1'
            my_str += c;  // Append the character to `my_str`
        } else if (c == 'B' && !my_str.empty()) {  // Check if the character is 'B' and `my_str` is not empty
            my_str.pop_back();  // Remove the last character from `my_str`
        }
    }

    // Print the content of `my_str`
    cout << my_str << endl;

    return 0;
}
