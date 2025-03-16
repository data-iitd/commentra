
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <sstream>
#include <stack>
#include <bitset>
#include <utility>
#include <iomanip>
#include <complex>
#include <memory>
using namespace std;
typedef long long ll;
#define all(v) v.begin(),v.end()
#define p(x) cout<<#x<<"="<<x<<endl
#define p2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define p3(x,y,z) cout<<#x<<"=" <<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<endl
#define parray(x,n) cout<<#x<<"=";for(int _=0;_<n;++_){cout<<x[_]<<" ";}cout<<endl
#define pmap(x) cout<<#x<<"=";for(auto &_:x){cout<<_.first<<"="<<_.second<<" ";}cout<<endl
#define REP(i,n) for(int i=0;i<n;++i)
#define REPR(i,n) for(int i=n-1;i>=0;--i)
#define DEB 0
#define F first
#define S second
#define mp make_pair
#define pb push_back

int N,X;

int calc(int x){
    vector<int> y(x);
    REP(i,x)y[i]=i+1;
    while(y.size()>1){
        vector<int> z;
        REP(i,y.size()-2){
            z.pb(max(y[i],max(y[i+1],y[i+2])));
        }
        y=z;
    }
    return y[0];
}

int main(){
    cin>>N>>X;
    if(X==1||X==2*N-1){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    if(X==2*N-2){
        REP(i,N-3)cout<<i+3<<endl;
        cout<<2<<endl;
        cout<<1<<endl;
        cout<<N<<endl;
        cout<<N-1<<endl;
        cout<<N-2<<endl;
    }else{
        vector<int> y(2*N-2);
        REP(i,2*N-2)y[i]=i+1;
        REP(i,X-2)swap(y[i],y[i+1]);
        REP(i,N-3)cout<<y[i]<<endl;
        cout<<X+1<<endl;
        cout<<X<<endl;
        cout<<X-1<<endl;
        cout<<X-2<<endl;
    }
    return 0;
}
