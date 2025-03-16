

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <cassert>
#include <climits>
#include <cctype>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 100000000
#define mod 100000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int main(){
	ll position; cin >> position;
	ll nrstSeqStartIndx = 1;
	while(1){
		ll val = nrstSeqStartIndx * ( nrstSeqStartIndx + 1 ) / 2;
		if(val >= position){
			break;
		}
		nrstSeqStartIndx *= 2;
	}
	while(1){
		ll val = nrstSeqStartIndx * ( nrstSeqStartIndx + 1 ) / 2;
		if(val > position){
			break;
		}
		nrstSeqStartIndx++;
	}
	ll startIndex = nrstSeqStartIndx * ( nrstSeqStartIndx - 1 ) / 2;
	cout << position - startIndex + 1 << endl;
}
