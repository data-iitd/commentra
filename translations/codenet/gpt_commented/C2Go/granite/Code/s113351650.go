
package main

import "fmt"

func main() {
  
  // Declare an integer variable 'x' to store user input
  var x int
  
  // Prompt the user for input and read an integer value into 'x'
  fmt.Scan(&x)
  
  // Check if the input value is 0
  if x == 0 {
    // If true, print "1" to the output
    fmt.Println("1")
  }
  
  // Check if the input value is 1
  if x == 1 {
    // If true, print "0" to the output
    fmt.Println("0")
  }
  
}

