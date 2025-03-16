#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <locale.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sqr(x) ((x) * (x))
#define INF 1000000000
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define vvvpii vector<vector<vector<pii>>>
#define vvvvpii vector<vector<vector<vector<pii>>>>
#define vvvvpll vector<vector<vector<vector<pll>>>>
#define vvvvvpll vector<vector<vector<vector<vector<pll>>>>
#define vvvvvvpll vector<vector<vector<vector<vector<vector<pll>>>>>
#define vvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>
#define vvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>
#define vvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>
#define vvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>
#define vvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>
#define vvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>
#define vvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>>>>>>>>
#define vvvvvvv