
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Main method that starts the program
    int testNumber;
    cin >> testNumber;
    for (int i = 0; i < testNumber; i++) {
        // Loop through each test case

        string s;
        cin >> s;

        long cnt = 0;
        long tmp = 0;

        for (int j = 0; j < s.length(); j++) {
            // Loop through each character in the string

            if (s[j] == 'A') {
                // If the character is "A", increment the temporary counter
                tmp++;
            } else if (s[j] == 'D') {
                // If the character is "D", add the temporary counter to the total count
                cnt += tmp;
            } else {
                // If the character is neither "A" nor "D", reset the temporary counter
                tmp = 0;
            }
        }

        // Print the result
        cout << cnt << endl;
    }

    return 0;
}

