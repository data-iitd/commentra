#include <iostream>
#include <string>

using namespace std;

int min(int x, int y) {
    return x < y ? x : y;
}

int main() {
    string S;
    cin >> S;

    int l0 = 0, l1 = 0;

    for (char c : S) {
        if (c == '0') {
            l0++;
        } else {
            l1++;
        }
    }

    cout << 2 * min(l0, l1) << endl;

    return 0;
}

