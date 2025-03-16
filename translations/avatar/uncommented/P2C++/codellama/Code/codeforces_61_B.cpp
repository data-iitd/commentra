#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define mod 1000000007
#define inf 1e18
#define pi 3.14159265358979323846
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define tr(c, it) for (auto it = (c).begin(); it != (c).end(); it++)
#define trr(c, it) for (auto it = (c).rbegin(); it != (c).rend(); it +)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repi(i, a, b) for (int i = a; i <= b; i++)
#define rrep(i, a, b) for (int i = a; i > b; i--)
#define rrepi(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vpdd vector<pdd>
#define mii map<int, int>
#define mll map<ll, ll>
#define mpii map<pii, int>
#define mpll map<pll, ll>
#define mdd map<double, double>
#define umii unordered_map<int, int>
#define umll unordered_map<ll, ll>
#define umpii unordered_map<pii, int>
#define umpll unordered_map<pll, ll>
#define umdd unordered_map<double, double>
#define umss unordered_map<string, string>
#define uss unordered_set<string>
#define usi unordered_set<int>
#define usl unordered_set<ll>
#define usp unordered_set<pii>
#define uspl unordered_set<pll>
#define uspd unordered_set<pdd>
#define ussll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define ussllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll unordered_set<pll, hash<pll>, equal_to<pll>, allocator<pll>>
#define usslllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll