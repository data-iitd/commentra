#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    print(x, n);
    return 0;
}

void print(int x, int n) {
    int max = n * 2 - 1;
    if (x == 1 || x == max) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    string sep = "\n";
    string ans = "";
    for (int i = x + n - 1; i < x + n + max - 1; i++) {
        int num = (i % max + 1);
        ans += to_string(num) + sep;
    }
    cout << ans << endl;
}

