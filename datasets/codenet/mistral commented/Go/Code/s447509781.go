// Package main is the entry point of the program
package main

import (
  "bufio" // Import bufio package for reading input
  "fmt"   // Import fmt package for printing output
  "os"    // Import os package for reading from standard input
  "strconv" // Import strconv package for converting strings to integers
  "strings" // Import strings package for splitting strings
)

// Define the main function
func main() {
  // Initialize the input reader
  input := Input{bufio.NewReaderSize(os.Stdin,1000000)}

  // Read the first integer from the input
  n := input.NextInt()

  // Read the second integer array from the input
  s := input.NextIntArray()

  // Initialize a boolean slice of size n
  u := make([]bool,n)

  // Initialize two integer variables m and f
  var m, f int64

  // Iterate through all the subarrays of size c+1, where c ranges from 1 to n-2
  for c := 1; c < n-1; c++ {
    // Initialize a variable f to 0
    f = 0

    // Iterate through all the subarrays of size c+1, where k ranges from 0 to n-1-c*c
    for k := 0; c < n-1-k*c; k++ {
      // Set the boolean value of the current index to true
      u[k*c] = true

      // Check if the boolean value of the last index of the current subarray is already set to true
      // If it is, break the inner loop as we don't need to check further
      if u[n-1-k*c] { break }

      // Calculate the sum of the current and previous subarrays
      f += s[n-1-k*c] + s[k*c]

      // Update the value of m if the current sum is greater than the previous maximum sum
      if m < f { m = f }

      // Set all the boolean values of the current subarray to false
    }

    // Iterate through all the indices of the current subarray and set their boolean values to false
    for k := 0; k*c < n-1; k++ { u[k*c] = false }
  }

  // Print the maximum sum
  fmt.Println(m)
}

// Define the Input struct and its methods for reading input
type Input struct {
  reader *bufio.Reader
}
func(i *Input) NextLine() string {
  // Read a line from the input and return it as a string
}
func(i *Input) NextInt() int {
  // Read an integer from the input and return it
}
func(i *Input) NextIntArray() []int64 {
  // Read an array of integers from the input and return it
}

// Define the Input struct and its methods for reading input ends here
