
#include<stdio.h>
#include<stdlib.h>

int main(){
  // Declare variables
  int n;                       // Number of elements in the array
  int sq[10000];               // Square array to store squares of numbers from 1 to n-1
  int fr[5000];                // Frequency array to store the frequency of each difference between squares
  int *com;                    // Pointer to store unique squares
  int tmp;                     // Temporary variable
  int i,j;                     // Loop variables

  // Start of the infinite loop
  while(1){
    scanf("%d",&n);              // Read the number of elements in the array from the user
    if(!n)break;              // If the number is zero, break the loop

    // Allocate memory for the vector
    com = (int*)malloc(n*sizeof(int));

    // Initialize square array
    for(i=1;i<n;i++)sq[i] = (i*i)%n;
    for(i=0;i<n;i++)com[i] = 0; // Initialize the vector with zeros

    // Find unique squares and store them in the vector
    for(i=1;i<n;i++){
      for(j=0;j<n;j++){
	if(com[j]==sq[i]){       // If the square is already present, set the flag to false
	  break;
	}
      }
      if(j==n)com[j] = sq[i]; // If the square is not present, add it to the vector
    }

    // Initialize frequency array
    for(i=0;i<=(n-1)/2;i++)fr[i] = 0;

    // Find the frequency of each difference between unique squares
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	if(i!=j){                 // If the indices are not same
	  tmp = com[i]-com[j];    // Calculate the difference between two squares
	  if(tmp<0)tmp+=n;        // If the difference is negative, make it positive by adding n
	  if(tmp>(n-1)/2)tmp = n - tmp; // If the difference is greater than half the size of the array, make it smaller by subtracting the difference from the size of the array
	  fr[tmp]++;             // Increment the frequency of the difference
	}
      }
    }

    // Print the frequency of each difference
    for(i=1;i<=(n-1)/2;i++)printf("%d\n",fr[i]);

    // Free the memory allocated for the vector
    free(com);
  }
}
