#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long gen, st, tim;
    cin >> gen >> st >> tim;
    gen /= tim;
    long long beg = st - 1, end = (long long)pow(10, 18);
    while (true) {
        long long med = (beg + end) / 2 + 1;
        if (get(med) - get(st - 1) > gen) {
            end = med - 1;
        } else {
            beg = med;
        }
        if (beg == end) {
            cout << beg - st + 1;
            break;
        }
    }
    return 0;
}

