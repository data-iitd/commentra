
package main

import "fmt"

// Initialize the main function
func main() {
  // Initialize a for loop that will iterate 5 times
  for i := 0; i < 5; i++ {
    // Declare and initialize a variable 'a' to store user input
    var a int

    // Request user input and store it in variable 'a'
    fmt.Scan(&a)

    // Check if the user input is equal to zero
    if a == 0 {
      // If user input is zero, print the current iteration number
      fmt.Println(i + 1)
    }
  }
}
