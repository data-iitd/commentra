
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int main(){
  int n,m;
  int i;
  int a[100006];
  int b[100006];
  int cnt = 0;
  int t;

  cin >> n >> m;

  for(i = 0;i < m;i++) cin >> a[i] >> b[i];

  vector<pair<int,int> > v;
  for(i = 0;i < m;i++) v.push_back(make_pair(a[i],b[i]));

  sort(v.begin(),v.end());

  t = 0;
  for(i = 0;i < m;i++){
    if(t <= v[i].first){
      t = v[i].second;
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}
