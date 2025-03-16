

package main

import "fmt"

// Function to perform linear search on an array
func linearsearch(S []int, n int, key int) int {
  i := 0 // Initialize index variable i to 0
  count := 0 // Initialize count variable to 0

  // Search for the key in the array S until it is found or the end of the array is reached
  for S[i]!= key {
    i++ // Increment i by 1 for each iteration
    if i >= n { // Check if the end of the array has been reached
      count = 1 // Set count to 1 if key is not found in the array
      return count // Return count to the calling function
    }
  }

  // If key is found, return 0 to indicate that it was found
  return 0
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
  S = make([]int, n) // Create an array of size n to store the elements of array S
  fmt.Println("Enter", n, "integers for array S:")
  for i = 0; i < n; i++ {
    fmt.Print("Enter integer S[", i, "]: ")
    fmt.Scan(&S[i])
  }

  // Read the number of queries from the user
  fmt.Print("Enter the number of queries: ")
  fmt.Scan(&q)

  // Read the elements of array T from the user
  T = make([]int, q) // Create an array of size q to store the elements of array T
  fmt.Println("Enter", q, "integers for array T:")
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
  fmt.Println("Number of integers in array S that are not present in array T:", count)
}

