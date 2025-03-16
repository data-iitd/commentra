
```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    if (B - A == C - B) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

