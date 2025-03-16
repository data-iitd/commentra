#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
#define INF 123456789012 // Define necessary data types and constants
typedef long long ll;
typedef pair<ll,ll>PP;
ll key[1005]={0}; // Initialize arrays here
ll cost[1005]={0};
ll dp[(1<<12)+5][1005]={0}; // 2D dynamic programming table

int main(){
  // Read input
  ll n, m; // n is the number of switches, m is the number of bulbs
  cin>>n>>m;

  // Initialize dynamic programming table with infinite values
  for(int i=0;i<(1<<12)+5;i++){
    for(int j=0;j<1005;j++){
      dp[i][j]=INF; // Set all values to infinite
    }
  }
  dp[0][0]=0; // Set the initial value of dp[0][0] to 0

  // Read bulbs' information
  for(int i=1;i<=m;i++){
    ll b; // The number of switches needed to turn on this bulb
    cin>>cost[i]>>b;

    // Update key array
    for(int j=0;j<b;j++){
      ll c; // The position of the switch
      cin>>c;
      key[i]+=(1<<(c-1)); // Set the corresponding bit in key[i] to 1
    }
  }

  // Fill dynamic programming table
  for(ll i=0;i<(1<<n);i++){ // Iterate through all possible combinations of switches
    for(int j=0;j<m;j++){ // Iterate through all bulbs
      dp[i][j+1]=min(dp[i][j],dp[i][j+1]); // Update dp[i][j+1] with the minimum value between dp[i][j] and dp[i][j+1]
      dp[i|key[j+1]][j+1]=min(dp[i|key[j+1]][j+1],dp[i][j]+cost[j+1]); // Update dp[i|key[j+1]][j+1] with the minimum value between dp[i|key[j+1]][j+1] and dp[i][j]+cost[j+1]
    }
  }

  // Output result
  if(dp[(1<<n)-1][m]==INF)cout<<-1<<endl; // Check if the minimum cost is infinite
  else cout<<dp[(1<<n)-1][m]<<endl; // Output the minimum cost
}

