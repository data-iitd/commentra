#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string i2s(int i) {
    return to_string(i);
}

string TenToN(int number, int n) {
    string s;
    int tmp = number;
    do {
        s = i2s(tmp % n) + s;
        tmp /= n;
    } while (tmp >= n);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    string s = TenToN(N, K);
    cout << s.length() << endl;

    return 0;
}

/*==========================================
 *             Library
 *==========================================*/

// Additional utility functions can be added here if needed

// <END-OF-CODE>
