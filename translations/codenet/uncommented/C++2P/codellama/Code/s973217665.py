#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define pi M_PI
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

def main():
    n = int(input())
    while n > 0:
        p, q = map(int, input().split())
        l = int(sqrt(p*p + q*q))
        isprime = 1
        for i in range(l):
            for j in range(l):
                x = i*i + j*j
                if x <= 1 or x >= p*p + q*q:
                    continue
                if (i*p + j*q) % x == 0 and (i*q - j*p) % x == 0:
                    isprime = 0
        print("P" if isprime else "C")
        n -= 1

    return 0

