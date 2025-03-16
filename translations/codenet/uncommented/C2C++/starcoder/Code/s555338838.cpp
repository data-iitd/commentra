#include <iostream>
using namespace std;

int main(){
  int key, i, j, len, a[101];
  cin >> len;
  for(i = 0;i < len;i++) cin >> a[i];

  for(j = 1;j < len;j++){
    for(i = 0;i < len;i++) cout << (i!= 0? " " : "") << a[i];
    cout << endl;
    key = a[j];
    for(i = j - 1;i >= 0 && a[i] > key;i--) a[i + 1] = a[i];
    a[i + 1] = key;
  }

  for(i = 0;i < len;i++) cout << (i!= 0? " " : "") << a[i];
  cout << endl;
  return 0;
}
