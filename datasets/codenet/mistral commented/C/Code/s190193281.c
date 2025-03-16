
#include<stdio.h>
#define N 1000000
#define Q 50000

int n,S[N],T[Q];

// Function to perform binary search on an array
int binarySearch(int key)
{
  int left = 0, right = n; // Initialize left and right pointers
  while(left < right){ // While the array is not yet searched completely
    mid = (left+right)/2; // Calculate the middle index
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
  printf("Enter the size of the array: ");
  scanf("%d",&n);

  // Allocate memory for the array
  S = (int*)malloc(n*sizeof(int));

  // Read the elements of the array
  printf("Enter %d integers:\n",n);
  for(i=0;i<n;i++){
    printf("Element %d: ",i+1);
    scanf("%d",&S[i]);
  }

  // Read the number of queries
  printf("Enter the number of queries: ");
  scanf("%d",&q);

  // Allocate memory for the queries
  T = (int*)malloc(q*sizeof(int));

  // Read the queries
  printf("Enter %d integers to be searched:\n",q);
  for(i=0;i<q;i++){
    printf("Query %d: ",i+1);
    scanf("%d",&T[i]);

    // Check if the query is present in the array
    if(binarySearch(T[i])==1) c++;
  }

  // Print the number of queries present in the array
  printf("Number of queries present in the array: %d\n",c);

  // Free the allocated memory
  free(S);
  free(T);

  return 0;
}