#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#define all(x) (x).begin(),(x).end()

def solve():
    pass

a = int(input())
b = int(input())
ans = ""
if a == 1 or b == 1:
    if a == 1 and b == 1:
        ans = "Draw"
    elif a == 1:
        ans = "Alice"
    else:
        ans = "Bob"
else:
    if a == b:
        ans = "Draw"
    elif a > b:
        ans = "Alice"
    else:
        ans = "Bob"
print(ans)



# 