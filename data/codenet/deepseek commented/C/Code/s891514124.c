#include <stdio.h>  // Include the standard input-output library

int main(void){  // Define the main function, which returns an integer

  int S;  // Declare an integer variable S
  scanf("%d", &S);  // Read an integer input from the user and store it in S

  // Check if S is less than 60
  if (S < 60)
    {
      printf("0:0:%d\n", S);  // Print "0:0:S" if S is less than 60
    }
  
  // Check if S is less than 3600
  else if (S < 3600)
    {
      printf("0:%d:%d\n", (int)S / 60, S % 60);  // Print "0:S/60:S%60" if S is less than 3600
    }
  
  // If S is not less than 3600
  else
    {
      printf("%d:%d:%d\n", (int)S / 3600, (int)(S % 3600) / 60, (S % 60) % 60);  // Print "S/3600:S%3600/60:S%60" if S is not less than 3600
    }
  return 0;  // Return 0 to indicate successful execution
}
