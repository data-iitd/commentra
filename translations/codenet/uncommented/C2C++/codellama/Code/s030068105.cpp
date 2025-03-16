#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
  int n;
  int *data;
  cin >> n;
  data = (int*)malloc(sizeof(int)*n);
  for(int i=0; i<n; i++) cin >> data[i];
  int max = 0, index;
  for(int i=0; i<n; i++) if(data[i] > max) {max = data[i];index=i;}
  int a = 0;
  for(int i=0; i<n; i++) if(i != index) a += data[i];
  if(a > max)cout << "Yes\n";
  else cout << "No\n";
  return 0;
}
