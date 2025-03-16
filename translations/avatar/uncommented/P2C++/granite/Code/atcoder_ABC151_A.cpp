
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <cassert>
#include <exception>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef pair<P,int> PPI;
typedef pair<int,P> PIP;
typedef pair<ll,P> PLP;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define reep(i,a,b) for(int i = (a); i < (b); i++)
#define repk(i,a,b) for(int i = (a); i <= (b); i++)
#define repn(i,a,b) for(int i = (a)-1; i >= (b); i--)
#define repne(i,a,b) for(int i = (a)-1; i!= (b); i--)
const int inf=1<<29;
const double EPS=1e-9;
const double PI=acos(-1.0);
const int mod=1e9+7;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

string c;

char solve(){
    rep(i,26){
        if(c[0]==i+'a') return i+'b';
    }
}

int main(void){
    cin>>c;
    cout<<solve()<<endl;
    return 0;
}

Translate the above C++ code to Java and end with comment "