#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<char> ch(n);
    int s1 = 0, s2 = 0;
    int flag = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        int temp1 = s1 + x;
        int temp2 = s2 + y;

        if (abs(temp1 - s2) <= 500) {
            s1 += x;
            ch[i] = 'A';
        } else if (abs(temp2 - s1) <= 500) {
            s2 += y;
            ch[i] = 'G';
        } else {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        cout << -1 << endl;
    } else {
        for (char c : ch) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}

