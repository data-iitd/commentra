#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
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
    // Step 1: Reading Inputs
    int X, Y, Z, K; 
    scanf("%d %d %d %d", &X, &Y, &Z, &K);
    
    // Step 2: Vector Initialization and Input
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
    
    // Step 3: Sorting
    qsort(A, X, sizeof(ll), (int (*)(const void*, const void*))compare_desc);
    qsort(B, Y, sizeof(ll), (int (*)(const void*, const void*))compare_desc);
    qsort(C, Z, sizeof(ll), (int (*)(const void*, const void*))compare_desc);
    
    // Step 4: Combining A and B
    ll AB[X*Y];
    int idx = 0;
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            AB[idx++] = A[i] + B[j];
        }
    }
    
    // Step 5: Sorting AB
    qsort(AB, X*Y, sizeof(ll), (int (*)(const void*, const void*))compare_desc);
    
    // Step 6: Combining AB and C
    ll ABC[K*Z];
    idx = 0;
    for(int i=0; i<min(K, X*Y); i++){
        for(int j=0; j<Z; j++){
            ABC[idx++] = AB[i] + C[j];
        }
    }
    
    // Step 7: Sorting ABC
    qsort(ABC, K*Z, sizeof(ll), (int (*)(const void*, const void*))compare_desc);
    
    // Step 8: Output
    for(int i=0; i<K; i++){
        printf("%lld\n", ABC[i]);
    }
    
    return 0;
}

int compare_desc(const void *a, const void *b) {
    ll A = *(ll*)a;
    ll B = *(ll*)b;
    if (A < B) return 1;
    if (A > B) return -1;
    return 0;
}
