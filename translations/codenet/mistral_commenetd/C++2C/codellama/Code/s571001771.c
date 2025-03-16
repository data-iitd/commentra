#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define INF 123456789012

int main(){
  // Read input
  int n, m;
  scanf("%d %d", &n, &m);

  // Initialize dynamic programming table with infinite values
  int dp[(1<<12)+5][1005];
  memset(dp, INF, sizeof(dp));
  dp[0][0]=0;

  // Read bulbs' information
  int key[1005];
  int cost[1005];
  for(int i=1;i<=m;i++){
    int b;
    scanf("%d %d", &cost[i], &b);
    key[i]=0;
    for(int j=0;j<b;j++){
      int c;
      scanf("%d", &c);
      key[i]+=(1<<(c-1));
    }
  }

  // Fill dynamic programming table
  for(int i=0;i<(1<<n);i++){
    for(int j=0;j<m;j++){
      dp[i][j+1]=min(dp[i][j],dp[i][j+1]);
      dp[i|key[j+1]][j+1]=min(dp[i|key[j+1]][j+1],dp[i][j]+cost[j+1]);
    }
  }

  // Output result
  if(dp[(1<<n)-1][m]==INF)printf("-1\n");
  else printf("%d\n", dp[(1<<n)-1][m]);
}

