
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Take user input as a string's'
    string s;
    getline(cin, s);

    // Initialize an empty list'res' to store the final result
    vector<string> res;

    // Define a list 'punctuation' containing all the punctuation marks
    vector<char> punctuation = { ',', '.', '!', '?' };

    // Iterate through each character 'i' in the string's'
    for (int i = 0; i < s.length(); i++) {

        // If current character is a space and previous character is not empty,
        // append the space to the result list
        if (i >= 1) {
            if (s[i] =='') {
                if (res[res.size() - 1]!= "") {
                    // Append space to the result list
                    res.push_back(s[i]);
                }
                else {
                    continue;
                }
            }
        }

        // If current character is not a space and is a punctuation mark,
        // check if the previous character is empty, if yes then pop the last character from the result list
        // and append the current punctuation mark along with an empty string
        else if (find(punctuation.begin(), punctuation.end(), s[i])!= punctuation.end()) {
            if (res[res.size() - 1] == "") {
                res.pop_back();
                res.push_back(string(1, s[i]));
                res.push_back("");
            }
            else {
                res.push_back(string(1, s[i]));
            }
        }

        // If current character is not a space and is not a punctuation mark,
        // simply append it to the result list
        else {
            res.push_back(string(1, s[i]));
        }
    }

    // Join all the elements of the result list and print the final string
    string finalString = "";
    for (int i = 0; i < res.size(); i++) {
        finalString += res[i];
    }
    cout << finalString << endl;

    return 0;
}
