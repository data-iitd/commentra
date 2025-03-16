
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <iomanip>
#include <queue>
#include <stack>
#include <bitset>
#include <utility>
#include <numeric>
#include <iterator>
#include <list>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long int_ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<string, int> msi;
typedef set<int> si;

#define FOR(i,a,b) for ( int i = (a); i <= (b); i++ )
#define RFOR(i,a,b) for ( int i = (a); i >= (b); i-- )
#define REP(i,n) FOR(i,1,n)
#define REP1(i,n) FOR(i,0,(n)-1)
#define RREP(i,n) RFOR(i,n,1)
#define RREP1(i,n) RFOR(i,(n)+1,1)
#define SZ(a) int (a).size()
#define ALL(a) a.begin(), a.end()
#define ALLR(a) a.rbegin(), a.rend()
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define POB pop_back
#define POF pop_front
#define EACH(it,c) for ( typeof( (c).begin() ) it=(c).begin(); it!=(c).end(); ++it )
#define EXIST(s,e) ( (s).find(e)!=(s).end() )
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(ALLR(c))
#define CLR(a) memset( a, 0, sizeof( a ) )
#define SET(a,v) memset( a, v, sizeof( a ) )
#define SZ(a) int (a).size()
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define POB pop_back
#define POF pop_front
#define EACH(it,c) for ( typeof( (c).begin() ) it=(c).begin(); it!=(c).end(); ++it )
#define EXIST(s,e) ( (s).find(e)!=(s).end() )
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(ALLR(c))
#define CLR(a) memset( a, 0, sizeof( a ) )
#define SET(a,v) memset( a, v, sizeof( a ) )
#define FOREACH(i,c) for ( auto i = (c).begin(); i!= (c).end(); ++i )
#define REP(i,n) for ( int i = 0; i < (int)(n); i++ )
#define REPN(i,m,n) for ( int i = (int)(m); i < (int)(n); i++ )
#define REP_REV(i,n) for ( int i = (int)(n)-1; i >= 0; i-- )
#define REPN_REV(i,m,n) for ( int i = (int)(n)-1; i >= (int)(m); i-- )
#define REP_STR(i,s) for ( char i = s; i <= 'z'; i++ )
#define REPN_STR(i,s,e) for ( char i = s; i <= e; i++ )
#define REP_CSTR(i,s) for ( const char* i = s; *i; i++ )
#define FOREACH(it,o) for ( auto it = (o).begin(); it!= (o).end(); ++it )
#define FOR(i,a,b) for ( int i = (a); i < (int)(b); i++ )
#define ALL(o) (o).begin(), (o).end()
#define ALLR(o) (o).rbegin(), (o).rend()
#defineSZ(a) int((a).size())
#define EACH(i,c) for ( auto i = (c).begin(); i!= (c).end(); ++i )
#define EXIST(s,e) ((s).find(e)!= (s).end())
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(ALLR(c))
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a,v) memset(a,v,sizeof(a))
#define DEBUG if(1)
#define DUMP(x)  cerr << #x << " = " << (x)
#define DUMP2(x,y) cerr<<"("<<#x<<","<<#y<<") = ("<<x<<","<<y<<")\n"
#define DUMP3(x,y,z) cerr<<"("<<#x<<","<<#y<<","<<#z<<") = ("<<x<<","<<y<<","<<z<<")\n"
#define X first
#define Y second
#define bitcount __builtin_popcount
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REPN(i,m,n) for(int i=(int)(m);i<(int)(n);++i)
#define REP_REV(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define REPN_REV(i,m,n) for(int i=(int)(n)-1;i>=(int)(m);--i)
#define ALL(c) c.begin(),c.end()
#define LL long long
#define ULL unsigned long long
#define TUPLE tuple<LL,LL,LL>
#define QT(T) const T&
#define DUMPOUT cerr
#define dump(...) DUMPOUT<<"  ";DUMPOUT<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl;DUMPOUT<<"    ";dump_func(__VA_ARGS__)

using uint = unsigned int;
usingull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<long long>;
using vvl = vector<vl>;
using vd = vector<double>;
using vvd = vector<vd>;
using vs = vector<string>;

template<typename T1,typename T2> ostream& operator<<(ostream& os, const pair<T1,T2>& p){os << p.first<<" "<<p.second; return os;}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v){for(int i=0;i<v.size();i++) os<<v[i]<<" "; return os;}
template<typename T> ostream& operator<<(ostream& os, const vector<vector<T>>& v){for(int i=0;i<v.size();i++) os<<v[i]<<endl; return os;}
template<typename T> ostream& operator<<(ostream& os, const...