
#include <iostream>

int main(){
  int K, X;
  // Read two integers, K and X, from the standard input
  std::cin >> K >> X;
  
  // Loop from X-K+1 to X+K-1
  for(int i = X - K + 1; i <= X + K - 1; i++){
    std::cout << i;
    // Print a space after each number except the last one
    if(i < X + K - 1) std::cout << " ";
  }
  // Print a newline character to move to the next line
  std::cout << std::endl;
  return 0;
}


