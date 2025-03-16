

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    cin >> a;
    int count = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '1') {
            count++;
        }
    }
    if (count == 0) {
        cout << 0 << endl;
    } else {
        int result = 1;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == '0') {
                int count = 0;
                while (i < a.length() && a[i] == '0') {
                    count++;
                    i++;
                }
                result *= (count + 1);
            }
        }
        cout << result << endl;
    }
    return 0;
}
