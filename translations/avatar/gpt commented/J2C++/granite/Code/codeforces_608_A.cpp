
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <bitset>
#include <stack>
#include <iomanip>
#include <numeric>
#include <list>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

const int MAXN = 1e5+10;
const int MAXM = 1e6+10;
const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;

template <typename T>
inline T read()
{
    T x = 0,f = 1;
    char ch = getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f = -1; ch = getchar();}
    while(ch>='0' && ch<='9') {x = x*10+ch-'0'; ch = getchar();}
    return x*f;
}

int main()
{
    int n = read<int>(),s = read<int>();
    int maxx = 0;
    for(int i = 1;i <= n;i++)
    {
        int f = read<int>(),t = read<int>();
        maxx = max(maxx,f+t);
    }
    printf("%d\n",max(maxx,s));
    return 0;
}

