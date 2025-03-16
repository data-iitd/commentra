#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector> 
#include<limits>
#include<numeric>
#include<type_traits>
#include<math.h>
using namespace std;
typedef long long ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define in(x) scanf("%d", &x)
#define out(str) printf("%s\n", str)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int L,N;

int main(){
    scanf("%d%d", &N, &L);
    string S[N];
    rep(i,N)scanf("%s", S[i]);
    sort(S,S+N);
    rep(i,N)printf("%s", S[i]);
    printf("\n");

}

