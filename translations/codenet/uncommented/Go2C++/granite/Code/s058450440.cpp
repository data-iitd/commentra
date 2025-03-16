
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> count(5, 0);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        switch (c) {
            case 'M':
                count[0]++;
                break;
            case 'A':
                count[1]++;
                break;
            case 'R':
                count[2]++;
                break;
            case 'C':
                count[3]++;
                break;
            case 'H':
                count[4]++;
                break;
        }
    }
    int ans = 0;
    do {
        int res = 1;
        for (int i = 0; i < 5; i++) {
            res *= count[i];
        }
        ans += res;
    } while (next_permutation(count.begin(), count.end()));
    cout << ans << endl;
    return 0;
}

