package main

import "fmt"

func main() {
  var n int
  var array [100]int

  // Take the size of the array as input from the user
  fmt.Scan(&n)

  // Initialize the array with user input
  for i := 0; i < n; i++ {
    fmt.Scan(&array[i]) // Read an element from the user and store it in the array
  }

  sum := 0 // Initialize the sum variable to zero

  // Calculate the sum of all the products of distinct pairs of elements in the array
  for i := 0; i < n-1; i++ { // Outer loop runs from 0 to n-2
    for j := i+1; j < n; j++ { // Inner loop runs from i+1 to n
      sum += array[i] * array[j] // Add the product of current and next element to the sum
    }
  }

  // Print the sum of all the products of distinct pairs of elements in the array
  fmt.Println(sum)
}

