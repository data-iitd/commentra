
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

// Main function starts here
int main(){
  int N; // Number of elements in the vector

  // Taking input of N from the user
  scanf("%d",&N);

  // Declaring two vectors X and Y of size N
  int X[N],Y[N];

  // Filling the vectors X and Y with user input
  for(int i = 0; i < N; i++){
    scanf("%d",&X[i]); // Taking input of X[i] from the user
    Y[i] = X[i]; // Assigning X[i] to Y[i]
  }

  // Sorting the vector Y in ascending order
  qsort(Y,N,sizeof(int),compare);

  // Finding the middle element of sorted vector Y
  int y = Y[N/2];

  // Iterating through the vector X and printing the middle element of Y based on the condition
  for(int i = 0; i < N; i++){
    if( X[i] < Y[N/2]){ // Checking if X[i] is less than the middle element of Y
      printf("%d",Y[N/2]); // If true, print the middle element of Y
    }
    else{ // If X[i] is greater than or equal to the middle element of Y
      printf("%d",Y[N/2 - 1]); // Print the middle element of Y - 1
      break; // Exit the loop as we have found the required element
    }
    printf("\n"); // Print a newline after each element
  }

  // End of main function
  return 0;
}

