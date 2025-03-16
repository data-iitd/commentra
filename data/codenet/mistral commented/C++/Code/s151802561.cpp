#include<stdio.h>

int main(){
  int A[100]; // An array of integers with a maximum size of 100
  int n; // The number of elements in the array
  int i, j, t, sw = 0, mini; // Variables used in the sorting algorithm

  printf("Enter the number of elements: ");
  scanf("%d", &n); // Read the number of elements from the standard input

  printf("Enter %d integers:\n", n);
  for ( i = 0; i < n; i++ ) { // Read %d integers from the standard input and store them in the array A
    scanf("%d", &A[i]);
  }

  printf("Sorting the array using Selection Sort algorithm:\n");
  for ( i = 0; i < n; i++ ) { // The outer loop runs n times
    mini = i; // Initialize mini as i
    for ( j = i; j < n; j++ ) { // The inner loop finds the minimum element in the unsorted part of the array
      if ( A[j] < A[mini] ) { // If A[j] is smaller than A[mini], update mini
        mini = j;
      }
    }
    t = A[i]; // Swap A[i] with the minimum element
    A[i] = A[mini];
    A[mini] = t;

    if ( i != mini ) sw++; // Increment sw only if a swap is made
  }

  printf("Sorted array: ");
  for ( i = 0; i < n; i++ ) { // Print the sorted array to the standard output
    if (i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");

  printf("Number of swaps: %d\n", sw);

  return 0;
}