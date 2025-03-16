
package main

import "fmt"

func main() {

  var i, j, N int // Declare variables for loop indices, array size, and array elements

  fmt.Scan(&N) // Read the size of the array

  A := make([]int, N) // Create an array of size N

  for i = 0; i < N; i++ {
    fmt.Scan(&A[i]) // Read the elements of the array
  }

  // Implement Bubble Sort
  for i = 0; i < N - 1; i++ {
    for j = N - 1; j > i; j-- {
      if A[j] < A[j - 1] {
        tmp := A[j] // Swap A[j] and A[j-1]
        A[j] = A[j - 1]
        A[j - 1] = tmp
      }
    }
  }

  for i = 0; i < N; i++ {
    fmt.Printf("%d", A[i]) // Print the sorted array elements
    if i < N - 1 {
      fmt.Printf(" ") // Print a space between elements, but not after the last element
    }
  }

  fmt.Printf("\n") // Print a newline character to end the line

  fmt.Printf("%d\n", count) // Print the number of swaps

}

