#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    // Taking the number of sentences n as input
    int n;
    cin >> n;

    // Initializing the answer counter ans and the sum of lengths of sentences sumL
    int ans = 1, sumL = 0;

    // Loop to split the input string into sentences based on punctuation marks
    string s;
    while (getline(cin, s)) {
        // Stripping leading and trailing whitespaces from the sentence s
        s = regex_replace(s, regex("^\\s+|\\s+$"), "");
        // Adding a dot at the end of the sentence if it doesn't already have one
        s += '.';

        // Calculating the length L of the sentence s
        int L = s.length();

        // Checking if the length of the sentence is greater than the number of sentences n
        if (L > n) {
            // Printing an error message and exiting the program if the condition is true
            cout << "Impossible" << endl;
            return 0;
        }

        // Checking if the sum of lengths of all previous sentences and the current sentence is greater than n
        if (sumL + L + (sumL > 0)) {
            // Incrementing the answer counter ans if the condition is true
            ans++;
            // Updating the sum of lengths sumL with the length of the current sentence
            sumL = L;
        } else {
            // Updating the sum of lengths sumL with the length of the current sentence and the previous sentence's length if any
            sumL = sumL + L + (sumL > 0);
        }
    }

    // Printing the final answer
    cout << ans << endl;

    return 0;
}

