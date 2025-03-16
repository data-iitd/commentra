#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define fs first
#define sc second
#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001

int main(){
    int X, Y, Z, K; scanf("%d %d %d %d", &X, &Y, &Z, &K);
    ll A[X], B[Y], C[Z];
    for(int i=0; i<X; i++){
        scanf("%lld", &A[i]);
    }
    for(int i=0; i<Y; i++){
        scanf("%lld", &B[i]);
    }
    for(int i=0; i<Z; i++){
        scanf("%lld", &C[i]);
    }
    
    sort(A, A+X, greater<ll>());
    sort(B, B+Y, greater<ll>());
    sort(C, C+Z, greater<ll>());
    
    vector<ll> AB;
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            AB.push_back(A[i]+B[j]);
        }
    }
    
    sort(AB.begin(), AB.end(), greater<ll>());
    vector<ll> ABC;
    for(int i=0; i<min(K, (int)AB.size()); i++){
        for(int j=0; j<Z; j++){
            ABC.push_back(AB[i] + C[j]);
        }
    }
    
    sort(ABC.begin(), ABC.end(), greater<ll>());
    for(int i=0; i<K; i++){
        printf("%lld\n", ABC[i]);
    }
    
    
    
    return 0;
}
