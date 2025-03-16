
#include <iostream>

int main() {
  
  // Declare variable N to hold the number of elements
  int N;
  // Read the number of elements from user input
  std::cin >> N;
  
  // Declare variables for iteration, sum, weighted sum, and arrays
  int i;
  long long sum = 0; // To store the total sum of elements
  long long wa = 0;  // To store the weighted sum (1 + 2 +... + N)
  int A[N];          // Array to hold the input elements
  int sa[N];         // Array to hold the adjusted differences
  int ans;           // Variable to store the final answer (0 or 1)
  int shou;          // Variable to store the average value
  long long min = 1123456789; // A large number for comparison (not used in this code)
  
  // Read the elements into array A and calculate the total sum and weighted sum
  for (i = 0; i < N; i++) {
    std::cin >> A[i]; // Read each element into the array A
    sum += A[i];        // Accumulate the sum of elements
    wa += i + 1;       // Accumulate the weighted sum
  }
  
  // Check if the total sum is divisible by the weighted sum
  if (sum % wa) {
    ans = 0; // If not divisible, set answer to 0 (NO)
  } else {
    // Calculate the average value (shou)
    shou = sum / wa;
    
    // Calculate the adjusted differences and store them in array sa
    for (i = 0; i < N; i++) {
      sa[i] = A[(i + 1) % N] - A[i] - shou; // Adjusted difference for circular array
    }
    
    // Check the conditions for the adjusted differences
    for (i = 0; i < N - 1; i++) {    
      // If the adjusted difference is non-positive and divisible by N
      if (sa[i] <= 0 &&!(sa[i] % N)) {
        ans = 1; // Set answer to 1 (YES)
      } else {
        ans = 0; // If any condition fails, set answer to 0 (NO)
        break;   // Exit the loop early
      }
    }
  }  
  
  // Output the final result based on the answer
  if (ans) {
    std::cout << "YES" << std::endl; // Print YES if conditions are met
  } else {
    std::cout << "NO" << std::endl;  // Print NO if conditions are not met
  }
  
  return 0; // Return success
}

