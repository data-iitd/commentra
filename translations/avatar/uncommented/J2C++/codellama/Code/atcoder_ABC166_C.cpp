#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <deque>
#include <set>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <climits>
#include <cctype>
using namespace std;
int main ( ) {
    int N;
    long M;
    long H[100000];
    bool ans[100000];
    scanf("%d", &N);
    scanf("%ld", &M);
    for (int i = 0; i < N; i++) {
        scanf("%ld", &H[i]);
        ans[i] = true;
    }
    for (int i = 0; i < M; i++) {
        int temp1, temp2;
        scanf("%d", &temp1);
        scanf("%d", &temp2);
        if (H[temp1 - 1] < H[temp2 - 1]) {
            ans[temp1 - 1] = false;
        } else if (H[temp1 - 1] > H[temp2 - 1]) {
            ans[temp2 - 1] = false;
        } else {
            ans[temp1 - 1] = false;
            ans[temp2 - 1] = false;
        }
    }
    int ans2 = 0;
    for (int i = 0; i < N; i++) {
        if (ans[i]) {
            ans2++;
        }
    }
    printf("%d\n", ans2);
    return 0;
}
