#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Define macros for maximum and minimum values
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))

// Function to compare integers in descending order
int compare_int(const void *a, const void *b){
  return *(long int*)b - *(long int*)a; // 大きい順
}

// Function to calculate the greatest common divisor (GCD)
long int gcd(long int a, long int b){
  if(b == 0){
    return a;
  }else{
    return gcd(b, a % b);
  }
}

// Function to calculate the least common multiple (LCM)
long int lcm(long int a, long int b){
  return a * b / gcd(a, b);
}

// Main function
int main(void){
  long int n; // Number of players
  long long int k; // Initial points
  long int q; // Number of queries
  long int a[100001]; // Array to store query results
  long long int point[100001] = {0}; // Array to store points for each player

  // Read input values
  scanf("%ld%lld%ld", &n, &k, &q);

  // Process each query to update points
  for(long int i = 0; i < q; i++){
    scanf("%ld", &a[i]);
    point[a[i] - 1]++; // Update points for the player who answered the query
  }

  // Determine if each player can reach the required points
  for(long int i = 0; i < n; i++){
    if(k - (q - point[i]) > 0){
      printf("Yes\n"); // Player can reach the required points
    }else{
      printf("No\n"); // Player cannot reach the required points
    }
  }

  return 0;
}

