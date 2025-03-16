
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <map>
#include <set>
#define END-OF-CODE

int main(){
  int n, m;scanf("%d %d",&n,&m); // Read the number of keys (n) and items (m)
  int key[1005]={0}; // Array to store the keys in a binary format
  int cost[1005]={0}; // Array to store the cost of each item
  int dp[(1<<12)+5][1005]={0}; // 2D array for dynamic programming
  const int INF=1234567890; // Constant for infinity
  for(int i=0;i<(1<<12)+5;i++){ // Initialize the dp array with infinity
    for(int j=0;j<1005;j++){
      dp[i][j]=INF;
    }
  }
  dp[0][0]=0; // Base case: no keys and no cost

  for(int i=1;i<=m;i++){ // Read the cost and keys for each item
    int b;
    scanf("%d %d",&cost[i],&b);
    for(int j=0;j<b;j++){
      int c;
      scanf("%d",&c);
      key[i]+=(1<<(c-1)); // Convert key information into binary format
    }
  }

  for(int i=0;i<(1<<n);i++){ // Iterate through all possible states
    for(int j=0;j<m;j++){
      dp[i][j+1]=std::min(dp[i][j],dp[i][j+1]); // Update the dp array based on the current state
      dp[i|key[j+1]][j+1]=std::min(dp[i|key[j+1]][j+1],dp[i][j]+cost[j+1]); // Update the dp array based on the next state
    }
  }

  if(dp[(1<<n)-1][m]==INF)printf("-1\n"); // Check if it's not possible to collect all keys and output -1
  else printf("%d\n",dp[(1<<n)-1][m]); // Output the minimum cost to collect all keys
  return 0;
