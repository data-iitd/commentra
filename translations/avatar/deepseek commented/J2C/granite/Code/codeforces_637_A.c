
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

#ifdef _MSC_VER
#define __typeof__ decltype
#define __restrict__ __restrict
#define __builtin_popcount __popcnt
#endif

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

template<typename T> void chmax(T& a, T b) { a = max(a, b); }
template<typename T> void chmin(T& a, T b) { a = min(a, b); }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

// Rest of the C code goes here

