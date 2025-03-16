
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <tuple>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;

int dy[4] = {-1, 0, +1, 0};
int dx[4] = {0, +1, 0, -1};

const long long INF = 1LL << 60;
const ll MOD = 1e9 + 7;

bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}

int gcd(int a, int b){
	if (b == 0)return a;
	return gcd(b, a % b);
}

#-----------------------ここから-----------

n = int(input())

s = ""

if n == 0:
	print('0')
	exit()

i = 1
while n!= 0:
	if n % 2 == 0:
		s += '0'
	else:
		s += '1'
	n -= abs(n % 2)
	n /= -2

s = s[::-1]

print(s)

#-----------------------ここまで-----------

