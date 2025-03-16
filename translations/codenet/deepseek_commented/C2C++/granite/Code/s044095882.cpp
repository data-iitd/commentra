
#include <iostream>  // Include the standard input-output library

int main(void)  // Define the main function, the entry point of the program
{
  long int n;  // Declare a variable to store the number of elements

  std::cin >> n;  // Read the value of n from the standard input
  long int a[n];  // Declare an array `a` with size n
  long int count[n];  // Declare an array `count` with size n

  for (long int i = 1; i < n; i++)  // Loop to read n-1 values into the array `a`
    std::cin >> a[i];

  for (long int i = 0; i < n; i++)  // Loop to initialize the `count` array to zero
    count[i] = 0;

  for (long int i = 1; i < n; i++)  // Loop to increment the `count` array based on the values in `a`
    count[a[i]-1]++;

  for (long int i = 0; i < n; i++)  // Loop to print the values in the `count` array
    std::cout << count[i] << std::endl;

  return 0;  // Return 0 to indicate successful execution
}
