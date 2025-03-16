#include<stdio.h> 
// This line includes the standard input/output library

int main() 
{ 
      int a, b, x, w; 
      // Declare four integer variables: a, b, x, and w

      while(scanf("%d %d",&a,&b)!=EOF) 
      { 
         x=a+b;
		 // Add this comment to explain the assignment of the sum of a and b to x

		 w=0; 
         // Initialize w to zero

         while(x) 
           { 
		      w++; 
              // Increment w each time through the loop
              x/=10; 
              // Divide x by 10 to get the next digit
           } 
         printf("%d\n",w); 
         // Print the value of w, which represents the number of digits in the sum of a and b

      } 
      // This while loop continues to read input until the end of the file is reached

      return 0; 
} 
// The main function returns 0 to indicate successful execution

