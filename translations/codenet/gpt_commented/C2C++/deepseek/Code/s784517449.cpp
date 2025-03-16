#include <iostream>
using namespace std;

const int MAX = 1000000; // Declare a constant for the maximum number of elements
int A[MAX], n; // Declare an array A to hold up to 1,000,000 integers and a variable n for the number of elements

/* 二分探索 (Binary Search) */
int binarySearch(int key) {
  int left = 0; // Initialize the left boundary of the search range
  int right = n; // Initialize the right boundary of the search range
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
  int i, q, k, sum = 0; // Declare variables for iteration, number of queries, the key to search, and a sum counter

  // Read the number of elements in the array
  cin >> n;
  
  // Read the elements into the array A
  for(i=0; i<n; i++) {
    cin >> A[i];
  }

  // Read the number of queries
  cin >> q;
  
  // Process each query
  for(i=0;i<q;i++) {
    cin >> k; // Read the key to search for
    if(binarySearch(k)) // Perform binary search for the key
      sum++; // Increment the sum if the key is found
  }

  // Output the total number of keys found in the array
  cout << sum << endl;
  return 0; // Return 0 to indicate successful execution
}

