
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void run(void){
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  vector<int> dp(k+1,0);
  for(int i=1;i<=k;i++){
    bool win=false;
    for(int j=0;j<n && a[j]<=i;j++){
      if(dp[i-a[j]]==0){
	win=true;
      }
    }
    dp[i]=win;
  }
  cout<<((dp[k])?"First":"Second")<<endl;
}

int main(void){
  run();
  return 0;
}

