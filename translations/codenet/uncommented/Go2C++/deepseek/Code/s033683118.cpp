#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve(istream &is, ostream &os) {
    int k, x;
    is >> k >> x;
    string ans = "No";
    if (k * 500 >= x) {
        ans = "Yes";
    }
    os << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line)) {
        if (line == "-----------------------------------") {
            solve(cin, cout);
        }
    }
    return 0;
}

