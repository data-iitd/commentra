#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define LEN 100005

typedef struct pp{
  string name;
  int t;
}P;

queue<P> Q;

int min(int a, int b){
  return a < b ? a : b;
}

int main(){
  int elaps = 0, c;
  int i, q;
  P u;

  cin >> n >> q;

  for(i = 1 ; i <= n ; i++){
    cin >> u.name >> u.t;
    Q.push(u);
  }

  while(!Q.empty()){
    u = Q.front();
    Q.pop();
    c = min(q,u.t);
    u.t -= c;
    elaps += c;
    if(u.t > 0) Q.push(u);
    else{
      cout << u.name << " " << elaps << endl;
    }
  }

  return 0;
}

