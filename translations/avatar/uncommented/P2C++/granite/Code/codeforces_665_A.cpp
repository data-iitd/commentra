
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>
#include <time.h>
#include <tuple>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

int main(){
    int a,at,b,bt,t1,t2,st,fin,now,ans;
    cin >> a >> at >> b >> bt >> t1 >> t2;
    st = t2 + ( t1 - 5 ) * 60;
    fin = st + at;
    now = 0;
    ans = 0;
    while(now < fin && now < 1140){
        if(now + bt > st){
            ans += 1;
        }
        now += b;
    }
    cout << ans << endl;
    return 0;
}

