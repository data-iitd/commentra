#include<stdio.h> 
int main() 
{ 
      int a,b,x,w; // Declare variables to store input values and results
      while(scanf("%d %d",&a,&b)!=EOF) // Read two integers from standard input until end of file
      { 
         x=a+b; // Calculate the sum of the two integers
		 w=0; // Initialize the digit count to 0
         while(x) // Loop to count the number of digits in the sum
           { 
		      w++; // Increment the digit count
              x/=10; // Divide the sum by 10 to remove the last digit
           } 
         printf("%d\n",w); // Print the number of digits in the sum
      } 
      return 0; // Return 0 to indicate successful execution
} 


