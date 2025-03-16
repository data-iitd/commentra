#include <stdio.h>

int main(void)
{
   # Declare two integer variables x and y
   x, y = 0, 0

   # Read two integers from the user using scanf function and store them in variables x and y respectively
   scanf("%d", &x);		scanf("%d", &y);
   
   # Print the product of x and y and the sum of 2 times x and 2 times y using printf function
   printf("%d %d\n", x * y, (2*x) + (2*y));  

   # Return 0 to indicate successful execution of the program
   return 0;
}

