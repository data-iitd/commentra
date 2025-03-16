
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
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define fs first
#define sc second
#define MOD 1000000007
#define EPS 0.00000001

int main(){
    int X, Y, Z, K; scanf("%d %d %d %d", &X, &Y, &Z, &K);
    vector<ll> A(X);
    vector<ll> B(Y);
    vector<ll> C(Z);
    for(ll &a:A)
        scanf("%lld", &a);
    for(ll &b:B)
        scanf("%lld", &b);
    for(ll &c:C)
        scanf("%lld", &c);
    
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    sort(C.begin(), C.end(), greater<ll>());
    
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
