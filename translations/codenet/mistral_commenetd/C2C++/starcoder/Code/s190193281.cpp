
#include<bits/stdc++.h>
using namespace std;

// Function to perform binary search on an array
int binarySearch(int arr[], int key, int low, int high)
{
  if(high >= low){ // If the array is not yet searched completely
    int mid = (low+high)/2; // Calculate the middle index
    if(arr[mid] == key) return 1; // If key is found, return 1
    else if(key < arr[mid]) return binarySearch(arr, key, low, mid-1); // If key is smaller, search in left half
    else return binarySearch(arr, key, mid+1, high); // If key is greater, search in right half
  }
  return 0; // If key is not present in the array, return 0
}

int main()
{
  int n,q,c=0; // Initialize variables

  // Read the size of the array
  cin>>n;

  // Allocate memory for the array
  int *S = new int[n];

  // Read the elements of the array
  cout<<"Enter "<<n<<" integers:\n";
  for(int i=0;i<n;i++){
    cout<<"Element "<<i+1<<": ";
    cin>>S[i];
  }

  // Read the number of queries
  cin>>q;

  // Allocate memory for the queries
  int *T = new int[q];

  // Read the queries
  cout<<"Enter "<<q<<" integers to be searched:\n";
  for(int i=0;i<q;i++){
    cout<<"Query "<<i+1<<": ";
    cin>>T[i];

    // Check if the query is present in the array
    if(binarySearch(S, T[i], 0, n-1)==1) c++;
  }

  // Print the number of queries present in the array
  cout<<"Number of queries present in the array: "<<c<<endl;

  // Free the allocated memory
  delete[] S;
  delete[] T;

  return 0;
}

