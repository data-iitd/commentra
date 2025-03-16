#include <iostream>
using namespace std;

int main(void){
  int i, a, b, s;
  int count[4];
  for(i = 0;i < 4;i++) count[i] = 0;
  for(i = 0;i < 3;i++){
    cin >> a >> b;
    count[a-1]++;
    count[b-1]++;
  }
  s = 1;
  for(i = 0;i < 4;i++) s *= count[i];
  if(s == 4) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}

