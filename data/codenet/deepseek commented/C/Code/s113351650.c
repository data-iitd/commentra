#include<stdio.h>
int main(void){
  
  // Declare an integer variable to store the input value.
  int x;
  
  // Read an integer input from the user and store it in the variable x.
  scanf("%d", &x);
  
  // Check the value of x and print 1 or 0 based on the value of x.
  if (x == 0) {
    printf("1\n");
  }
  if (x == 1) {
    printf("0\n");
  }
  
  // Return 0 to indicate successful execution of the program.
  return 0;
}
