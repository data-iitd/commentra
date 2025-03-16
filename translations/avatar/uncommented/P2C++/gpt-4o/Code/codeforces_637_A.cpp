#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline after the integer input
    string input;
    getline(cin, input);
    
    vector<string> s;
    size_t pos = 0;
    while ((pos = input.find(' ')) != string::npos) {
        s.push_back(input.substr(0, pos));
        input.erase(0, pos + 1);
    }
    s.push_back(input); // Add the last element

    unordered_map<string, int> w;
    for (const auto& word : s) {
        w[word]++;
    }

    reverse(s.begin(), s.end());
    string a;
    int c = -1;

    for (const auto& pair : w) {
        if (pair.second == max_element(w.begin(), w.end(), 
            [](const pair<string, int>& a, const pair<string, int>& b) {
                return a.second < b.second;
            })->second) {
            int index = find(s.begin(), s.end(), pair.first) - s.begin();
            if (index > c) {
                a = pair.first;
                c = index;
            }
        }
    }

    cout << a << endl;
    return 0;
}

// <END-OF-CODE>
