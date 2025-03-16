#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string s;
    int l = 2019;
    cin >> s;

    vector<int> m(l, 0);
    int a = 0, r = 0;

    for (int i = 0; i < s.length(); ++i) {
        int e = s.length() - i - 1;
        a += (s[e] - '0') * pow(10, i);
        a %= l;
        m[a]++;
        r += m[a];
    }

    cout << r << endl;
    return 0;
}

