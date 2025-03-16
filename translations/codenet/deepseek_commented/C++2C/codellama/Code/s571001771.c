#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define INF 123456789012

int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  int key[1005]={0};
  int cost[1005]={0};
  int dp[(1<<12)+5][1005]={0};
  for(int i=0;i<(1<<12)+5;i++){
    for(int j=0;j<1005;j++){
      dp[i][j]=INF;
    }
  }
  dp[0][0]=0;

  for(int i=1;i<=m;i++){
    int b;
    scanf("%d %d", &cost[i], &b);
    for(int j=0;j<b;j++){
      int c;
      scanf("%d", &c);
      key[i]+=(1<<(c-1));
    }
  }

  for(int i=0;i<(1<<n);i++){
    for(int j=0;j<m;j++){
      dp[i][j+1]=min(dp[i][j],dp[i][j+1]);
      dp[i|key[j+1]][j+1]=min(dp[i|key[j+1]][j+1],dp[i][j]+cost[j+1]);
    }
  }

  if(dp[(1<<n)-1][m]==INF)printf("-1\n");
  else printf("%d\n", dp[(1<<n)-1][m]);
}

