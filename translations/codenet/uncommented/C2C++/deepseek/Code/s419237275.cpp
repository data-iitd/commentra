#include <iostream>
#include <vector>
using namespace std;

#define N 200
#define SHIRO 0
#define HAI 1
#define KURO 2

void aaaaa();
void bbbbb(int);

int n,A[N][N];
int color[N],d[N],f[N];
int TT;

int main() {

  int u,k,v;
  int i,j;

  cin >> n;

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j] = 0;
    }
  }
  for(i=0;i<n;i++){
    cin >> u >> k;
    u--;
    for(j=0;j<k;j++){
      cin >> v;
      v--;
      A[u][v] = 1;
    }
  }

  aaaaa();

  return 0;
}


void aaaaa() {
  int u,i;

  for(i=0;i<n;i++){
    color[i] = SHIRO;
  }
    
  TT = 0;

  for(u=0;u<n;u++){
    if(color[u] == SHIRO){
      bbbbb(u);
    }
  }

  for(i = 0;i<n;i++){
    cout << i+1 << " " << d[i] << " " << f[i] << endl;
  }
}

void bbbbb(int k) {
  int v;
  color[k] = HAI;
  TT++;
  d[k] = TT;
  for(v=0;v<n;v++){
    if(A[k][v] == 0) continue;
    if(color[v] == SHIRO){
      bbbbb(v);
    }
  }
  color[k] = KURO;
  f[k] = ++TT;
}

