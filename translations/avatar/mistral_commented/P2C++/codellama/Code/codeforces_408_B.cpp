#######
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define beg(x) x.begin()
#define en(x) x.end()
#define rbeg(x) x.rbegin()
#define ren(x) x.rend()
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define sz(x) (int)(x).size()
#define prec(n) fixed<<setprecision(n)
#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define vvi vector<vi>
#define vvll vector<vll>
#define vvld vector<vld>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define piii pair<int, pii>
#define plll pair<ll, pll>
#define pllld pair<ll, pld>
#define piiii pair<pii, int>
#define pllll pair<pll, ll>
#define plllld pair<pll, ld>
#define piiiii pair<piii, int>
#define plllll pair<plll, ll>
#define pllllld pair<plll, ld>
#define piiiiii pair<piiii, int>
#define pllllll pair<pllll, ll>
#define plllllld pair<pllll, ld>
#define piiiiiii pair<piiiii, int>
#define plllllll pair<plllll, ll>
#define pllllllld pair<plllll, ld>
#define piiiiiiii pair<piiiiii, int>
#define pllllllll pair<pllllll, ll>
#define plllllllld pair<pllllll, ld>
#define piiiiiiiii pair<piiiiiii, int>
#define plllllllll pair<plllllll, ll>
#define pllllllllld pair<plllllll, ld>
#define piiiiiiiiii pair<piiiiiiii, int>
#define pllllllllll pair<pllllllll, ll>
#define plllllllllld pair<pllllllll, ld>
#define piiiiiiiiiii pair<piiiiiiiii, int>
#define plllllllllll pair<plllllllll, ll>
#define pllllllllllld pair<plllllllll, ld>
#define piiiiiiiiiiii pair<piiiiiiiiii, int>
#define pllllllllllll pair<pllllllllll, ll>
#define plllllllllllld pair<pllllllllll, ld>
#define piiiiiiiiiiiii pair<piiiiiiiiiii, int>
#define plllllllllllll pair<plllllllllll, ll>
#define pllllllllllllld pair<plllllllllll, ld>
#define piiiiiiiiiiiiii pair<piiiiiiiiiiii, int>
#define pllllllllllllll pair<pllllllllllll, ll>
#define plllllllllllllld pair<pllllllllllll, ld>
#define piiiiiiiiiiiiiii pair<piiiiiiiiiiiii, int>
#define plllllllllllllll pair<plllllllllllll, ll>
#define pllllllllllllllld pair<plllllllllllll, ld>
#define piiiiiiiiiiiiiiii pair<piiiiiiiiiiiiii, int>
#define pllllllllllllllll pair<pllllllllllllll, ll>
#define plllllllllllllllld pair<pllllllllllllll, ld>
#define piiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiii, int>
#define plllllllllllllllll pair<plllllllllllllll, ll>
#define pllllllllllllllllld pair<plllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiii, int>
#define pllllllllllllllllll pair<pllllllllllllllll, ll>
#define plllllllllllllllllld pair<pllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiii, int>
#define plllllllllllllllllll pair<plllllllllllllllll, ll>
#define pllllllllllllllllllld pair<plllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiii, int>
#define pllllllllllllllllllll pair<pllllllllllllllllll, ll>
#define plllllllllllllllllllld pair<pllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiii, int>
#define plllllllllllllllllllll pair<plllllllllllllllllll, ll>
#define pllllllllllllllllllllld pair<plllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiii, int>
#define pllllllllllllllllllllll pair<pllllllllllllllllllll, ll>
#define plllllllllllllllllllllld pair<pllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiii, int>
#define plllllllllllllllllllllll pair<plllllllllllllllllllll, ll>
#define pllllllllllllllllllllllld pair<plllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiii, int>
#define pllllllllllllllllllllllll pair<pllllllllllllllllllllll, ll>
#define plllllllllllllllllllllllld pair<pllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiii, int>
#define plllllllllllllllllllllllll pair<plllllllllllllllllllllll, ll>
#define pllllllllllllllllllllllllld pair<plllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiii, int>
#define pllllllllllllllllllllllllll pair<pllllllllllllllllllllllll, ll>
#define plllllllllllllllllllllllllld pair<pllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define plllllllllllllllllllllllllll pair<plllllllllllllllllllllllll, ll>
#define pllllllllllllllllllllllllllld pair<plllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define pllllllllllllllllllllllllllll pair<pllllllllllllllllllllllllll, ll>
#define plllllllllllllllllllllllllllld pair<pllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define plllllllllllllllllllllllllllll pair<plllllllllllllllllllllllllll, ll>
#define pllllllllllllllllllllllllllllld pair<plllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define pllllllllllllllllllllllllllllll pair<pllllllllllllllllllllllllllll, ll>
#define plllllllllllllllllllllllllllllld pair<pllllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define plllllllllllllllllllllllllllllll pair<plllllllllllllllllllllllllllll, ll>
#define pllllllllllllllllllllllllllllllld pair<plllllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define pllllllllllllllllllllllllllllllll pair<pllllllllllllllllllllllllllllll, ll>
#define plllllllllllllllllllllllllllllllld pair<pllllllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define plllllllllllllllllllllllllllllllll pair<plllllllllllllllllllllllllllllll, ll>
#define pllllllllllllllllllllllllllllllllld pair<plllllllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define pllllllllllllllllllllllllllllllllll pair<pllllllllllllllllllllllllllllllll, ll>
#define plllllllllllllllllllllllllllllllllld pair<pllllllllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define plllllllllllllllllllllllllllllllllll pair<plllllllllllllllllllllllllllllllll, ll>
#define pllllllllllllllllllllllllllllllllllld pair<plllllllllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define pllllllllllllllllllllllllllllllllllll pair<pllllllllllllllllllllllllllllllllll, ll>
#define plllllllllllllllllllllllllllllllllllld pair<pllllllllllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define plllllllllllllllllllllllllllllllllllll pair<plllllllllllllllllllllllllllllllllll, ll>
#define pllllllllllllllllllllllllllllllllllllld pair<plllllllllllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define pllllllllllllllllllllllllllllllllllllll pair<pllllllllllllllllllllllllllllllllllll, ll>
#define plllllllllllllllllllllllllllllllllllllld pair<pllllllllllllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define plllllllllllllllllllllllllllllllllllllll pair<plllllllllllllllllllllllllllllllllllll, ll>
#define pllllllllllllllllllllllllllllllllllllllld pair<plllllllllllllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define plllllllllllllllllllllllllllllllllllllllll pair<pllllllllllllllllllllllllllllllllllllll, ll>
#define plllllllllllllllllllllllllllllllllllllllld pair<plllllllllllllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define pllllllllllllllllllllllllllllllllllllllllll pair<pllllllllllllllllllllllllllllllllllllll, ll>
#define pllllllllllllllllllllllllllllllllllllllllld pair<pllllllllllllllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define plllllllllllllllllllllllllllllllllllllllllll pair<plllllllllllllllllllllllllllllllllllllll, ll>
#define plllllllllllllllllllllllllllllllllllllllllld pair<plllllllllllllllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define pllllllllllllllllllllllllllllllllllllllllllll pair<pllllllllllllllllllllllllllllllllllllllll, ll>
#define pllllllllllllllllllllllllllllllllllllllllllld pair<plllllllllllllllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define plllllllllllllllllllllllllllllllllllllllllllll pair<plllllllllllllllllllllllllllllllllllllllll, ll>
#define plllllllllllllllllllllllllllllllllllllllllllld pair<plllllllllllllllllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define plllllllllllllllllllllllllllllllllllllllllllllll pair<pllllllllllllllllllllllllllllllllllllllllll, ll>
#define plllllllllllllllllllllllllllllllllllllllllllllld pair<plllllllllllllllllllllllllllllllllllllllll, ld>
#define piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii pair<piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii, int>
#define plllllllllllllllllllllllllllllllllllllllllllllllll pair<plllllllllllllllllllllllllllllllllllllllllll, ll>
#define plllllllllllllllllllllllllllllllllllllll