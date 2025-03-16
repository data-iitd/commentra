#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

int main() {
    int n;
    cin >> n;

    string input;
    cin.ignore();  // To ignore the newline character after the integer input
    getline(cin, input);  // Read the entire line of text

    int ans = 1, sumL = 0;

    regex re("[.?!]");  // Regular expression to split sentences
    sregex_token_iterator iter(input.begin(), input.end(), re, {0, -1});
    sregex_token_iterator end;

    while (iter != end) {
        string s = *iter;
        s = regex_replace(s, regex("^\\s+|\\s+$"), "");  // Trim whitespace
        s += '.';  // Add a period to the end of the sentence
        int L = s.length();  // Calculate the length of the current sentence

        if (L > 1) {
            if (L > n) {
                cout << "Impossible" << endl;
                return 0;
            }

            if (sumL + L + (sumL > 0) > n) {
                ans++;
                sumL = L;
            } else {
                sumL = sumL + L + (sumL > 0);
            }
        }
        iter++;
    }

    cout << ans << endl;

    return 0;
}

