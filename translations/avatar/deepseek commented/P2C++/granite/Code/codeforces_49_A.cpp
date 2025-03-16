

#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    getline(cin, a);  // Take an input from the user
    string vo = "aeiouyAEIOUY";  // Define a string of vowels

    // Iterate over the input string in reverse order
    for (int i = a.length() - 1; i >= 0; i--) {
        if (a[i] =='' || a[i] == '?') {  // Check if the current character is a space or a question mark
            continue;  // Continue to the next iteration
        } else {
            if (vo.find(a[i])!= string::npos) {  // Check if the current character is a vowel
                cout << "YES" << endl;  // Print "YES" if the character is a vowel
            } else {
                cout << "NO" << endl;  // Print "NO" if the character is not a vowel and break the loop
            }
            break;  // Break the loop after printing the result
        }
    }

    return 0;
}

