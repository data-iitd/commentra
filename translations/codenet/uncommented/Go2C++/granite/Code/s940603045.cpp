
```cpp
#include <bits/stdc++.h>
using namespace std;

const string abcd = "abcdefghijklmnopqrstuvwxyz";
const string ABCD = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int dx[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int dy[9] = {1, 1, 0, -1, -1, -1, 0, 1, 0};
int inf = numeric_limits<int>::max();

int main() {
    string N;
    cin >> N;
    int sum = 0;
    for (char c : N) {
        sum += c - '0';
    }
    int m;
    cin >> m;
    if (m % sum == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

