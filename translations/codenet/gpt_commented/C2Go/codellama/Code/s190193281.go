package main

import "fmt"

const N = 1000000  // Maximum size for the array S
const Q = 50000    // Maximum size for the array T

var n, S [N]int  // Declare variables: n for the number of elements, S for the sorted array
var T [Q]int  // Declare variable: T for the query array

// Function to perform binary search on the sorted array S
func binarySearch(key int) int {
  left, right := 0, n  // Initialize left and right pointers for the search range
  for left < right {  // Continue searching while the range is valid
    mid := (left + right) / 2  // Calculate the middle index
    if S[mid] == key {  // If the key is found, return 1
      return 1
    } else if key < S[mid] {  // Narrow the search to the left half
      right = mid
    } else {  // Narrow the search to the right half
      left = mid + 1
    }
  }
  return 0  // If the key is not found, return 0
}

func main() {
  var i, j, q, c int  // Declare variables: i for loops, q for number of queries, c for count of found keys
  
  // Read the number of elements in the sorted array S
  fmt.Scan(&n)
  
  // Read the elements into the sorted array S
  for i = 0; i < n; i++ {
    fmt.Scan(&S[i])
  }
  
  // Read the number of queries
  fmt.Scan(&q)
  
  // Process each query to check if it exists in the sorted array S
  for i = 0; i < q; i++ {
    fmt.Scan(&T[i])  // Read the query element into array T
    if binarySearch(T[i]) == 1 {  // If the element is found, increment the count
      c++
    }
  }
   
  // Output the total count of found elements
  fmt.Println(c)
}

