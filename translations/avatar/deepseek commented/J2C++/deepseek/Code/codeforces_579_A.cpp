#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "";

    // Converting the integer to binary representation
    while (n > 0) {
        int x = n % 2;
        n /= 2;
        s = to_string(x) + s;
    }

    int ans = 0;

    // Counting the number of '1's in the binary representation
    for (char c : s) {
        if (c == '1') {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
