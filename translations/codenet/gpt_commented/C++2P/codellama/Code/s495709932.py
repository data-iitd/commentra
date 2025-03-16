#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  // Optimize input/output operations
  ios::sync_with_stdio(false);
  
  // Read the number of elements in the array
  int N;
  cin >> N;
  
  // Initialize a vector to store the elements
  vector<int64_t> A(N);
  
  // Read the elements into the vector
  rep(i, N) cin >> A[i];

  // Initialize a variable to keep track of the maximum difference
  int64_t answer = 0;
  
  // Iterate through all pairs of elements to find the maximum difference
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      // Calculate the absolute difference between the two elements
      int64_t diff = abs(A[i] - A[j]);
      
      // Update the maximum difference found so far
      answer = max(answer, diff);
    }
  }
  
  // Output the maximum difference
  cout << answer << endl;
  
  return 0;
}

