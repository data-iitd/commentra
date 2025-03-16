
package main

import "fmt"

// Function to perform linear search on an array
func linearsearch(S []int, n int, key int) int {
  var i int = 0 // Initialize index variable i to 0
  var count int = 0 // Initialize count variable to 0

  // Search for the key in the array S until it is found or the end of the array is reached
  for i < n {
    if S[i] == key {
      return 0 // If key is found, return 0 to indicate that it was found
    }
    i++ // Increment i by 1 for each iteration
  }

  // If key is not found, return 1 to indicate that it was not found
  return 1
}

// Main function to read input and call linearsearch function
func main() {
  var i, j, n, q int // Declare and initialize variables
  var S, T []int // Declare and initialize arrays
  var count int = 0 // Initialize count variable to 0

  // Read the size of the array S from the user
  fmt.Print("Enter the size of the array S: ")
  fmt.Scan(&n)

  // Read the elements of array S from the user
  fmt.Print("Enter ", n, " integers for array S:\n")
  for i = 0; i < n; i++ {
    fmt.Print("Enter integer S[", i, "]: ")
    fmt.Scan(&S[i])
  }

  // Read the number of queries from the user
  fmt.Print("Enter the number of queries: ")
  fmt.Scan(&q)

  // Read the elements of array T from the user
  fmt.Print("Enter ", q, " integers for array T:\n")
  for j = 0; j < q; j++ {
    fmt.Print("Enter integer T[", j, "]: ")
    fmt.Scan(&T[j])
  }

  // Call linearsearch function for each element of array T and increment count if key is not found
  for j = 0; j < q; j++ {
    key := T[j] // Assign the current element of array T to key variable
    if linearsearch(S, n, key) == 1 { // Call linearsearch function and check if count is 1 (key not found)
      count++ // Increment count if key is not found
    }
  }

  // Print the final count to the user
  fmt.Print("Number of integers in array S that are not present in array T: ", count, "\n")

  // Return 0 to indicate successful execution of the program
  return 0
}

