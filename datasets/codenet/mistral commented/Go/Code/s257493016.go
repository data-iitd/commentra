package main

import (
  "fmt"
)

// Function to find minimum number in a slice
func min(n ...int) int {
  if len(n) == 0 {
    // Panic if the slice is empty
    panic("len == 0")
  }
  r := n[0]
  // Initialize minimum value with first element of the slice
  for i := 1; i < len(n); i++ {
    // Compare current element with minimum value and update minimum value if current element is smaller
    if n[i] <= r {
      r = n[i]
    }
  }
  // Return the minimum value
  return r
}

// Main function
func main() {
  // Initialize variables for number of floors H, number of jumps N, and variables A and B for each jump
  var H, N, A, B int
  fmt.Scan(&H, &N)

  // Initialize a slice dp of size H+10001 with initial value 2100000000
  dp := make([]int, H+10001)
  for l := 1; l < H+10001; l++ {
    dp[l] = 2100000000
  }

  // Initialize maximum reachable floor amax to 0
  amax := 0
  // Iterate through each jump
  for i := 0; i < N; i++ {
    // Read floor A and number of floors B that can be jumped from floor A
    fmt.Scan(&A, &B)

    // If the maximum reachable floor is less than A, update maximum reachable floor
    if A >= amax {
      amax = A
    }

    // Update dp[A] with minimum of current dp[A] and B
    dp[A] = min(dp[A], B)

    // Iterate through floors from A+1 to H+A and update dp[j] with minimum of current dp[j] and dp[j-A]+B
    for j := A + 1; j <= H+A+1; j++ {
      dp[j] = min(dp[j], dp[j-A]+B)
    }
  }

  // Print the minimum number of jumps required to reach the last floor
  fmt.Println(min(dp[H:H+amax+1]...))

  // End of code
}
