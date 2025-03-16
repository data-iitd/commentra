

package main

import "fmt"

func main() {
  var n int // Declare an integer variable 'n' to store the size of the array
  fmt.Println("Enter the size of the array:")
  fmt.Scan(&n) // Take the size of the array as input from the user

  array := make([]int, n) // Initialize an integer array 'array' of size 'n'

  // Initialize the array with user input
  for i := 0; i < n; i++ {
    fmt.Printf("Enter element %d: ", i+1)
    fmt.Scan(&array[i]) // Read an element from the user and store it in the array
  }

  sum := 0 // Initialize the sum variable to zero

  // Calculate the sum of all the products of distinct pairs of elements in the array
  for i := 0; i < n-1; i++ { // Outer loop runs from 0 to n-2
    for j := i + 1; j < n; j++ { // Inner loop runs from i+1 to n
      sum += array[i] * array[j] // Add the product of current and next element to the sum
    }
  }

  // Print the sum of all the products of distinct pairs of elements in the array
  fmt.Println("Sum of all the products of distinct pairs of elements in the array:", sum)
}

