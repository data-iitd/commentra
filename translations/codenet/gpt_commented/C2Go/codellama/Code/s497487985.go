#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Macro definitions for maximum and minimum
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))

// Comparison function for qsort to sort integers in descending order
func compare_int(a, b unsafe.Pointer) int {
  return *(*int64)(b) - *(*int64)(a) // Sort in descending order
}

// Function to calculate the greatest common divisor (GCD) using recursion
func gcd(a, b int64) int64 {
  if(b == 0){
    return a // Base case: if b is 0, return a
  }else{
    return gcd(b, a % b) // Recursive case
  }
}

// Function to calculate the least common multiple (LCM) using GCD
func lcm(a, b int64) int64 {
  return a * b / gcd(a, b) // LCM formula
}

// Main function
func main() {
  var n int64 // Number of participants
  var k int64 // Points required to win
  var q int64 // Number of questions
  var a [100001]int64 // Array to store the questions
  var point [100001]int64 = [100001]int64{0} // Array to track points of each participant

  // Read input values for n, k, and q
  fmt.Scanf("%d%d%d", &n, &k, &q)

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
      fmt.Println("Yes")
      return
    }
  }
  */
  
  // Process each question and update points for the corresponding participant
  for(var i = 0; i < q; i++){
    fmt.Scanf("%d", &a[i]) // Read the participant number for the question
    point[a[i] - 1]++ // Increment the point for the participant who answered
    /*
    // Update points for other participants (commented out)
    for(long int j = 0; j < n; j++){
      if(a[i] != (j + 1) && point[j] < k){
        point[j]++;
      }
      // fmt.Printf("i = %d  point = %d\n", i, point[j])
    }
    */
  }

  // Determine if each participant has enough points to win
  for(var i = 0; i < n; i++){
    if(k - (q - point[i]) > 0){ // Check if the participant has enough points
      fmt.Println("Yes") // Participant can win
    }else{
      fmt.Println("No") // Participant cannot win
    }
  }

  return // End of the program
}

