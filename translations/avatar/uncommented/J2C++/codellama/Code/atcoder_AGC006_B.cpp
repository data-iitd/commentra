
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void print(int x, int n) {
    int max = n * 2 - 1;
    if (x == 1 || x == max) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    string sep = "\n";
    string ans = accumulate(x + n - 1, x + n + max - 1, string(), [&](string s, int e) {
        return s + to_string((e % max + 1)) + sep;
    });
    cout << ans << endl;
}

int main() {
    int n, x;
    cin >> n >> x;
    print(x, n);
    return 0;
}

