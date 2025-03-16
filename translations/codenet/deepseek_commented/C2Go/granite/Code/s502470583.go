
package main

import "fmt"  // Import the standard input/output library

func main() {
  var a, b, c, d int  // Declare four integer variables

  // Read two integer values from the standard input and store them in a and b
  fmt.Scan(&a, &b)

  // Calculate the product of a and b, and store it in c
  c = a * b

  // Calculate the perimeter of a rectangle with sides a and b, and store it in d
  d = 2 * a + 2 * b

  // Print the values of c and d to the standard output
  fmt.Printf("%d %d\n", c, d)
}

