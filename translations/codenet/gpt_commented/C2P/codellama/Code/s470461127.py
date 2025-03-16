#include <stdio.h>

int main(void)
{
   # Declare two integer variables x and y
   x, y = 0, 0
   
   # Initialize x and y to 0
   x = 0; 
   y = 0;   

   # Read two integer values from the user and store them in x and y
   scanf("%d", &x);	
   scanf("%d", &y);
   
   # Calculate the product of x and y, and the perimeter of a rectangle with sides x and y
   # Print the product and the perimeter
   print(x * y, (2*x) + (2*y))
   print("