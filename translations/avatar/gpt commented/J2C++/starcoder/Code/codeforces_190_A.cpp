#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cfloat>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n == 0) {
        if (m!= 0) {
            printf("Impossible");
        } else {
            printf("0 0");
        }
        return 0;
    }
    if (m <= n) {
        if (m == 0) {
            m = 1;
        }
        printf("%d %d", n, m + n - 1);
        return 0;
    }
    printf("%d %d", m, m + n - 1);
    return 0;
}

