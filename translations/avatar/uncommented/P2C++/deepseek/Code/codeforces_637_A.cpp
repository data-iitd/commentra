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
    vector<string> tokens;
    string token;
    for (char c : s) {
        if (c == ' ') {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token += c;
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    unordered_map<string, int> w;
    for (const string& word : tokens) {
        w[word]++;
    }
    reverse(tokens.begin(), tokens.end());
    int c = -1, a = 0;
    for (const string& word : tokens) {
        if (w[word] == *max_element(w.begin(), w.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second < b.second;
        })) {
            if (find(tokens.begin(), tokens.end(), word) > tokens.begin() + c) {
                a = word;
                c = find(tokens.begin(), tokens.end(), word) - tokens.begin();
            }
        }
    }
    cout << a << endl;
    return 0;
}
