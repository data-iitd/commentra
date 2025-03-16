

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long x;
    cin >> x;
    vector<int> digits;
    while (x > 0) {
        int r = x % 10;
        if (9 - r < r) {
            if (x / 10 == 0 && 9 - r == 0) {
                digits.push_back(r);
            } else {
                digits.push_back(9 - r);
            }
        } else {
            digits.push_back(r);
        }
        x /= 10;
    }
    int pow = 0;
    long long newNumber = 0;
    for (int i = digits.size() - 1; i >= 0; i--) {
        newNumber += digits[i] * pow(10, pow);
        pow++;
    }
    cout << newNumber << endl;
    return 0;
}

