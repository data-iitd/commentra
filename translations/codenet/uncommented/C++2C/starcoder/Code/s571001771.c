#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#define MAX 1005
#define MOD 1000000007
int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  int key[MAX], cost[MAX];
  for(int i=0;i<MAX;i++){
    key[i]=0;
    cost[i]=0;
  }
  for(int i=0;i<m;i++){
    scanf("%d", &cost[i]);
    int b;
    scanf("%d", &b);
    for(int j=0;j<b;j++){
      int c;
      scanf("%d", &c);
      key[i]+=(1<<(c-1));
    }
  }
  int dp[1<<MAX][MAX];
  for(int i=0;i<(1<<n);i++){
    for(int j=0;j<m;j++){
      dp[i][j+1]=INT_MAX;
    }
  }
  for(int i=0;i<m;i++){
    dp[0][i+1]=0;
  }
  for(int i=0;i<(1<<n);i++){
    for(int j=0;j<m;j++){
      dp[i][j+1]=min(dp[i][j], dp[i][j+1]);
      dp[i|key[j+1]][j+1]=min(dp[i|key[j+1]][j+1], dp[i][j]+cost[j+1]);
    }
  }
  if(dp[(1<<n)-1][m]==INT_MAX)printf("-1\n");
  else printf("%d\n", dp[(1<<n)-1][m]);
}

