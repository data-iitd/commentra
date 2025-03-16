
#include <iostream>

int main()
{
   // Declare two integer variables x and y
   int x, y;
   
   // Initialize x and y to 0
   x = 0; 
   y = 0;   

   // Read two integer values from the user and store them in x and y
   std::cin >> x;	
   std::cin >> y;
   
   // Calculate the product of x and y, and the perimeter of a rectangle with sides x and y
   // Print the product and the perimeter
   std::cout << x * y << " " << (2*x) + (2*y) << std::endl;  

    // Return 0 to indicate successful completion of the program
    return 0;
}
