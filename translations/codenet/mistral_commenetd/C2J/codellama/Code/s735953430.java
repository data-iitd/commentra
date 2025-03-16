#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// The main function is the entry point of the program
int main() {
  // Declare variables
  int i_min, min; // i_min stores the index of the minimum number, min stores the minimum number
  int i, j, k; // i, j, k are loop variables
  int X, N; // X is the given number, N is the number of numbers to be subtracted

  // Read input values X and N from the user
  scanf("%d %d",&X,&N);

  // Check if N is zero, if yes, print X and exit the program
  if( N==0 ){
    printf("%d\n",X); 
    exit(0);
  }

  // Initialize two arrays plus and minus of size 256
  int plus[256];
  int minus[256];
  for(i=0;i<256;i++){
    // Initialize plus array with numbers from 0 to 255
    plus[i] = i;
    // Initialize minus array with negative numbers of plus array
    minus[i] = (-1*i);
  }

  // Subtract the given numbers from the plus array
  for(i=0;i<N;i++){
    scanf("%d",&j);
    // Set the corresponding index in the plus array to zero
    plus[j] = 0;
  }

  // Initialize variables i_min and min with initial values
  i_min=0;
  min = 1000;

  // Find the minimum number in the plus array that is not zero and can form the difference X
  for(i=255;i>=0;i--){
    // Skip the iteration if the current number in the plus array is zero and it is not the first element
    if( plus[i] == 0 && i>0 ){
      continue;
    }
    // Calculate the difference between X and the current number in the plus array
    k = X-plus[i];
    // If the difference is negative, make it positive
    if(k<0){ k *= -1; }
    // Update min and i_min if the current difference is smaller than the previous minimum
    if( k<=min ){
      min = k;
      i_min = i;
    }
  }

  // Print the index of the minimum number
  printf("%d\n",i_min);

  // Return 0 to indicate successful execution of the program
  return 0;
}

