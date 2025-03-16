
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <limits.h>
#include <iomanip>
#include <stack>
#include <functional>
#include <list>
#include <bitset>
#include <random>
#include <chrono>
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
    // Step 1: Reading inputs
    int X, Y, Z, K; scanf("%d %d %d %d", &X, &Y, &Z, &K);
    
    // Step 2: Vector initialization and input
    vector<ll> A(X);
    vector<ll> B(Y);
    vector<ll> C(Z);
    for(ll &a:A)
        scanf("%lld", &a);
    for(ll &b:B)
        scanf("%lld", &b);
    for(ll &c:C)
        scanf("%lld", &c);
    
    // Step 3: Sorting
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    sort(C.begin(), C.end(), greater<ll>());
    
    // Step 4: Combining A and B
    vector<ll> AB;
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            AB.push_back(A[i]+B[j]);
        }
    }
    
    // Step 5: Sorting AB
    sort(AB.begin(), AB.end(), greater<ll>());
    
    // Step 6: Combining AB and C
    vector<ll> ABC;
    for(int i=0; i<min(K, (int)AB.size()); i++){
        for(int j=0; j<Z; j++){
            ABC.push_back(AB[i] + C[j]);
        }
    }
    
    // Step 7: Sorting ABC
    sort(ABC.begin(), ABC.end(), greater<ll>());
    
    // Step 8: Output
    for(int i=0; i<K; i++){
        printf("%lld\n", ABC[i]);
    }
    
    return 0;
}

