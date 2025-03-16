
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <random>
#include <complex>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <numeric>
#include <regex>
#include <valarray>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using namespace std;

// solution
int main(){
    int n;
    cin >>n;
    if(n==1){
        cout << 0 << endl;
        return 0;
    }
    vector<int> p;
    int nn = n;
    for(int i=2; i*i<=nn; i++){
        if(nn%i==0){
            p.pb(i);
            while(nn%i==0) nn /= i;
        }
    }
    if(nn>1) p.pb(nn);
    int ans = 0;
    for(int i:p){
        int x = n;
        while(x>0){
            x -= x/i;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
// END-OF-CODE