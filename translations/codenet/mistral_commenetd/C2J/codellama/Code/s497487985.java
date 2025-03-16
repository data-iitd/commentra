#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))

// Function to compare two integers in descending order
int compare_int(const void *a, const void *b){
  return *(long int*)b - *(long int*)a; // 大きい順
}

// Function to find the greatest common divisor (GCD) of two integers
long int gcd(long int a, long int b){
  if(b == 0){
    // If 'b' is 0, then 'a' is the GCD
    return a;
  }else{
    // Otherwise, recursively call the function with 'b' and the remainder of 'a' divided by 'b'
    return gcd(b, a % b);
  }
}

// Function to find the least common multiple (LCM) of two integers
long int lcm(long int a, long int b){
  // The LCM is the product of the two numbers divided by their GCD
  return a * b / gcd(a, b);
}

// Main function
int main(void){
  long int n; // Number of people
  long long int k; // Total points
  long int q; // Number of queries
  long int a[100001]; // Array to store the query numbers
  long long int point[100001] = {0}; // Array to store the current points for each person

  // Read input values
  scanf("%ld%lld%ld", &n, &k, &q);

  /*
  // Initialize the points for all people to 'k'
  for(long int i = 0; i < n; i++){
    point[i] = k;
  }
  */

  // Check if it's possible to distribute the points to all queries
  if(q < k){
    // If the total number of queries is less than the total points, then it's impossible to distribute the points to all queries
    for(long int i = 0; i < n; i++){
      printf("Yes\n"); // This will never be reached
      return 0;
    }
  }

  // Distribute the points to each query one by one
  for(long int i = 0; i < q; i++){
    scanf("%ld", &a[i]); // Read the query number
    point[a[i] - 1]++; // Increase the points for the person with the query number

    /*
    // Try to distribute the points to other people if the current person doesn't get the point
    for(long int j = 0; j < n; j++){
      if(a[i] != (j + 1) && point[j] < k){ // If the current person's number is different from 'j + 1' and the points for person 'j' are less than 'k'
	point[j]++; // Increase the points for person 'j'
      }
    }
    */
  }

  // Check if it's possible to distribute the remaining points to the remaining people
  for(long int i = 0; i < n; i++){
    if(k - (q - point[i]) > 0){ // If the remaining points are greater than the difference between the total points and the points already distributed
      printf("Yes\n"); // It's possible to distribute the remaining points to the remaining people
    }else{
      printf("No\n"); // It's impossible to distribute the remaining points to the remaining people
    }
  }

  return 0;
}

