
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX_N 100000
#define MOD 100000007
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,a,n) for(int i=a;i<n;i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

struct BIT{
    int size;
    vector<int> tree;
    BIT(int n){
        size = n;
        tree.resize(size+1);
    }
    int _sum(int i){
        int s = 0;
        while(i>0){
            s += tree[i];
            i -= i & -i;
        }
        return s;
    }
    int sum(int l,int r){
        return _sum(r)-_sum(l-1);
    }
    void add(int i,int x){
        while(i<=size){
            tree[i] += x;
            i += i & -i;
        }
    }
};

int main(void) {
    int n;
    cin >> n;
    int m = n*(n+1)/4;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    vector<int> b = a;
    sort(all(b));
    b.erase(unique(all(b)),b.end());
    map<int,int> mp;
    rep(i,b.size())mp[b[i]] = i;
    rep(i,n)a[i] = mp[a[i]];
    auto check = [&](int x){
        vector<int> c(n+1);
        rep(i,n)c[i+1] = c[i] + (a[i]>=x?2:-1);
        int mi = *min_element(all(c));
        rep(i,n+1)c[i] -= mi;
        BIT bit(n+1);
        int sum = 0;
        rep(i,n+1){
            sum += bit.sum(c[i],n);
            bit.add(c[i],1);
        }
        return sum >= m;
    };
    int ng = -1, ok = b.size();
    while(ok-ng>1){
        int mid = (ok+ng)/2;
        if(check(mid))ok = mid;
        else ng = mid;
    }
    cout << b[ok-1] << endl;
}
// END-OF-CODE