#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int l = 2019;
    vector<int> m(l + 1, 1);
    int a = 0, r = 0;
    for (int i = 0; i < s.length(); i++) {
        a += (int)(s[i] - '0') * pow(10, i, l);
        r += m[a % l];
        m[a % l]++;
    }
    cout << r << endl;
    return 0;
}

