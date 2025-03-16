
#include<stdio.h> // Include standard input/output library

int main(void){ // Beginning of main function

 int a, b, n; // Declare and initialize three integer variables

 printf("Enter two integers: "); // Prompt user to enter two integers
 scanf("%d %d",&a,&b); // Read two integers from standard input and store in variables a and b

 n=(a+b)/2; // Calculate the average of a and b and store the result in variable n

 printf("The average of %d and %d is: %d\n",a,b,n); // Display the average on standard output

 return 0; // Program has executed successfully, return integer value 0 to operating system
}