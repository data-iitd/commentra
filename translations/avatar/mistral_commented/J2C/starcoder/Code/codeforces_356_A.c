
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
#include <memory.h>
#include <complex>
#include <functional>
#include <numeric>
#include <utility>
#include <bitset>
#include <climits>
#include <limits>
#include <float.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <limits.h>
#include <sys/time.h>
#include <omp.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define sz(v) ((int)(v).size())
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vvll vector<vector<vector<long long>>>
#define vvpii vector<vector<pii>>
#define vvpi vector<vector<pair<int, int>>>
#define vvs vector<vector<string>>
#define vvc vector<vector<char>>
#define vvb vector<vector<bool>>
#define vvd vector<vector<double>>
#define vlll vector<vector<vector<long long>>>
#define vllv vector<vector<vector<long long>>>
#define vlls vector<vector<vector<string>>>
#define vllc vector<vector<vector<char>>>
#define vllb vector<vector<vector<bool>>>
#define vlld vector<vector<vector<double>>>
#define vvlm vector<vector<vector<map<int, int>>>>
#define vvllm vector<vector<vector<map<long long, long long>>>>
#define vvlpii vector<vector<vector<pii>>>
#define vvlpi vector<vector<vector<pair<int, int>>>>
#define vvlvs vector<vector<vector<vector<string>>>>
#define vvlvc vector<vector<vector<vector<char>>>>
#define vvlvb vector<vector<vector<vector<bool>>>>
#define vvlvd vector<vector<vector<vector<double>>>>
#define vvlll vector<vector<vector<vector<long long>>>>
#define vvllv vector<vector<vector<vector<long long>>>>
#define vvlls vector<vector<vector<vector<string>>>>
#define vvllc vector<vector<vector<vector<char>>>>
#define vvllb vector<vector<vector<vector<bool>>>>
#define vvlld vector<vector<vector<vector<double>>>>
#define vvlpi vector<vector<vector<pair<int, int>>>>
#define vvlpl vector<vector<vector<pair<long long, long long>>>>
#define vvlss vector<vector<vector<string>>>
#define vvlsc vector<vector<vector<char>>>
#define vvlcb vector<vector<vector<bool>>>
#define vvlcd vector<vector<vector<double>>>
#define vvlpii vector<vector<vector<pii>>>
#define vvlpl vector<vector<vector<pair<long long, long long>>>>
#define vvlss vector<vector<vector<string>>>
#define vvlsc vector<vector<vector<char>>>
#define vvlcb vector<vector<vector<bool>>>
#define vvlcd vector<vector<vector<double>>>
#define vvlpi vector<vector<vector<pair<int, int>>>>
#define vvlpl vector<vector<vector<pair<long long, long long>>>>
#define vvlss vector<vector<vector<string>>>
#define vvlsc vector<vector<vector<char>>>
#define vvlcb vector<vector<vector<bool>>>
#define vvlcd vector<vector<vector<double>>>
#define vvll vector<vector<vector<long long>>>
#define vvl vector<vector<long long>>
#define vvs vector<vector<string>>
#define vvc vector<vector<char>>
#define vvb vector<vector<bool>>
#define vvd vector<vector<double>>
#define vlll vector<vector<vector<long long>>>
#define vllv vector<vector<vector<long long>>>
#define vlls vector<vector<vector<string>>>
#define vllc vector<vector<vector<char>>>
#define vllb vector<vector<vector<bool>>>
#define vlld vector<vector<vector<double>>>
#define vvlm vector<vector<vector<map<int, int>>>>
#define vvllm vector<vector<vector<map<long long, long long>>>>
#define vvlpii vector<vector<vector<pii>>>
#define vvlpi vector<vector<vector<pair<int, int>>>>
#define vvlvs vector<vector<vector<vector<string>>>>
#define vvlvc vector<vector<vector<vector<char>>>>
#define vvlvb vector<vector<vector<vector<bool>>>>
#define vvlvd vector<vector<vector<vector<double>>>>
#define vvlll vector<vector<vector<vector<long long>>>>
#define vvllv vector<vector<vector<vector<long long>>>>
#define vvlls vector<vector<vector<vector<string>>>>
#define vvllc vector<vector<vector<vector<char>>>>
#define vvllb vector<vector<vector<vector<bool>>>>
#define vvlld vector<vector<vector<vector<double>>>>
#define vvlpi vector<vector<vector<pair<int, int>>>>
#define vvlpl vector<vector<vector<pair<long long, long long>>>>
#define vvlss vector<vector<vector<string>>>
#define vvlsc vector<vector<vector<char>>>
#define vvlcb vector<vector<vector<bool>>>
#define vvlcd vector<vector<vector<double>>>
#define vvlpii vector<vector<vector<pii>>>
#define vvlpl vector<vector<vector<pair<long long, long long>>>>
#define vvlss vector<vector<vector<string>>>
#define vvlsc vector<vector<vector<char>>>
#define vvlcb vector<vector<vector<bool>>>
#define vvlcd vector<vector<vector<double>>>
#define vvlpi vector<vector<vector<pair<int, int>>>>
#define vvlpl vector<vector<vector<pair<long long, long long>>>>
#define vvlss vector<vector<vector<string>>>
#define vvlsc vector<vector<vector<char>>>
#define vvlcb vector<vector<vector<bool>>>
#define vvlcd vector<vector<vector<double>>>
#define vvll vector<vector<vector<long long>>>
#define vvl vector<vector<long long>>
#define vvs vector<vector<string>>
#define vvc vector<vector<char>>
#define vvb vector<vector<bool>>
#define vvd vector<vector<double>>
#define vlll vector<vector<vector<long long>>>
#define vllv vector<vector<vector<long long>>>
#define vlls vector<vector<vector<string>>>
#define vllc vector<vector<vector<char>>>
#define vllb vector<vector<vector<bool>>>
#define vlld vector<vector<vector<double>>>
#define vvlm vector<vector<vector<map<int, int>>>>
#define vvllm vector<vector<vector<map<long long, long long>>>>
#define vvlpii vector<vector<vector<pii>>>
#define vvlpi vector<vector<vector<pair<int, int>>>>
#define vvlvs vector<vector<vector<vector<string>>>>
#define vvlvc vector<vector<vector<vector<char>>>>
#define vvlvb vector<vector<vector<vector<bool>>>>
#define vvlvd vector<vector<vector<vector<double>>>>
#define vvlll vector<vector<vector<vector<long long>>>>
#define vvllv vector<vector<vector<vector<long long>>>>
#define vvlls vector<vector<vector<vector<string>>>>
#define vvllc vector<vector<vector<vector<char>>>>
#define vvllb vector<vector<vector<vector<bool>>>>
#define vvlld vector<vector<vector<vector<double>>>>
#define vvlpi vector<vector<vector<pair<int, int>>>>
#define vvlpl vector<vector<vector<pair<long long, long long>>>>
#define vvlss vector<vector<vector<string>>>
#define vvlsc vector<vector<vector<char>>>
#define vvlcb vector<vector<vector<bool>>>
#define vvlcd vector<vector<vector<double>>>
#define vvlpii vector<vector<vector<pii>>>
#define vvlpl vector<vector<vector<pair<long long, long long>>>>
#define vvlss vector<vector<vector<string>>>
#define vvlsc vector<vector<vector<char>>>
#define vvlcb vector<vector<vector<bool>>>
#define vvlcd vector<vector<vector<double>>>
#define vvlpi vector<vector<vector<pair<int, int>>>>
#define vvlpl vector<vector<vector<pair<long long, long long>>>>
#define vvlss vector<vector<vector<string>>>
#define vvlsc vector<vector<vector<char>>>
#define vvlcb vector<vector<vector<bool>>>
#define vvlcd vector<vector<vector<double>>>
#define vvll vector<vector<vector<long long>>>
#define vvl vector<vector<long long>>
#define vvs vector<vector<string>>
#define vvc vector<vector<char>>
#define vvb vector<vector<bool>>
#define vvd vector<vector<double>>
#define vlll vector<vector<vector<long long>>>
#define vllv vector<vector<vector<long long>>>
#define vlls vector<vector<vector<string>>>
#define vllc vector<vector<vector<char>>>
#define vllb vector<vector<vector<bool>>>
#define vlld vector<vector<vector<double>>>
#define vvlm vector<vector<vector<map<int, int>>>>
#define vvllm vector<vector<vector<map<long long, long long>>>>
#define vvlpii vector<vector<vector<pii>>>
#define vvlpi vector<vector<vector<pair<int, int>>>>
#define vvlvs vector<vector<vector<vector<string>>>>
#define vvlvc vector<vector<vector<vector<char>>>>
#define vvlvb vector<vector<vector<vector<bool>>>>
#define vvlvd vector<vector<vector<vector<double>>>>
#define vvlll vector<vector<vector<vector<long long>>>>
#define vvllv vector<vector<vector<vector<long long>>>>
#define vvlls vector<vector<vector<vector<string>>>>
#define vvllc vector<vector<vector<vector<char>>>>
#define vvllb vector<vector<vector<vector<bool>>>>
#define vvlld vector<vector<vector<vector<double>>>>
#define vvlpi vector<vector<vector<pair<int, int>>>>
#define vvlpl vector<vector<vector<pair<long long, long long>>>>
#define vvlss vector<vector<vector<string>>>
#define vvlsc vector<vector<vector<char>>>
#define vvlcb vector<vector<vector<bool>>>
#define vvlcd vector<vector<vector<double>>>
#define vvlpii vector<vector<vector<pii>>>
#define vvlpl vector<vector<vector<pair<long long, long long>>>>
#define vvlss vector<vector<vector<string>>>
#define vvlsc vector<vector<vector<char>>>
#define vvlcb vector<vector<vector<bool>>>
#define vvlcd vector<vector<vector<double>>>
#define vvlpi vector<vector<vector<pair<int, int>>>>
#define vvlpl vector<vector<vector<pair<long long, long long>>>>
#define vvlss vector<vector<vector<string>>>
#define vvlsc vector<vector<vector<char>>>
#define vvlcb vector<vector<vector<bool>>>
#define vvlcd vector<vector<vector<double>>>
#define vvll vector<vector<vector<long long>>>
#define vvl vector<vector<long long>>
#define vvs vector<vector<string>>
#define vvc vector<vector<char>>
#define vvb vector<vector<bool>>
#define vvd vector<vector<double>>
#define vlll vector<vector<vector<long long>>>
#define vllv vector<vector<vector<long long>>>
#define vlls vector<vector<vector<string>>>
#define vllc vector<vector<vector<char>>>
#define vllb vector<vector<vector<bool>>>
#define vlld vector<vector<vector<double>>>
#define vvlm vector<vector<vector<map<