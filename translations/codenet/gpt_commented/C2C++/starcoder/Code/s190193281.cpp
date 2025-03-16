#include<bits/stdc++.h>
using namespace std;

// Function to perform binary search on the sorted array S
int binarySearch(int key, int S[], int n)
{
  int left = 0, right = n, mid;  // Initialize left and right pointers for the search range
  while(left < right) {  // Continue searching while the range is valid
    mid = (left + right) / 2;  // Calculate the middle index
    if(S[mid] == key) return 1;  // If the key is found, return 1
    else if(key < S[mid]) right = mid;  // Narrow the search to the left half
    else left = mid + 1;  // Narrow the search to the right half
  }
  return 0;  // If the key is not found, return 0
}

int main()
{
  int n, q, c = 0;  // Declare variables: n for the number of elements, q for the number of queries, c for count of found keys
  cin >> n;  // Read the number of elements in the sorted array S
  int S[n];  // Declare an array S to store the sorted elements
  for(int i = 0; i < n; i++) cin >> S[i];  // Read the elements into the sorted array S
  cin >> q;  // Read the number of queries
  int T[q];  // Declare an array T to store the queries
  for(int i = 0; i < q; i++) cin >> T[i];  // Read the queries into array T
  for(int i = 0; i < q; i++) {  // Process each query to check if it exists in the sorted array S
    if(binarySearch(T[i], S, n) == 1) c++;  // If the element is found, increment the count
  }
  cout << c << endl;  // Output the total count of found elements
  return 0;  // Return 0 to indicate successful completion
}

