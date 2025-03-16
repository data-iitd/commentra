
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>


using namespace std;

int main() {

    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> L(100000);
    int l;
    for (int i = 0; i < N; i++) {
        scanf("%d", &l);
        L[i] = l;
    }

    sort(L.begin(), L.end());

    vector<int>::iterator itr;
    
    for (int i = 0; i < M; i++) {
        int max_L = L.back();
        if (max_L == 0) {
            break;
        }

        max_L /= 2;
        itr = lower_bound(L.begin(), L.end(), max_L);
        L.insert(itr, max_L);
        L.pop_back();
    }

    long long ans = accumulate(L.begin(), L.end(), 0LL);

    printf("%lld\n", ans);

}
