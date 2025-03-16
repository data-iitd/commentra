#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int readInt() {
    int x;
    cin >> x;
    return x;
}

int solve() {
    int K = readInt();
    if (K % 2 == 0 || K % 5 == 0) return -1;
    if (K % 7 == 0) K /= 7;
    K *= 9;
    int ans = 1;
    int remainder = 10 % K;
    while (remainder != 1) {
        ans++;
        remainder = remainder * 10 % K;
    }
    return ans;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// <END-OF-CODE>
