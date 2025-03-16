#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> find(const string& s, char ch) {
    vector<int> indices;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == ch) {
            indices.push_back(i);
        }
    }
    return indices;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (s.find('0') == string::npos) {
        cout << n - 1 << endl;
    } else {
        vector<int> indices = find(s, '0');
        if (indices.size() == 1) {
            cout << n << endl;
        } else {
            int maximum = 0;
            for (size_t i = 0; i < indices.size(); ++i) {
                for (size_t j = i + 1; j < indices.size(); ++j) {
                    int x0 = indices[i];
                    int x1 = indices[j];
                    maximum = max(maximum, 2 + 2 * (abs(static_cast<int>(i) - static_cast<int>(j)) - 1) - (abs(x0 - x1) - 1));
                }
            }
            cout << count(s.begin(), s.end(), '1') + maximum << endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
