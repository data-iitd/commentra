package main

import (
  "fmt"
)

// min function returns the minimum value from a variable number of integer arguments.
// It panics if no arguments are provided.
func min(n ...int) int {
  if len(n) == 0 {
    panic("len == 0") // Ensure there is at least one argument
  }
  r := n[0] // Initialize the result with the first argument
  // Iterate through the remaining arguments to find the minimum
  for i := 1; i < len(n); i++ {
    if n[i] <= r {
      r = n[i] // Update the result if a smaller value is found
    }
  }
  return r // Return the minimum value found
}

func main() {
  var H, N, A, B int
  // Read the total height H and the number of items N from input
  fmt.Scan(&H, &N)
  
  // Initialize a dynamic programming array to store the minimum cost for each height
  dp := make([]int, H+10001)
  // Set initial values to a large number (infinity) for all heights
  for l := 1; l < H+10001; l++ {
    dp[l] = 2100000000 // Represents a large value (infinity)
  }
  
  amax := 0 // Variable to track the maximum height of items
  // Process each item
  for i := 0; i < N; i++ {
    // Read the height A and cost B of the current item
    fmt.Scan(&A, &B)
    // Update amax if the current item's height is greater
    if A >= amax {
      amax = A
    }
    // Update the minimum cost for achieving height A
    dp[A] = min(dp[A], B)
    // Update the minimum cost for all heights from A+1 to H+A+1
    for j := A + 1; j <= H + amax + 1; j++ {
      dp[j] = min(dp[j], dp[j-A] + B) // Calculate the minimum cost for height j
    }
  }
  
  // Print the minimum cost to achieve height H considering all possible heights up to amax
  fmt.Println(min(dp[H:H+amax+1]...))
}
