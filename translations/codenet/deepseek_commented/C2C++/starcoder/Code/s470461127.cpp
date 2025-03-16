#include <iostream>

using namespace std;

int main(void)
{
   int x, y;
   x = 0; y = 0;   

   // Read two integers from the standard input and store them in x and y
   cin >> x;		cin >> y;
   
   // Calculate the product of x and y
   // Also, calculate the perimeter of a rectangle with sides x and y
   cout << x * y << " " << (2*x) + (2*y) << endl;  

   return 0;
}

