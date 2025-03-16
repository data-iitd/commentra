
#include<stdio.h>
#include<stdlib.h>

int main(){
  int n; // Variable to store the input number
  int sq[10000], fr[5000]; // Arrays to store squares and frequency counts
  int *com; // Pointer to dynamically allocate memory for unique square values
  int tmp; // Temporary variable for calculations

  // Infinite loop to continuously read input until a zero is entered
  while(1){
    scanf("%d", &n); // Read an integer from input
    if(!n) break; // Exit the loop if the input is zero

    // Allocate memory for 'com' based on the size of'sq'
    com = (int*)malloc(n*sizeof(int));

    // Calculate the squares of numbers from 1 to n-1 modulo n
    for(int i=1; i<n; i++) sq[i] = (i*i) % n;
    int com_size = 0; // Variable to store the size of 'com'

    // Collect unique square values into the dynamically allocated memory 'com'
    for(int i=1; i<n; i++){
      bool f = true; // Flag to check if the square is unique
      for(int j=0; j<com_size; j++){
        if(com[j] == sq[i]){ // Check if the square is already in 'com'
          f = false; // Not unique
          break;
        }
      }
      if(f){
        com[com_size] = sq[i]; // Add to 'com' if unique
        com_size++; // Increment the size of 'com'
      }
    }
 
    // Initialize frequency array to count occurrences of differences
    for(int i=0; i<=(n-1)/2; i++) fr[i] = 0;

    // Calculate the frequency of differences between unique squares
    for(int i=0; i<com_size; i++){
      for(int j=0; j<com_size; j++){
        if(i!= j){ // Ensure we are not comparing the same element
          tmp = com[i] - com[j]; // Calculate the difference
          if(tmp < 0) tmp += n; // Adjust if negative
          if(tmp > (n-1)/2) tmp = n - tmp; // Adjust to be within the range
          fr[tmp]++; // Increment the frequency count for this difference
        }
      }
    }

    // Output the frequency counts for differences from 1 to (n-1)/2
    for(int i=1; i<=(n-1)/2; i++) printf("%d\n", fr[i]);

    // Free the dynamically allocated memory for 'com'
    free(com);
  }
}
