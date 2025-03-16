#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX 1000000000
#define MOD 1000000007
#define N 1000000
#define ll long long
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vvii vector<vector<pii> >
#define vvll vector<vector<pll> >
#define vvvii vector<vector<vector<pii> > >
#define vvvll vector<vector<vector<pll> > >
#define vvvvii vector<vector<vector<vector<pii> > > >
#define vvvvll vector<vector<vector<vector<pll> > > >
#define vvvvvii vector<vector<vector<vector<vector<pii> > > > >
#define vvvvvll vector<vector<vector<vector<vector<pll> > > > >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define mprep(i,a,b) for(int i=a;i<b;i+=a)
#define mper(i,a,b) for(int i=a;i>b;i-=a)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vvii vector<vector<pii> >
#define vvll vector<vector<pll> >
#define vvvii vector<vector<vector<pii> > >
#define vvvll vector<vector<vector<pll> > >
#define vvvvii vector<vector<vector<vector<pii> > > >
#define vvvvll vector<vector<vector<vector<pll> > > >
#define vvvvvii vector<vector<vector<vector<vector<pii> > > > >
#define vvvvvll vector<vector<vector<vector<vector<pll> > > > >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define mprep(i,a,b) for(int i=a;i<b;i+=a)
#define mper(i,a,b) for(int i=a;i>b;i-=a)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vvii vector<vector<pii> >
#define vvll vector<vector<pll> >
#define vvvii vector<vector<vector<pii> > >
#define vvvll vector<vector<vector<pll> > >
#define vvvvii vector<vector<vector<vector<pii> > > >
#define vvvvll vector<vector<vector<vector<pll> > > >
#define vvvvvii vector<vector<vector<vector<vector<pii> > > > >
#define vvvvvll vector<vector<vector<vector<vector<pll> > > > >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define mprep(i,a,b) for(int i=a;i<b;i+=a)
#define mper(i,a,b) for(int i=a;i>b;i-=a)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vvii vector<vector<pii> >
#define vvll vector<vector<pll> >
#define vvvii vector<vector<vector<pii> > >
#define vvvll vector<vector<vector<pll> > >
#define vvvvii vector<vector<vector<vector<pii> > > >
#define vvvvll vector<vector<vector<vector<pll> > > >
#define vvvvvii vector<vector<vector<vector<vector<pii> > > > >
#define vvvvvll vector<vector<vector<vector<vector<pll> > > > >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define mprep(i,a,b) for(int i=a;i<b;i+=a)
#define mper(i,a,b) for(int i=a;i>b;i-=a)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vvii vector<vector<pii> >
#define vvll vector<vector<pll> >
#define vvvii vector<vector<vector<pii> > >
#define vvvll vector<vector<vector<pll> > >
#define vvvvii vector<vector<vector<vector<pii> > > >
#define vvvvll vector<vector<vector<vector<pll> > > >
#define vvvvvii vector<vector<vector<vector<vector<pii> > > > >
#define vvvvvll vector<vector<vector<vector<vector<pll> > > > >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define mprep(i,a,b) for(int i=a;i<b;i+=a)
#define mper(i,a,b) for(int i=a;i>b;i-=a)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vvii vector<vector<pii> >
#define vvll vector<vector<pll> >
#define vvvii vector<vector<vector<pii> > >
#define vvvll vector<vector<vector<pll> > >
#define vvvvii vector<vector<vector<vector<pii> > > >
#define vvvvll vector<vector<vector<vector<pll> > > >
#define vvvvvii vector<vector<vector<vector<vector<pii> > > > >
#define vvvvvll vector<vector<vector<vector<vector<pll> > > > >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define mprep(i,a,b) for(int i=a;i<b;i+=a)
#define mper(i,a,b) for(int i=a;i>b;i-=a)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vvii vector<vector<pii> >
#define vvll vector<vector<pll> >
#define vvvii vector<vector<vector<pii> > >
#define vvvll vector<vector<vector<pll> > >
#define vvvvii vector<vector<vector<vector<pii> > > >
#define vvvvll vector<vector<vector<vector<pll> > > >
#define vvvvvii vector<vector<vector<vector<vector<pii> > > > >
#define vvvvvll vector<vector<vector<vector<vector<pll> > > > >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define mprep(i,a,b) for(int i=a;i<b;i+=a)
#define mper(i,a,b) for(int i=a;i>b;i-=a)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vvii vector<vector<pii> >
#define vvll vector<vector<pll> >
#define vvvii vector<vector<vector<pii> > >
#define vvvll vector<vector<vector<pll> > >
#define vvvvii vector<vector<vector<vector<pii> > > >
#define vvvvll vector<vector<vector<vector<pll> > > >
#define vvvvvii vector<vector<vector<vector<vector<pii> > > > >
#define vvvvvll vector<vector<vector<vector<vector<pll> > > > >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define mprep(i,a,b) for(int i=a;i<b;i+=a)
#define mper(i,a,b) for(int i=a;i>b;i-=a)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vvii vector<vector<pii> >
#define vvll vector<vector<pll> >
#define vvvii vector<vector<vector<pii> > >
#define vvvll vector<vector<vector<pll> > >
#define vvvvii vector<vector<vector<vector<pii> > > >
#define vvvvll vector<vector<vector<vector<pll> > > >
#define vvvvvii vector<vector<vector<vector<vector<pii> > > > >
#define vvvvvll vector<vector<vector<vector<vector<pll> > > > >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define mprep(i,a,b) for(int i=a;i<b;i+=a)
#define mper(i,a,b) for(int i=a;i>b;i-=a)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vvii vector<vector<pii> >
#define vvll vector<vector<pll> >
#define vvvii vector<vector<vector<pii> > >
#define vvvll vector<vector<vector<pll> > >
#define vvvvii vector<vector<vector<vector<pii> > > >
#define vvvvll vector<vector<vector<vector<pll> > > >
#define vvvvvii vector<vector<vector<vector<vector<pii> > > > >
#define vvvvvll vector<vector<vector<vector<vector<pll> > > > >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define mprep(i,a,b) for(int i=a;i<b;i+=a)
#define mper(i,a,b) for(int i=a;i>b;i-=a)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vvii vector<vector<pii> >
#define vvll vector<vector<pll> >
#define vvvii vector<vector<vector<pii> > >
#define vvvll vector<vector<vector<pll> > >
#define vvvvii vector<vector<vector<vector<pii> > > >
#define vvvvll vector<vector<vector<vector<pll> > > >
#define vvvvvii vector<vector<vector<vector<vector<pii> > > > >
#define vvvvvll vector<vector<vector<vector<vector<pll> > > > >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define mprep(i,a,b) for(int i=a;i<b;i+=a)
#define mper(i,a,b) for(int i=a;i>b;i-=a)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vvii vector<vector<pii> >
#define vvll vector<vector<pll> >
#define vvvii vector<vector<vector<pii> > >
#define vvvll vector<vector<vector<pll> > >
#define vvvvii vector<vector<vector<vector<pii> > > >
#define vvvvll vector<vector<vector<vector<pll> > > >
#define vvvvvii vector<vector<vector<vector<vector<pii> > > > >
#define vvvvvll vector<vector<vector<vector<vector<pll> > > > >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define mprep(i,a,b) for(int i=a;i<b;i+=a)
#define mper(i,a,b) for(int i=a;i>b;i-=a)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vvii vector<vector<pii> >
#define vvll vector<vector<pll> >
#define vvvii vector<vector<