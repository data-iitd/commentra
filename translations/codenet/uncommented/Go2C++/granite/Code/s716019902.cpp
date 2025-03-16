
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int FAC_NUM = 300001;

int main() {
    int N;
    cin >> N;

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue;
        }
        sum += i;
    }
    cout << sum << endl;

    return 0;
}

