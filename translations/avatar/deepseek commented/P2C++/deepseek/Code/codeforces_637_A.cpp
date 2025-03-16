#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after the integer input
    string s;
    getline(cin, s);

    // Remove the trailing space and split the string into a vector of strings
    vector<string> words;
    string word;
    for (char c : s) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    // Create an unordered_map to count the occurrences of each string
    unordered_map<string, int> w;
    for (const string& word : words) {
        w[word]++;
    }

    // Reverse the vector of strings
    reverse(words.begin(), words.end());

    // Initialize variables c and a to -1 and 0 respectively
    int c = -1, a = 0;

    // Iterate over the unordered_map to find the most frequent string
    for (const auto& pair : w) {
        if (pair.second == w.size()) {
            // Check if the index of the string in the reversed vector is greater than the current value of c
            auto it = find(words.begin(), words.end(), pair.first);
            if (it != words.end() && distance(words.begin(), it) > c) {
                // Update the value of a to the current string and update the value of c to the index of the current string in the reversed vector
                a = pair.first;
                c = distance(words.begin(), it);
            }
        }
    }

    // Print the value of a
    cout << a << endl;

    return 0;
}
