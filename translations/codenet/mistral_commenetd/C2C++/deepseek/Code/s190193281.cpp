#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define N 1000000
#define Q 50000

int n, S[N], T[Q];

// Function to perform binary search on an array
int binarySearch(int key)
{
  int left = 0, right = n; // Initialize left and right pointers
  while(left < right){ // While the array is not yet searched completely
    int mid = (left+right)/2; // Calculate the middle index
    if(S[mid] == key) return 1; // If key is found, return 1
    else if(key < S[mid]) right = mid; // If key is smaller, search in left half
    else left = mid+1; // If key is greater, search in right half
  }
  return 0; // If key is not present in the array, return 0
}

int main()
{
  int i,j,q,c=0; // Initialize variables

  // Read the size of the array
  cout << "Enter the size of the array: ";
  cin >> n;

  // Read the elements of the array
  cout << "Enter " << n << " integers:\n";
  for(i=0;i<n;i++){
    cout << "Element " << i+1 << ": ";
    cin >> S[i];
  }

  // Read the number of queries
  cout << "Enter the number of queries: ";
  cin >> q;

  // Read the queries
  cout << "Enter " << q << " integers to be searched:\n";
  for(i=0;i<q;i++){
    cout << "Query " << i+1 << ": ";
    cin >> T[i];

    // Check if the query is present in the array
    if(binarySearch(T[i])==1) c++;
  }

  // Print the number of queries present in the array
  cout << "Number of queries present in the array: " << c << endl;

  return 0;
}
