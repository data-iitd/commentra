#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

// Macro definitions for maximum and minimum
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))

// Comparison function for qsort to sort integers in descending order
int compare_int(const void *a, const void *b){
  return *(long int*)b - *(long int*)a; // Sort in descending order
}

// Function to calculate the greatest common divisor (GCD) using recursion
long int gcd(long int a, long int b){
  if(b == 0){
    return a; // Base case: if b is 0, return a
  }else{
    return gcd(b, a % b); // Recursive case
  }
}

// Function to calculate the least common multiple (LCM) using GCD
long int lcm(long int a, long int b){
  return a * b / gcd(a, b); // LCM formula
}

// Main function
int main(void){
  long int n; // Number of participants
  long long int k; // Points required to win
  long int q; // Number of questions
  long int a[100001]; // Array to store the questions
  long long int point[100001] = {0}; // Array to track points of each participant

  // Read input values for n, k, and q
  scanf("%ld%lld%ld", &n, &k, &q);

  /*
  // Initialize points for each participant to k (commented out)
  for(long int i = 0; i < n; i++){
    point[i] = k;
  }
  */
  
  /*
  // Check if any participant has less points than k (commented out)
  if(q < k){
    for(long int i = 0; i < n; i++){
      printf("Yes\n");
      return 0;
    }
  }
  */
  
  // Process each question and update points for the corresponding participant
  for(long int i = 0; i < q; i++){
    scanf("%ld", &a[i]); // Read the participant number for the question
    point[a[i] - 1]++; // Increment the point for the participant who answered
    /*
    // Update points for other participants (commented out)
    for(long int j = 0; j < n; j++){
      if(a[i] != (j + 1) && point[j] < k){
        point[j]++;
      }
      // printf("i = %ld  point = %lld\n", i, point[j]);
    }
    */
  }

  // Determine if each participant has enough points to win
  for(long int i = 0; i < n; i++){
    if(k - (q - point[i]) > 0){ // Check if the participant has enough points
      printf("Yes\n"); // Participant can win
    }else{
      printf("No\n"); // Participant cannot win
    }
  }

  return 0; // End of the program
}

