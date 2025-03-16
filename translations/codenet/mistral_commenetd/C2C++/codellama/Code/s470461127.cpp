#include <iostream>

int main()
{
   // Declare two integer variables x and y
   int x, y;
   x = 0; y = 0;   

   // Read two integers from the user using cin function and store them in variables x and y respectively
   std::cin >> x;		std::cin >> y;
   
   // Print the product of x and y and the sum of 2 times x and 2 times y using cout function
   std::cout << x * y << " " << (2*x) + (2*y) << std::endl;  

   // Return 0 to indicate successful execution of the program
   return 0;
}

