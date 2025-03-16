#include<stdio.h>

int main(void) {
  
  // Declare an integer variable 'x' to store user input
  int x;
  
  // Prompt the user for input and read an integer value into 'x'
  scanf("%d", &x);
  
  // Check if the input value is 0
  if (x == 0) 
    // If true, print "1" to the output
    printf("1\n");
  
  // Check if the input value is 1
  if (x == 1) 
    // If true, print "0" to the output
    printf("0\n");
  
  // Return 0 to indicate successful completion of the program
  return 0;
  
}
