#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<math.h>

#include<stdbool.h>

#include<ctype.h>

#include<limits.h>

#include<float.h>

#include<time.h>

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<math.h>

#include<stdbool.h>

#include<ctype.h>

#include<limits.h>

#include<float.h>

#include<time.h>

int main(void)
{
  int a, b; // Declare two integer variables 'a' and 'b'
  // Initialize them to zero by default

  scanf("%d",&a); // Read an integer value from the standard input and store it in variable 'a'
  scanf("%d",&b); // Read an integer value from the standard input and store it in variable 'b'

  if((a*b)%2 == 0){ // Check if the product of 'a' and 'b' is even
    printf("Even\n"); // If it is even, print "Even" to the standard output
  }else{
    printf("Odd\n"); // If it is odd, print "Odd" to the standard output
  }

  return 0; // Indicate successful termination of the program
}

