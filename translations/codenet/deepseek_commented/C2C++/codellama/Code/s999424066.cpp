#include<iostream>  // Step 1: Include the standard input/output library.
using namespace std;  // Step 2: Use the standard namespace.
int main(){  // Step 3: Define the main function.
  int a,b,c,x,y;  // Step 4: Declare integer variables a, b, c, x, y.
  cin>>a>>b>>c>>x>>y;  // Step 5: Read values for a, b, c, x, y from the user.
  c*=2;  // Step 6: Double the value of c.
  if(a+b<=c)  // Step 7: Check if the sum of a and b is less than or equal to c.
    cout<<a*x+b*y<<endl;  // Step 8: If true, print the product of a and x plus the product of b and y.
  else{  // Step 9: If false, start the else block.
    if(x<=y){  // Step 10: Check if x is less than or equal to y.
      if(b<=c)  // Step 11: Check if b is less than or equal to c.
        cout<<c*x+(y-x)*b<<endl;  // Step 12: If true, print the product of c and x plus the product of (y-x) and b.
      else  // Step 13: If false, start the else block.
        cout<<c*y<<endl;  // Step 14: Print the product of c and y.
    }
    else{  // Step 15: If x is greater than y, start the else block.
      if(a<=c)  // Step 16: Check if a is less than or equal to c.
        cout<<c*y+(x-y)*a<<endl;  // Step 17: If true, print the product of c and y plus the product of (x-y) and a.
      else  // Step 18: If false, start the else block.
        cout<<c*x<<endl;  // Step 19: Print the product of c and x.
    }
  }
  return 0;  // Step 20: End the main function and return 0.
}
