
#include<stdio.h>

int main(){
  int n; // Declare an integer variable 'n' to store the size of the array
  int array[100]; // Declare an integer array 'array' of size 100

  // Take the size of the array as input from the user
  scanf("%d",&n);

  // Initialize the array with user input
  for(int i=0;i<n;i++){
    scanf("%d",&array[i]); // Read an element from the user and store it in the array
  }

  int sum=0; // Initialize the sum variable to zero

  // Calculate the sum of all the products of distinct pairs of elements in the array
  for(int i=0;i<n-1;i++){ // Outer loop runs from 0 to n-2
    for(int j=i+1;j<n;j++){ // Inner loop runs from i+1 to n
      sum+=array[i]*array[j]; // Add the product of current and next element to the sum
    }
  }

  // Print the sum of all the products of distinct pairs of elements in the array
  printf("%d\n",sum);

  // Return 0 to indicate successful execution of the program
  return(0);
}

