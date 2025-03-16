
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, sa;
    cin >> n >> m;
    string s;
    cin >> s;
    sa = count(s.begin(), s.end(), '-');
    sa = min(n - sa, sa);
    vector<string> ss;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        b -= a;
        if (b % 2 == 0 || b > sa * 2) {
            ss.push_back("1\n");
        } else {
            ss.push_back("0\n");
        }
    }
    cout << accumulate(ss.begin(), ss.end(), string());
    return 0;
}

