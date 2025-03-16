#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <cmath> 
#include <algorithm> 
#include <set> 
#include <map> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <cassert> 
using namespace std; 

#define FOR(i,a,b) for (int i = (a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define ALL(c) (c).begin(), (c).end() 
#define SZ(c) (int)(c).size() 
#define PB push_back 
#define MP make_pair 
#define CLR(c,v) memset((c),(v),sizeof(c)) 
#define SORT(c) sort(ALL(c)) 
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin()) 
#define LIST(c) (c).begin(),(c).end() 
#define MSET(c,v) memset((c),(v),sizeof(c)) 
#define MCOPY(a,b) memcpy((a),(b),sizeof(a)) 
#define MMOVE(a,b) memmove((a),(b),sizeof(a)) 
#define MSCMP(a,b) memcmp((a),(b),sizeof(a)) 
#define MAX(a,b) ((a)>(b)?(a):(b)) 
#define MIN(a,b) ((a)<(b)?(a):(b)) 
#define MAX3(a,b,c) MAX(MAX(a,b),c) 
#define MIN3(a,b,c) MIN(MIN(a,b),c) 
#define MAX4(a,b,c,d) MAX(MAX3(a,b,c),d) 
#define MIN4(a,b,c,d) MIN(MIN3(a,b,c),d) 
#define MEDIAN(a,b,c) MIN(MAX(a,b),c)==a?b:MAX(MIN(a,b),c)==c?a:b 
#define REV(a) reverse(LIST(a)) 
#define SORTNG(a) sort(LIST(a)) 
#define SORTG(a) sort(LIST(a),greater<typeof(a[0])>()) 
#define PERMUTE next_permutation 
#define PERMUTE_SECOND next_permutation(a.begin()+1,a.end()) 
#define TC(t) while(t--) 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define what_is(x) cerr << #x << " is " << x << endl;

void solve() { 
    // Step 4: Read input values
    int n;
    cin >> n; 
    long a[n]; 
    REP(i, n) { 
        cin >> a[i]; 
    } 

    // Step 5: Initialize a dynamic programming array
    long dp[n + 1]; 
    CLR(dp, -1); 

    // Step 6: Fill the dynamic programming array
    dp[n - 1] = a[n - 1]; 
    for (int i = n - 1; i >= 0; i--) { 
        dp[i] = max(dp[i + 1], a[i]); 
    } 

    // Step 7: Calculate the result
    REP(i, n) { 
        if (a[i] > dp[i + 1]) { 
            cout << 0 << " "; 
        } else { 
            cout << (dp[i + 1] - a[i] + 1) << " "; 
        } 
    } 

    // Step 8: Print the result
    cout << endl; 
} 

int main() { 
    FAST_INP;
    // Step 9: Debugging (optional)
    // debug(n); 
    solve(); 
    return 0; 
} 

