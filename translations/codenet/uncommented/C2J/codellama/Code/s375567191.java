#include <stdio.h>
#define MAX 101
#define WHITE 0
#define BLACK 2
#define GRAY 1
int time,n,g[MAX][MAX] = {0};
int d[MAX],f[MAX],color[MAX] = {WHITE};

void visit(int u){
  int i;

  color[u] = GRAY;
  d[u] = ++time;

  for(i=0;i<n;i++){
    if(g[u][i] == 0)
      continue;
    if(color[i] ==WHITE)
      visit(i);
  }

  color[u] = BLACK;
  f[u] = ++time;
}

void dfs(void){
  int i;
  time = 0;

  for(i=0;i<n;i++)
    if(color[i] == WHITE)
      visit(i);

  for(i=0;i<n;i++)
    System.out.println(i+1+" "+d[i]+" "+f[i]);
}

public class Main{
  public static void main(String[] args){
    int i,j,x,y,z;

    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();

    for(i=0;i<n;i++){
      x = sc.nextInt();
      y = sc.nextInt();
      for(j=0;j<y;j++){
        z = sc.nextInt();
        g[x-1][z-1] = 1;
      }
    }

    dfs();
  }
}

