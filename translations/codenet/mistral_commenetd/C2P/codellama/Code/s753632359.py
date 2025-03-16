
#include<stdio.h>

# Declare variables N and D of integer type
# N and D should be positive integers less than or equal to 20
int main(void):
   N, D = input("Enter two positive integers less than or equal to 20: ").split()

   # Initialize variables N and D using scanf function
   N, D = int(N), int(D)

   # Calculate the quotient of N by (D*2+1) and store it in variable ans
   ans = N // (D*2+1)

   # Calculate the remainder of N by (D*2+1) and store it in variable rem
   rem = N % (D*2+1)

   # Check if the remainder is zero or not
   if(rem != 0):
       # If the remainder is not zero, increment the value of ans by 1
       ans = ans + 1

   # Print the value of ans using printf function
   print(ans)

   # Return 0 to indicate successful execution of the program
   return 0

