#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <iterator>
#include <sstream>

using namespace std;

vector<int> find(const string& s, char ch) {
    vector<int> indices;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ch) {
            indices.push_back(i);
        }
    }
    return indices;
}

int main() {
    int n;
    string s;
    cin >> n;
    cin.ignore(); // To ignore the newline character after the integer input
    getline(cin, s);

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
                    int distance = 2 + 2 * (abs(indices[i] - indices[j]) - 1) - (abs(indices[i] - indices[j]) - 1);
                    maximum = max(maximum, distance);
                }
            }
            cout << count(s.begin(), s.end(), '1') + maximum << endl;
        }
    }

    return 0;
}
