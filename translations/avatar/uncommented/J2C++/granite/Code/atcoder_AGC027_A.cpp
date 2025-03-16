
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, x;
    cin >> N >> x;
    vector < int > sweet;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        sweet.push_back(a);
    }
    sort(sweet.begin(), sweet.end());
    int num = 0;
    for (int i = 0; i < N; i++) {
        if (x - sweet[num] >= 0) {
            x = x - sweet[num];
            num++;
        } else {
            break;
        }
    }
    if ((num == N) && (x > 0)) {
        num -= 1;
    }
    cout << num << endl;
    return 0;
}

