#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int n,i;
  vector<int> h(100001);
  int max = -1;
  bool flag = false;

  cin >> n;

  for(i = 0;i < n;i++){
    cin >> h[i];
    if(max < h[i]) max = h[i];

    if(max - h[i] >= 2) flag = true;
  }

  if(flag) cout << "No" << endl;
  else cout << "Yes" << endl;

  return 0;
}

