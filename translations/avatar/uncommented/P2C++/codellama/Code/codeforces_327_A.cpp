#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> find(string s, char ch) {
    vector<int> indices;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ch) {
            indices.push_back(i);
        }
    }
    return indices;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    if (s.find('0') == string::npos) {
        cout << n - 1 << endl;
    } else {
        vector<int> indices = find(s, '0');
        if (indices.size() == 1) {
            cout << n << endl;
        } else {
            int maximum = 0;
            for (int i = 0; i < indices.size() - 1; i++) {
                for (int j = i + 1; j < indices.size(); j++) {
                    int diff = abs(indices[i] - indices[j]) - 1;
                    maximum = max(maximum, 2 + 2 * diff - (indices[j] - indices[i]));
                }
            }
            cout << s.count('1') + maximum << endl;
        }
    }
    return 0;
}

