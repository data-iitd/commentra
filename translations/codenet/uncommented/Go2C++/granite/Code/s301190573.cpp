
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>
#include <set>
#include <map>
#include <numeric>
#include <sstream>
#include <queue>
#include <stack>
#include <iomanip>
#include <functional>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int MAX_N = 1000000;
int par[MAX_N];
int rank[MAX_N];

void initialize(int n){
    for(int i=0;i<n;i++){
        par[i] = i;
    }
}

int root(int i){
    if(par[i] == i) return i;
    return par[i] = root(par[i]);
}

bool same(int i,int j){
    return root(i) == root(j);
}

void unite(int i,int j){
    int x = root(i);
    int y = root(j);
    if(x == y) return;
    if(rank[x] < rank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin >> p[i];
        p[i]--;
    }
    initialize(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        unite(x-1,y-1);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(same(i,p[i])) ans++;
    }
    cout << ans << endl;
    return 0;
}
