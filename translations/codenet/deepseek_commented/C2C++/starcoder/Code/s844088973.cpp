#include <iostream>

using namespace std;

int main(){
  int K, X;
  // Read two integers, K and X, from the standard input
  cin >> K >> X;
  
  // Loop from X-K+1 to X+K-1
  for(int i = X - K + 1; i <= X + K - 1; i++){
    cout << i;
    // Print a space after each number except the last one
    if(i < X + K - 1) cout << " ";
  }
  // Print a newline character to move to the next line
  cout << "\n";
  return 0;
}
