#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
#define ALL(v) (v).begin(), (v).end()
const int inf = 1e9;
const int mod = 1e9+7;

def is_prime(x):
	for i in range(2, int(x**0.5)+1):
		if x % i == 0: return False
	return True

N = int(input())

ans = 1
for i in range(2, N+1):
	if is_prime(i):
		NN = N
		cnt = 0
		while NN > 0:
			cnt += NN//i
			NN //= i
		ans *= cnt+1
		ans %= mod

print(ans)
# 