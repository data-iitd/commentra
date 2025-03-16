
package main

import "fmt"

func main() {
  var n int64 // Declare a variable to store the number of elements in the array

  fmt.Print("Enter the number of elements: ")
  fmt.Scan(&n) // Read the number of elements from the standard input and store it in n

  a := make([]int64, n) // Declare an array of size n to store the input numbers
  count := make([]int64, n) // Declare an array of size n to store the count of occurrences of each number

  fmt.Println("Enter", n, "numbers:")
  for i := int64(0); i < n; i++ { // Initialize the array a with input numbers
    fmt.Scan(&a[i])
  }

  fmt.Println("Initializing count array with zeros:")
  for i := int64(0); i < n; i++ { // Initialize all elements of the count array to zero
    count[i] = 0
  }

  fmt.Println("Counting occurrences:")
  for i := int64(0); i < n; i++ { // Iterate through the array a and increment the corresponding element in the count array
    count[a[i]-1]++
  }

  fmt.Println("Printing the contents of the count array:")
  for i := int64(0); i < n; i++ { // Print the contents of the count array to the standard output
    fmt.Println(count[i])
  }

  fmt.Println("Program completed successfully.")
}

