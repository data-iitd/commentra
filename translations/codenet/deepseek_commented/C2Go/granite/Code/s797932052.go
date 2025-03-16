
package main

import "fmt"

func main() {
  var a, b int // Declare two integer variables to store user input
  fmt.Scan(&a) // Read an integer value from the user and store it in variable a
  fmt.Scan(&b) // Read another integer value from the user and store it in variable b
  if (a*b)%2 == 0 { // Check if the product of a and b is even or odd
    fmt.Println("Even") // Print "Even" if the product is even
  } else {
    fmt.Println("Odd") // Print "Odd" if the product is odd
  }
}

// 