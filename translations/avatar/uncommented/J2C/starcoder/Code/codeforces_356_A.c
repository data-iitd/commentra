#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((int)(v).size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sqr(x) ((x) * (x))
#define INF 1000000000
#define MOD 1000000007
#define EPS 1e-9
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvll vector<vector<ull>>
#define vvvll vector<vector<vector<ll>>>
#define vvvvll vector<vector<vector<vector<ll>>>>
#define vvvvvll vector<vector<vector<vector<vector<ll>>>>>
#define vvvvvvll vector<vector<vector<vector<vector<vector<ll>>>>>>
#define vvvvvvvll vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>
#define vvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>
#define vvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>
#define vvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>
#define vvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>
#define vvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>
#define vvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ve