#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define sqr(x) ((x)*(x))
#define INF 1000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vpii> vvpii;
typedef set<int> si;
typedef set<ll> sll;
typedef set<pii> spii;
typedef set<vi> svi;
typedef set<vll> svll;
typedef set<vpii> svpii;
typedef multiset<int> msi;
typedef multiset<ll> msll;
typedef multiset<pii> mpii;
typedef multiset<vi> mvi;
typedef multiset<vll> mvll;
typedef multiset<vpii> mvpii;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef map<pii,pii> mpii;
typedef map<vi,vi> mvi;
typedef map<vll,vll> mvll;
typedef map<vpii,vpii> mvpii;

int main ( ) {
    int n;
    scanf ( "%d", &n );
    char s[100000];
    int march[5] = {0};
    for ( int i = 0 ; i < n ; i++ ) {
        scanf ( "%s", s );
        if ( s[0] == 'M' || s[0] == 'A' || s[0] == 'R' || s[0] == 'C' || s[0] == 'H' )
            march[s[0] - 'A']++;
    }
    int ans = 0;
    for ( int i = 0 ; i < 5 ; i++ )
        for ( int j = 0 ; j < 5 ; j++ )
            for ( int k = 0 ; k < 5 ; k++ )
                if ( i!= j && j!= k && k!= i )
                    ans += march[i] * march[j] * march[k];
    printf ( "%d", ans );
    return 0;
}

