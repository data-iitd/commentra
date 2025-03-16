
#include<stdio.h>
#include<stdlib.h>

int main(){
  int n;
  int *sq, *fr; // Declare arrays to store squares and frequencies
  int *com; // Declare array to store unique squares
  int tmp; // Temporary variable for calculations
  int i, j; // Loop variables

  while(1){
    scanf("%d", &n); // Read input integer n
    if(!n) break; // Break the loop if n is 0

    sq = (int*)malloc(n*sizeof(int)); // Allocate memory for sq array
    fr = (int*)malloc((n-1)/2*sizeof(int)); // Allocate memory for fr array
    com = (int*)malloc(n*sizeof(int)); // Allocate memory for com array

    for(i=1; i<n; i++) sq[i] = (i*i) % n; // Calculate squares modulo n
    for(i=0; i<=(n-1)/2; i++) fr[i] = 0; // Initialize frequency array

    int com_size = 0; // Initialize size of com array
    for(i=1; i<n; i++){ // Find unique squares modulo n
      bool f = true; // Flag to check if the square is unique
      for(j=0; j<com_size; j++){
	if(com[j] == sq[i]){ // Check if the square is already in com
	  f = false; // Set flag to false if not unique
	  break; // Break the loop if not unique
	}
      }
      if(f){ // Add unique square to com if flag is true
	com[com_size] = sq[i];
	com_size++;
      }
    }

    for(i=0; i<com_size; i++){ // Calculate differences between unique squares
      for(j=0; j<com_size; j++){
	if(i!= j){ // Avoid comparing a square with itself
	  tmp = com[i] - com[j]; // Calculate difference
	  if(tmp < 0) tmp += n; // Adjust if tmp is negative
	  if(tmp > (n-1)/2) tmp = n - tmp; // Adjust if tmp is greater than half of n
	  fr[tmp]++; // Increment the count for the difference
	}
      }
    }

    for(i=1; i<=(n-1)/2; i++) printf("%d\n", fr[i]); // Output the frequencies

    free(sq); // Free memory for sq array
    free(fr); // Free memory for fr array
    free(com); // Free memory for com array
  }
}
