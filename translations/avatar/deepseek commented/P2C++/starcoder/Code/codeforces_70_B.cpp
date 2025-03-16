
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Take the maximum sentence length as input
    int n;
    cin >> n;

    // Initialize variables to keep track of the number of sentences and their cumulative length
    int ans = 1, sumL = 0;

    // Take a string input and split it into sentences using the regular expression [.?!]
    for (string s; getline(cin, s);) {
        // Strip leading and trailing whitespace and add a period to the end of the sentence
        s = regex_replace(s, regex("^\\s+|\\s+$"), "");
        s += ".";
        // Calculate the length of the sentence
        int L = s.length();

        // Check if the sentence length is greater than 1
        if (L > 1) {
            // Check if the sentence length is greater than the maximum allowed length
            if (L > n) {
                // If the sentence is too long, print "Impossible" and exit
                cout << "Impossible" << endl;
                return 0;
            }

            // Check if adding the current sentence would exceed the maximum allowed length
            if (sumL + L + (sumL > 0) > n) {
                // If adding the sentence would exceed the maximum length, increment the sentence count
                ans++;
                // Reset the cumulative length to the length of the current sentence
                sumL = L;
            } else {
                // Otherwise, add the length of the current sentence to the cumulative length
                sumL = sumL + L + (sumL > 0);
            }
        }
    }

    // Print the total number of sentences
    cout << ans << endl;

    return 0;
}

