
package main // Start of the main package

import "fmt" // Import the fmt package for input/output operations

func main() { // Start of the main function
  var A, B, C, X int // Declare variables A, B, C, and X to store user input
  fmt.Scan(&A, &B, &C, &X) // Read user input for variables A, B, C, and X using fmt.Scan

  cnt := 0 // Initialize counter variable cnt to 0
  for a := 0; a <= A; a++ { // Start of the outermost for loop, iterating from 0 to A
    for b := 0; b <= B; b++ { // Start of the inner for loop, iterating from 0 to B
      for c := 0; c <= C; c++ { // Start of the innermost for loop, iterating from 0 to C
        total := 500*a + 100*b + 50*c // Calculate the total value based on the current values of a, b, and c
        if total == X { // If the total value equals X, increment the counter variable cnt
          cnt++
        }
      }
    }
  }
  fmt.Println(cnt) // Output the final value of the counter variable cnt to the console
}

