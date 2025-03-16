#include<stdio.h>  # Step 1: Include the standard input/output library.
int main():  # Step 2: Define the main function.
  a,b,c,x,y = int(input()),int(input()),int(input()),int(input()),int(input())  # Step 3: Declare integer variables a, b, c, x, y.
  c*=2  # Step 4: Double the value of c.
  if a+b<=c:  # Step 5: Check if the sum of a and b is less than or equal to c.
    print(a*x+b*y)  # Step 6: If true, print the product of a and x plus the product of b and y.
  else:  # Step 7: If false, start the else block.
    if x<=y:  # Step 8: Check if x is less than or equal to y.
      if b<=c:  # Step 9: Check if b is less than or equal to c.
        print(c*x+(y-x)*b)  # Step 10: If true, print the product of c and x plus the product of (y-x) and b.
      else:  # Step 11: If false, start the else block.
        print(c*y)  # Step 12: Print the product of c and y.
    else:  # Step 13: If x is greater than y, start the else block.
      if a<=c:  # Step 14: Check if a is less than or equal to c.
        print(c*y+(x-y)*a)  # Step 15: If true, print the product of c and y plus the product of (x-y) and a.
      else:  # Step 16: If false, start the else block.
        print(c*x)  # Step 17: Print the product of c and x.
  return 0  # Step 18: End the main function and return 0.
