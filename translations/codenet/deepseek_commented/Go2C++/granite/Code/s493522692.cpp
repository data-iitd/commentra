
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cassert>
#include <ccomplex>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int MAX_N = 100001;
const int MAX_M = 100001;
const int MOD = 100000007;
const double EPS = 1e-10;

int N,M;

int main(){
    cin >> N >> M;
    int ans = 0;
    ans += min(N,M/2);
    N -= ans;
    M -= ans*2;
    ans += M/4;
    cout << ans << endl;
}

