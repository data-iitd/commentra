#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  int n;
  int sq[10000], fr[5000]; // Declare arrays to store squares and frequencies
  int com[10000]; // Declare array to store unique squares
  int tmp; // Temporary variable for calculations

  while(1){
    scanf("%d", &n); // Read input integer n
    if(!n) break; // Break the loop if n is 0

    for(int i=1; i<n; i++) sq[i] = (i*i) % n; // Calculate squares modulo n
    int com_size = 0; // Initialize the size of com

    for(int i=1; i<n; i++){ // Find unique squares modulo n
      bool f = true; // Flag to check if the square is unique
      for(int j=0; j<com_size; j++){
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

    for(int i=0; i<=(n-1)/2; i++) fr[i] = 0; // Initialize frequency array

    for(int i=0; i<com_size; i++){ // Calculate differences between unique squares
      for(int j=0; j<com_size; j++){
	if(i!= j){ // Avoid comparing a square with itself
	  tmp = com[i] - com[j]; // Calculate difference
	  if(tmp < 0) tmp += n; // Adjust if tmp is negative
	  if(tmp > (n-1)/2) tmp = n - tmp; // Adjust if tmp is greater than half of n
	  fr[tmp]++; // Increment the count for the difference
	}
      }
    }

    for(int i=1; i<=(n-1)/2; i++) printf("%d\n", fr[i]); // Output the frequencies
  }
}
