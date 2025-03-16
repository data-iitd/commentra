#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin >> N;
    long long min = 0;
    for (int i = 0; i < 5; i++) {
        if (i == 0) {
            cin >> min;
        } else {
            long long temp;
            cin >> temp;
            min = min < temp? min : temp;
        }
    }
    cout << (long long)ceil((double)N / min) + 4 << endl;
    return 0;
}
