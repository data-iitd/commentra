#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &A, int key) {
  int left = 0; // Initialize the left boundary of the search range
  int right = A.size(); // Initialize the right boundary of the search range
  int mid; // Variable to hold the midpoint index during the search

  // Continue searching while the left boundary is less than the right boundary
  while(left < right) {
    mid = (left + right) / 2; // Calculate the midpoint index
    if(key == A[mid]) return 1; // If the key is found, return 1
    if(key > A[mid]) left = mid + 1; // If the key is greater, search in the right half
    else if(key < A[mid]) right = mid; // If the key is smaller, search in the left half
  }
  return 0; // If the key is not found, return 0
}

int main(void) {
  int n, q, k, sum = 0; // Declare variables for iteration, number of queries, the key to search, and a sum counter
  vector<int> A; // Declare an array A to hold up to 1,000,000 integers

  // Read the number of elements in the array
  cin >> n;
  
  // Read the elements into the array A
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    A.push_back(x);
  }

  // Read the number of queries
  cin >> q;
  
  // Process each query
  for(int i=0;i<q;i++) {
    cin >> k; // Read the key to search for
    if(binarySearch(A, k)) // Perform binary search for the key
      sum++; // Increment the sum if the key is found
  }

  // Output the total number of keys found in the array
  cout << sum << endl;
  return 0; // Return 0 to indicate successful execution
}

