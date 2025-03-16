#include<iostream>
#define N 1000000  // Maximum size for the array S
#define Q 50000    // Maximum size for the array T

using namespace std;  // Declare the standard namespace

int n, S[N], T[Q];  // Declare variables: n for the number of elements, S for the sorted array, T for the query array

// Function to perform binary search on the sorted array S
int binarySearch(int key)
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
  int i, j, q, c = 0;  // Declare variables: i for loops, q for number of queries, c for count of found keys
  
  // Read the number of elements in the sorted array S
  cin >> n;
  
  // Read the elements into the sorted array S
  for(i = 0; i < n; i++) {
    cin >> S[i];
  }
  
  // Read the number of queries
  cin >> q;
  
  // Process each query to check if it exists in the sorted array S
  for(i = 0; i < q; i++) {
    cin >> T[i];  // Read the query element into array T
    if(binarySearch(T[i]) == 1) c++;  // If the element is found, increment the count
  }
   
  // Output the total count of found elements
  cout << c << endl;
  
  return 0;  // Return 0 to indicate successful completion
}

