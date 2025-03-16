#include <iostream>

using namespace std;

int main(){
  int K,X;
  cin >> K >> X;
  for(int i=X-K+1;i<=X+K-1;i++){
    cout << i;
    if(i<X+K-1) cout << " ";
  }
  cout << "\n";
  return 0;
}
