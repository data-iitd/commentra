
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int h, a, num = 0;
    cin >> h >> a;
    for (int i = 1; h > 0; i++) {
        h = h - a;
        num++;
    }
    cout << num << endl;
    return 0;
}

