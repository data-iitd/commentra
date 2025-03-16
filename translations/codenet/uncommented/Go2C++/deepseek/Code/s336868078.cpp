#include <iostream>
using namespace std;

int solve(int a, int b, int c) {
    int temp_;
    if (c == a + b) {
        temp_ = b + c;
    } else if (c - 1 > a + b) {
        int temp = (c - 1) - (a + b);
        temp_ = b + c - temp;
    } else {
        temp_ = b + c;
    }
    return temp_;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int ans = solve(a, b, c);
    cout << ans << endl;

    return 0;
}
