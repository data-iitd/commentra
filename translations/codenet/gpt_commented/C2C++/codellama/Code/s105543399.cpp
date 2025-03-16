#include <iostream>

int main() {
  // Declare variables
  long long n, a, m, M, c, b, i;
  
  // Initialize cumulative sum and set initial min and max values
  c = 0; // Cumulative sum of the numbers
  m = 100000000; // Initialize minimum value to a large number
  M = -100000000; // Initialize maximum value to a small number
  
  // Read the number of elements
  std::cin >> n;

  // Loop through each element to read and process
  for(i = 1; i <= n; i++) {
    // Read the current number
    std::cin >> a;
    
    // Update maximum value if the current number is greater
    if(a > M) {
      M = a;
    } 
    
    // Update minimum value if the current number is smaller
    if(a < m) {
      m = a;
    }
    
    // Add the current number to the cumulative sum
    c = c + a;
  }
  
  // Print the minimum, maximum, and cumulative sum
  std::cout << m << " " << M << " " << c << std::endl;

  return 0; // Indicate successful completion of the program
}

