#include <iostream>
using namespace std;
int main(void){
  int i,N,x;
  x = 0;
  cin >> N;
  for(i=1; i<=N; i++)
    x += i;
  cout << x << endl;
  return 0;
}
