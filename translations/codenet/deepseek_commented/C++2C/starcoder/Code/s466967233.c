#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)
typedef long long ll;
#define fin(ans) printf("%lld\n",(ans))
/*

*/
int main()
{
    ll N,K;
    ll A[200100];
    ll B[200100] = {-1}; // Array to track visited nodes
    int now = 1; // Starting node
    ll cnt = 0; // Counter for cycle detection
    scanf("%lld%lld",&N,&K);
    REP(i,N){
        scanf("%lld",&A[i+1]); // Read the sequence of nodes
    }
    REP(i,200100){
        B[i] = -1; // Initialize all nodes as unvisited
    }
    // Detect cycle and find the position after K steps
    B[1] = 0; // Mark the starting node
    for(ll j = 1; j <= K; j++){
        now = A[now]; // Move to the next node
        if(B[now] == -1){
            B[now] = j; // Mark the node as visited
        }else{
            cnt = j; // Record the cycle start
            break; // Exit the loop as cycle is detected
        }
    }
    if(j < K){
        ll tmp = (K - B[now]) % (cnt - B[now]); // Calculate remaining steps
        for (ll j = 0; j < tmp; j++)
        {
            now = A[now]; // Move to the position after K steps
        }
    }
    fin(now); // Output the final position
    return 0;
}

