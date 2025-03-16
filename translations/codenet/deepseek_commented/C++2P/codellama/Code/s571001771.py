#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PP;
ll key[1005]={0}; // Array to store the keys in a binary format
ll cost[1005]={0}; // Array to store the cost of each item
ll dp[(1<<12)+5][1005]={0}; // 2D array for dynamic programming
const ll INF=123456789012; // Constant for infinity

int main(){
  ll n, m;cin>>n>>m; // Read the number of keys (n) and items (m)
  for(int i=0;i<(1<<12)+5;i++){ // Initialize the dp array with infinity
    for(int j=0;j<1005;j++){
      dp[i][j]=INF;
    }
  }
  dp[0][0]=0; // Base case: no keys and no cost

  for(int i=1;i<=m;i++){ // Read the cost and keys for each item
    ll b;
    cin>>cost[i]>>b;
    for(int j=0;j<b;j++){
      ll c;
      cin>>c;
      key[i]+=(1<<(c-1)); // Convert key information into binary format
    }
  }

  for(ll i=0;i<(1<<n);i++){ // Iterate through all possible states
    for(int j=0;j<m;j++){
      dp[i][j+1]=min(dp[i][j],dp[i][j+1]); // Update the dp array based on the current state
      dp[i|key[j+1]][j+1]=min(dp[i|key[j+1]][j+1],dp[i][j]+cost[j+1]); // Update the dp array based on the next state
    }
  }

  if(dp[(1<<n)-1][m]==INF)cout<<-1<<endl; // Check if it's not possible to collect all keys and output -1
  else cout<<dp[(1<<n)-1][m]<<endl; // Output the minimum cost to collect all keys
}

