#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <random>

using namespace std;

#define int long long

class Ban:
    def __init__(self, l, r, val):
        self.l = l
        self.r = r
        self.val = val

    def __init__(self):
        pass

class Sp:
    def __init__(self):
        self.LIM = 20
        self.N = 2e5 + 7

    def init(self, a):
        n = len(a)
        for i in range(n):
            self.mn[0][i] = a[i]
        for i in range(1, self.LIM):
            for j in range(n):
                if j + (1 << i) <= n:
                    self.mn[i][j] = max(self.mn[i - 1][j], self.mn[i - 1][j + (1 << (i - 1))])
        self.pw[1] = 0
        for i in range(2, self.N):
            self.pw[i] = self.pw[i / 2] + 1

    def get(self, l, r):
        r += 1
        p = self.pw[r - l]
        return min(self.mn[p][l], self.mn[p][r - (1 << p)])

def main():
    ios_base.sync_with_stdio(False)
    cin.tie(0)

    n = int(input())
    a = list(map(int, input().split()))
    dl = list(map(int, input().split()))
    ans = 0
    bans = []
    for i in range(n):
        r = i
        while r + 1 < n and a[r] + 1 == a[r + 1]:
            r += 1
        ans += a[r]
        i = r
        bans.append(Ban(r - a[r], r, r - a[r]))
    Sp().init(dl)
    for t in bans:
        if Sp().get(t.l, t.r) > t.val:
            print(-1)
            return 0
    print(ans)

if __name__ == '__main__':
    main()

