package main

import "fmt"

func main() {
  // Declare and initialize two integer variables, x and a
  var x, a int

  // Read data from the standard input stream and store it into x and a
  fmt.Scan(&x, &a)

  // Check if x is greater than or equal to a
  result := 0
  if x >= a {
    result = 10
  }

  // Print the result to the standard output stream
  fmt.Println(result)
}

