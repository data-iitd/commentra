// Including necessary header files
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Variable declaration and initialization
    int n;
    string s;

    // Reading input from the user
    cin >> n >> s;

    // Variable declaration and initialization for maximum count and current count
    int max = 0;
    int cnt = 0;

    // Iterating through each character in the string 's'
    for (char r : s) {
        // Checking if the character is 'I'
        if (r == 'I') {
            // Incrementing the current count
            cnt++;
        } else {
            // Decrementing the current count
            cnt--;
        }

        // Updating the maximum count if the current count is greater
        if (cnt > max) {
            max = cnt;
        }
    }

    // Printing the maximum count
    cout << max << endl;

    return 0;
}

// <END-OF-CODE>
