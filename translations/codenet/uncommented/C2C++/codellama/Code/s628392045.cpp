#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

int main(){
  int n,i;
  int h[100001];
  int max = -1;
  int flag = 0;

  cin >> n;

  for(i = 0;i < n;i++){
    cin >> h[i];
    if(max < h[i]) max = h[i];

    if(max - h[i] >= 2) flag = 1;
  }

  if(flag == 1) cout << "No\n";

  else cout << "Yes\n";

  return 0;
}

