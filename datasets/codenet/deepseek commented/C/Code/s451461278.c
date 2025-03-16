#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

// Partition function used in Quicksort algorithm
int Partition(char [], int [], int, int);

// Quicksort function to sort the array
void Quicksort(char [], int [], int, int);

// Merge function used in Merge Sort algorithm
void Merge(char [], int [],int,int,int);

// Merge Sort function to sort the array using recursion
void Merge_Sort(char [], int [],int,int);

// Variable to store the pivot index in Partition function
int q;

// Main function to read input, sort data using both algorithms, and check stability
int main(void){

  // Arrays to store characters and their corresponding numbers
  int A[MAX + 1];
  char C[MAX + 1];
  char MC[MAX + 1];
  int MN[MAX + 1];

  // Variables to store the number of elements and loop index
  int i, p, n;
  int count = 0;

  // Read the number of elements
  scanf("%d",&n);

  // Read characters and their corresponding numbers
  for(i=1;i<=n;i++)
    scanf(" %c %d",&C[i], &A[i]);

  // Copy characters and numbers to another array for Merge Sort
  for(i=1;i<=n;i++){
    MC[i] = C[i];
    MN[i] = A[i];
  }

  // Sort the copied array using Merge Sort
  Merge_Sort(MC,MN,1,n);

  // Sort the original array using Quicksort
  p = 1;
  Quicksort(C, A, p, n);

  // Check if the sorting results are stable
  for(i = 1; i <= n;i++){
    if(MN[i] == A[i] && MC[i] == C[i])
      count++;
  }

  // Print the stability result
  if(count == n)
    printf("Stable\n");
  else
    printf("Not stable\n");

  // Print the sorted characters and their corresponding numbers
  for(i=1;i<=n;i++)
    printf("%c %d\n",C[i], A[i]);

  return 0;
}

// Partition function to find the pivot index and rearrange elements
int Partition(char C[], int A[], int p, int r){

  // Variables to store temporary values during partition
  int i, j;
  char tmpC,x;
  int  tmpN, y;

  // Choose the last element as pivot
  x = C[r];
  y = A[r];
  i = p - 1;

  // Rearrange elements in the array
  for(j = p;j<r;j++){
    if(A[j] <= y){
      i = i + 1;
      tmpN = A[j];
      tmpC = C[j];
      A[j] = A[i];
      C[j] = C[i];
      A[i] = tmpN;
      C[i] = tmpC;
    }
  }
  
  // Place the pivot element in its correct position
  tmpN = A[i+1];
  tmpC = C[i + 1];
  A[i+1] = A[r];
  C[i+1] = C[r];
  A[r] = tmpN;
  C[r] = tmpC;

  return i+1;
}

// Quicksort function to sort the array recursively
void Quicksort(char C[], int A[], int p, int r){

  // Base case: if the subarray has more than one element
  if(p < r){
    q = Partition(C, A, p, r);
    Quicksort(C, A, p, q-1);
    Quicksort(C, A, q+1, r);
    }
}

// Merge function to merge two sorted subarrays
void Merge(char MC[], int MN[],int left,int mid,int right){

    // Calculate sizes of two subarrays to be merged
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int LN[n1 + 1];
    int RN[n2 + 1];
    int LC[n1 + 1];
    int RC[n2 + 1];
    
    // Copy data to temp arrays
    int i,j,k;
    
    for(i = 1;i <= n1;i++){
      LN[i] = MN[left + i - 1];
      LC[i] = MC[left + i - 1];
    }
    
    for(i = 1;i <= n2;i++){
      RN[i] = MN[mid + i];
      RC[i] = MC[mid + i];
    }
    
    // Sentinel values to avoid checking if any subarray is empty
    LN[n1+1] = 1000000000;
    RN[n2+1] = 1000000000;
    
    // Initial indexes for subarrays
    i = 1;
    j = 1;
    
    // Merge the temp arrays back into arr[left..right]
    for(k = left;k <= right;k++){
      if(LN[i] <= RN[j]){
	MN[k] = LN[i];
	MC[k] = LC[i++];
      }
      else{
	MN[k] = RN[j];
	MC[k] = RC[j++];
      }
    }
}

// Merge Sort function to sort the array using recursion
void Merge_Sort(char MC[], int MN[],int left,int right){
    int mid;

    // Base case: if the subarray has more than one element
    if(left < right){
        mid = (left + right)/2;
        Merge_Sort(MC,MN,left,mid);
        Merge_Sort(MC,MN,mid+1,right);
        Merge(MC,MN,left,mid,right);
    }
}