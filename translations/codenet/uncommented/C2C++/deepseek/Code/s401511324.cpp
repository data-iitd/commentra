#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n, tmp, cnt = 0;
  cin >> n;
  vector<int> l(n);
  for(int i = 0; i < n; i++){
    cin >> l[i];
  }
  sort(l.begin(), l.end());
  for(int i = 0; i < n-2; i++){
    for(int j = i+1; j < n-1; j++){
      for(int k = j+1; k < n; k++){
        if(l[i] + l[j] > l[k]){
          cnt++;
        }
        else{
          break;
        }
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
