#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vpii> vvpii;
typedef set<int> si;
typedef set<ll> sll;
typedef set<ull> sull;
typedef set<pii> spii;
typedef set<vi> svi;
typedef set<vll> svll;
typedef set<vull> svull;
typedef set<vpii> svpii;
typedef multiset<int> msi;
typedef multiset<ll> msll;
typedef multiset<ull> msull;
typedef multiset<pii> mspii;
typedef multiset<vi> msvi;
typedef multiset<vll> msvll;
typedef multiset<vull> msvull;
typedef multiset<vpii> msvpii;
typedef map<int, int> mii;
typedef map<ll, ll> ml;
typedef map<ull, ull> mull;
typedef map<pii, pii> mpii;
typedef map<vi, vi> mvi;
typedef map<vll, vll> mvll;
typedef map<vull, vull> mvull;
typedef map<vpii, vpii> mvpii;
typedef map<string, int> msii;
typedef map<string, ll> msll;
typedef map<string, pii> mppii;
typedef map<string, vi> msvi;
typedef map<string, vll> msvll;
typedef map<string, vull> msvull;
typedef map<string, vpii> msvpii;
typedef map<int, string> mis;
typedef map<ll, string> msis;
typedef map<pii, string> mpis;
typedef map<vi, string> mvs;
typedef map<vll, string> mvs;
typedef map<vull, string> mvs;
typedef map<vpii, string> mvs;
int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        char s[n];
        scanf("%s", s);
        int a = 0, b = 0;
        for(int j = 0; j < n; j++)
        {
            if(s[j] == 'O') a++;
            else b++;
        }
        if(a == b)
        {
            printf("1 12\n");
            continue;
        }
        if(a > b)
        {
            printf("0\n");
            continue;
        }
        int ans = 0;
        for(int j = 1; j <= 12; j++)
        {
            if(j * a == b)
            {
                ans++;
                printf("%d %d\n", j, a);
            }
        }
        if(ans == 0) printf("0\n");
    }
    return 0;
}
