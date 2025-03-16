#include <stdio.h>

int main(){
  // Declare an array to hold up to 100 integers and other necessary variables
  int A[100], n, i, j, t, sw = 0, mini;

  // Read the number of elements to be sorted
  scanf("%d", &n);
  
  // Read the elements into the array A
  for ( i = 0; i < n; i++ ) 
    scanf("%d", &A[i]);

  // Selection sort algorithm to sort the array A
  for ( i = 0; i < n; i++ ){
    mini = i; // Assume the minimum is the first element of the unsorted part
    // Find the index of the minimum element in the unsorted part
    for ( j = i; j < n; j++ ){
      if ( A[j] < A[mini] ) 
        mini = j; // Update mini if a smaller element is found
    }
    // Swap the found minimum element with the first element of the unsorted part
    t = A[i]; 
    A[i] = A[mini]; 
    A[mini] = t;

    // Count the number of swaps made
    if ( i != mini ) 
      sw++;
  }

  // Print the sorted array
  for ( i = 0; i < n; i++ ){
    if (i) 
      printf(" "); // Print a space before each element except the first
    printf("%d", A[i]); // Print the current element
  }
  printf("\n"); // Print a newline after the array

  // Print the total number of swaps made during sorting
  printf("%d\n", sw);

  return 0; // End of the program
}
