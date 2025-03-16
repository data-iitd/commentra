#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int rec(long x) {
    int answer = 0;
    for (int k = 31; k >= 0; k--) {
        if ((x & (1 << k)) != 0) {
            answer++;
        }
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    int a[33];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[rec(x)]++;
    }
    double answer = 0;
    for (int i = 0; i < 33; i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1);
        answer += summ;
    }
    cout << (long) answer << endl;
    return 0;
}

