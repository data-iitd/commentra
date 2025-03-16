#include<stdio.h>  // Include the input-output stream library for standard input and output operations.
#include<stdlib.h> // Include the standard library for using the malloc function.
#include<string.h> // Include the string library for using the strcpy function.

int main(){
  int N; scanf("%d", &N); // Read the number of elements N from the standard input.
  int *X = (int *) malloc(N * sizeof(int)); // Allocate memory for vector X of size N.
  int *Y = (int *) malloc(N * sizeof(int)); // Allocate memory for vector Y of size N.
  
  // Read N elements into vector X and simultaneously copy them to vector Y.
  for(int i = 0; i < N; i++){
    scanf("%d", &X[i]);
    Y[i] = X[i];
  }
  
  // Sort the vector Y in ascending order.
  qsort(Y, N, sizeof(int), compare);
  
  // Calculate the median of the sorted vector Y. The median is the middle element for odd N, and the average of the two middle elements for even N.
  int y = Y[N/2];
  
  // Iterate through each element in vector X and output the appropriate median value based on the comparison with y.
  for(int i = 0; i < N; i++){
    if(X[i] < y){
      printf("%d", y); // If the element in X is less than the median, output the median.
    } else {
      printf("%d", y - 1); // Otherwise, output the median minus one.
    }
    printf("\n"); // Output a newline after each result.
  }
  
  return 0; // Return 0 to indicate successful execution.
}

