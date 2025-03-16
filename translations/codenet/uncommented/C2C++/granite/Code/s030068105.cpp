
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> data(n);
  for(int i=0; i<n; i++) cin >> data[i];
  int max = 0, index;
  for(int i=0; i<n; i++) if(data[i] > max) {max = data[i];index=i;}
  int a = 0;
  for(int i=0; i<n; i++) if(i!= index) a += data[i];
  if(a > max)cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
