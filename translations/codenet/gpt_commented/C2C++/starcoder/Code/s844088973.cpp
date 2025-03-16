#include <iostream>

int main(){
  // Declare two integer variables K and X
  int K, X;

  // Read two integers from standard input: K and X
  std::cin >> K >> X;

  // Loop from (X - K + 1) to (X + K - 1)
  for(int i = X - K + 1; i <= X + K - 1; i++){
    // Print the current value of i
    std::cout << i;
    
    // If i is not the last number, print a space after it
    if(i < X + K - 1) 
        std::cout << " ";
  }

  // Print a newline character after the loop completes
  std::cout << "\n";

  // Return 0 to indicate successful completion of the program
  return 0;
}
