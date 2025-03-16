
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define INF 1e18
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define rrep(i,a,b) for (int i = (a); i > (b); --i)
#define vll vector<ll>
#define vpi vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define vvi vector<vector<int>>
#define vvp vector<vector<pair<int,int>>>
#define vvpi vector<vector<pair<int,pi>>>
#define vvvpi vector<vector<vector<pair<int,pi>>>>
#define vvl vector<vector<ll>>
#define vvp vector<vector<pair<ll,ll>>>
#define vvvp vector<vector<vector<pair<ll,ll>>>>
#define vvvvp vector<vector<vector<vector<pair<ll,ll>>>>>
#define vvvvvp vector<vector<vector<vector<vector<pair<ll,ll>>>>>>
#define vvvvvvp vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>
#define vvvvvvvp vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>
#define vvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>
#define vvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>
#define vvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>
#define vvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>
#define vvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>
#define vvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvp vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<ll,ll>>>>>>>>>>>>>>>>
