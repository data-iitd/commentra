#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int l = 2019;
    vector<int> m(l + 1, 0);
    m[0] = 1;
    int a = 0, r = 0;
    for (int i = 0; i < s.size(); i++) {
        a += (s[i] - '0') * pow(10, i, l);
        m[a % l] += 1;
        r += m[a % l];
    }
    cout << r << endl;
    return 0;
}

