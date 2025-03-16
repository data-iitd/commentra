
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  // Initialize input reader with a buffer size of 1,000,000 bytes
  string line;
  getline(cin, line);
  istringstream iss(line);
  int n;
  iss >> n;
  
  // Read the number of elements and the array of integers from input
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    getline(cin, line);
    istringstream iss(line);
    iss >> s[i];
  }
  
  // Create a boolean slice to track used indices
  vector<bool> u(n);
  
  // Initialize variables to store the maximum sum and a temporary sum
  long long m = 0, f = 0;
  
  // Iterate through possible values of c from 1 to n-2
  for (int c = 1; c < n-1; c++) {
    f = 0; // Reset the temporary sum for each c
    
    // Iterate to find pairs of indices based on the current value of c
    for (int k = 0; c < n-1-k*c; k++) {
      u[k*c] = true; // Mark the current index as used
      
      // Break if the corresponding index is already used
      if (u[n-1-k*c]) { break; }
      
      // Calculate the sum of the elements at the current indices
      f += s[n-1-k*c] + s[k*c];
      
      // Update the maximum sum if the current sum is greater
      if (m < f) { m = f; }
    }
    
    // Reset the used indices for the next iteration of c
    for (int k = 0; k*c < n-1; k++) { u[k*c] = false; }
  }
  
  // Print the maximum sum found
  cout << m << endl;
  
  return 0;
}

