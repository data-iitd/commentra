#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)

here = [0] * 100001
dp1 = [0] * 100001
dp2 = [0] * 100001

while True:
    n, m = map(int, input().split())
    if n == 0: break
    rep(i, 100001) here[i] = dp1[i] = dp2[i] = 0
    dpflg = False
    rep(i, m):
        a = int(input())
        if a == 0: dpflg = True
        here[a] = 1
    maxi1 = 0
    maxi2 = 0
    reps(i, 1, n + 1):
        if here[i] == 1: dp1[i] = dp1[i - 1] + 1
        maxi1 = max(dp1[i], maxi1)
    reps(i, 1, n + 1):
        if here[i] == 1: dp2[i] = dp2[i - 1] + 1
        else: dp2[i] = dp1[i - 1] + 1
        maxi2 = max(dp2[i], maxi2)
    if not dpflg:
        print(maxi1)
    else:
        print(maxi2)

