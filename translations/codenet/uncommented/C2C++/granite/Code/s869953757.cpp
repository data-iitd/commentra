
#include<iostream>
#include<queue>

#define M 100
#define whi 0
#define gra 1
#define bla 2

using namespace std;

int n;
int T[M][M];
int color[M],d[M];
queue<int> Q;

void bfs(int s){
  int i,u,v;
  
  for(i=0; i<n; i++){
    color[i] = whi;
    d[i] = 1000000;
  }

  color[s] = gra;
  d[s] = 0;
  Q.push(s);

  while(!Q.empty()){
    u = Q.front();
    Q.pop();
    for(v=0; v<n; v++){
      if(T[u][v] == 1 && color[v] == whi){
	color[v] = gra;
	d[v] = d[u]+1;
	Q.push(v);
      }
    }
    color[u] = bla;
  }
  
}

int main(){
  int i,j;
  int u,k,v;

  cin >> n;

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      T[i][j] = 0;
    }
  }

  for(i=0; i<n; i++){
    cin >> u >> k;
    u--;
    for(j=0; j<k; j++){
      cin >> v;
      v--;
      T[u][v] = 1;
    }
  }

  bfs(0);

  for(i=0; i<n; i++){
    if(d[i] == 1000000) d[i] = -1;
    cout << i+1 << " " << d[i] << endl;
  }

  return 0;
}
