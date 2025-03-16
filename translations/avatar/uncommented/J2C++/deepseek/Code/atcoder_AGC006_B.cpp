#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

void print(int x, int n) {
    int max = n * 2 - 1;
    if (x == 1 || x == max) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    stringstream ss;
    for (int i = x + n - 1; i < x + n + max - 1; ++i) {
        ss << (i % max + 1) << endl;
    }
    string ans = ss.str();
    cout << ans;
}

int main() {
    int n, x;
    cin >> n >> x;
    print(x, n);
    return 0;
}

