
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()

int main(){
  string s; cin >> s;
  int score = 0;
  REP(i,s.size()){
    char my = i%2==0?'g':'p';
    char his = s[i];
    if(my!=his) score += my=='p'?1:-1;
  }
  cout << score << endl;
  return 0;
}
//END-OF-CODE