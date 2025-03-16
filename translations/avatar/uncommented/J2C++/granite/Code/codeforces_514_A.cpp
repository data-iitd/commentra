
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin >> x;
    vector<int> list;
    while (x > 0) {
        int r = x % 10;
        if (9 - r < r) {
            if (x / 10 == 0 && 9 - r == 0)
                list.push_back(r);
            else
                list.push_back(9 - r);
        } else
            list.push_back(r);
        x = x / 10;
    }
    long long newNumber = 0;
    for (int i = 0; i < list.size(); i++) {
        newNumber = newNumber + list[i] * pow(10, i);
    }
    cout << newNumber << endl;
    return 0;
}
// 