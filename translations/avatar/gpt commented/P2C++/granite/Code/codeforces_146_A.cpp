
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string number;
    cin >> number;
    int h1 = 0, h2 = 0, x = 0;
    for (int i = 0; i < n; i++) {
        if (number[i]!= '4' && number[i]!= '7') {
            cout << "NO" << endl;
            x = 1;
            break;
        }
        if (i < n / 2) {
            h1 += number[i] - '0';
        } else {
            h2 += number[i] - '0';
        }
    }
    if (!x) {
        if (h1 == h2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
