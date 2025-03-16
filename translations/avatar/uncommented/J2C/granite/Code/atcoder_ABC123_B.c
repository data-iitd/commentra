
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a[5], r[5];
    map<int, int> map;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
        r[i] = a[i] % 10;
        int b = 10;
        if (r[i]!= 0) {
            b = 10 - r[i];
            map[b] = a[i];
        }
    }
    int ans = 0;
    if (map.size() == 0) {
        for (int i = 0; i < 5; i++) {
            ans += a[i];
        }
        printf("%d\n", ans);
        return 0;
    }
    int last = map[map.rbegin()->first];
    int idx = 0;
    for (int i = 0; i < 5; i++) {
        if (a[i] == last) {
            idx = i;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (i!= idx) {
            if (a[i] % 10 == 0) {
                ans += a[i];
            } else {
                ans += a[i] + (10 - r[i]);
            }
        }
    }
    ans += last;
    printf("%d\n", ans);
    return 0;
}
// END-OF-CODE