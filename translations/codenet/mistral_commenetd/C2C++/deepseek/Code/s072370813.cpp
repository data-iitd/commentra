#include <iostream>
#include <vector>

int main() {
  // Declare variables
  int N;                  // Number of elements in the array
  int i;                 // Loop counter
  long long sum = 0;      // Sum of all elements in the array
  long long wa = 0;       // Sum of all indices from 1 to N
  std::vector<int> A;    // Array to store input elements
  std::vector<int> sa;    // Array to store differences between adjacent elements
  int ans;               // Answer flag
  int shou;              // Quotient of sum and wa

  // Read input
  std::cin >> N;
  // Read N integers into the array A
  A.resize(N);
  sa.resize(N);
  for( i = 0; i < N; i++ ){
    std::cin >> A[i];
    // Add current element to sum
    sum += A[i];
    // Add current index to wa
    wa += i+1;
  }

  // Check if sum is divisible by wa
  if( sum % wa ) ans = 0;
  else{
    // Calculate quotient of sum and wa
    shou = sum/wa;
    // Calculate differences between adjacent elements and store in array sa
    for( i = 0; i < N; i++ ){
      sa[i] = A[(i+1)%N] - A[i]-shou;
    }

    // Check if any difference is less than or equal to 0 and divisible by N
    for( i = 0; i < N-1; i++ ){
      if( sa[i] <= 0 && !(sa[i] % N))
        ans = 1;
      else{
        ans = 0;
        break;
      }
    }
  }

  // Print answer
  if( ans ) std::cout << "YES" << std::endl;
  else{
    std::cout << "NO" << std::endl;
  }

  return 0;
}
