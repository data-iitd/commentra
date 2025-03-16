#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int c = 0;
    for (int i = 0; i < n; i++) {
        vector<int> l1;
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            l1.push_back(s[j] - '0');
        }
        if (accumulate(l1.begin(), l1.end(), 0) > 1) {
            c++;
        }
    }
    cout << c << endl;
    return 0;
}

