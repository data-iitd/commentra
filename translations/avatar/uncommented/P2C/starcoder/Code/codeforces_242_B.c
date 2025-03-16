#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sqr(x) ((x) * (x))
#define INF 1000000000
#define MOD 1000000007
#define EPS 1e-9
#define line printf("===================\n")
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define MAX 1000000

int main ( ) {
    int n, l, r, id = 0, ans = 0;
    scanf ( "%d", &n );
    scanf ( "%d %d", &l, &r );
    for ( int i = 1 ; i < n ; i++ ) {
        int li, ri;
        scanf ( "%d %d", &li, &ri );
        if ( li <= l && r <= ri ) id = i;
        else if ( li < l || r < ri ) id = n;
        l = min ( l, li );
        r = max ( r, ri );
    }
    printf ( "%d", -1 if ( id == n ) else id + 1 );
    return 0;
}

