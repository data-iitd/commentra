#include<stdio.h> // Including the standard input/output library

int main(void){ // The main function is the starting point of the program
  
  int x; // Declaring an integer variable named x

  scanf("%d",&x); // Reading an integer value from the standard input and storing it in the variable x

  if(x==0)printf("1\n"); // If the value of x is 0, then print the value 1 followed by a newline character
  if(x==1)printf("0\n"); // If the value of x is 1, then print the value 0 followed by a newline character

  return 0; // The program has finished executing successfully, so return 0 to the operating system
}

