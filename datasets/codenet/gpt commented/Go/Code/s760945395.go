package main

import "fmt"

func main() {
  // Loop to iterate 5 times
  for i := 0; i < 5; i++ {
    var a int // Declare a variable 'a' to store user input
    fmt.Scan(&a) // Read an integer input from the user and store it in 'a'
    
    // Check if the input value is zero
    if a == 0 {
      // Print the current iteration index + 1 if the input is zero
      fmt.Println(i + 1)
    }
  }
}
