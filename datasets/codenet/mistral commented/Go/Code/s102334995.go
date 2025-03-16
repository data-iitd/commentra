// Importing the 'fmt' package for input/output operations
package main

import (
  "fmt"
)

func main() {
  // Declaring two integer variables 'a' and 'b'
  var a, b int

  // Reading input values for variables 'a' and 'b' from the standard input
  fmt.Scan(&a, &b)

  // Multiplying the variables 'a' and 'b' and printing the result
  fmt.Println(a * b)

  // Multiplying the sum of 'a' and 'b' with 2 and printing the result
  fmt.Println((a + b) * 2)
}

// End of the code
