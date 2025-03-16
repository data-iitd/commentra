#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(int x, int n) {
    int max = n * 2 - 1;
    if (x == 1 || x == max) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    string sep = "\n";
    string ans;
    for (int e = x + n - 1; e < x + n + max - 1; ++e) {
        ans += to_string((e % max) + 1) + sep;
    }
    cout << ans;
}

int main() {
    int n, x;
    cin >> n >> x;
    print(x, n);
    return 0;
}

// <END-OF-CODE>
