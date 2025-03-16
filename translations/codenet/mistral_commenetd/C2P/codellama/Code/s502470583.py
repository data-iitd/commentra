
#include<stdio.h>

int main( ):
  a, b, c, d = 0, 0, 0, 0

  # Read two integers from the user and store them in variables a and b
  scanf("%d %d",&a,&b)

  # Multiply the two integers and store the result in variable c
  c = a * b

  # Multiply each integer with 2 and add them to get the value of d
  d = 2 * a + 2 * b

  # Print the values of c and d on the console
  printf("%d %d\n",c,d)

  # End of the main function and return 0 to indicate successful execution
  return 0

