
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Define a list containing all the vowels in upper and lower case
    vector<char> vo = { 'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y' };

    // Take an input string 'a' from the user
    string a;
    getline(cin, a);

    // Iterate through the string 'a' from the end to the beginning
    for (int i = a.length() - 1; i >= 0; i--) {
        // If the current character is a space or a question mark, skip it and move on to the next character
        if (a[i] =='' || a[i] == '?') {
            continue;
        }
        // If the current character is not a space or a question mark, check if it is a vowel or not
        else {
            // Check if the current character is a vowel
            if (find(vo.begin(), vo.end(), a[i])!= vo.end()) {
                // If it is, print "YES" and break out of the loop
                cout << "YES" << endl;
                break;
            }
            // If it is not, print "NO" and break out of the loop
            else {
                cout << "NO" << endl;
                break;
            }
        }
    }

    return 0;
}

