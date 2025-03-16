
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

typedef long long ll;
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int ara[n];
    map<int, int> map;
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        ara[i] = v;
        if (map.find(v) == map.end()) {
            map[v] = 1;
        } else {
            map[v]++;
        }
    }
    int max = 0;
    for (auto i : map) {
        max = max(max, i.second);
    }
    map<int, int> mm;
    for (int i = 0; i < n; i++) {
        if (mm.find(ara[i]) == mm.end()) {
            mm[ara[i]] = 1;
            if (mm[ara[i]] == max) {
                printf("%d\n", ara[i]);
                break;
            }
        } else {
            mm[ara[i]]++;
            if (mm[ara[i]] == max) {
                printf("%d\n", ara[i]);
                break;
            }
        }
    }
    return 0;
}
//END-OF-CODE