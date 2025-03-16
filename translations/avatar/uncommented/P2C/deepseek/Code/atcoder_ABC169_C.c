#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define setrecursionlimit(x) (void(0))
#define dbg(args...) (void(0))
#define LMIIS(f, sep) (f)
#define II (int)
#define P 1000000007
#define INF 10000000010

void main_() {
    char sa[10], sb[10];
    scanf("%s %s", sa, sb);
    int a = atoi(sa);
    double b = atof(sb) * 100.0 + 0.1;
    int b_int = (int)b;
    printf("%d\n", a * b_int / 100);
}

int main() {
    main_();
    return 0;
}
