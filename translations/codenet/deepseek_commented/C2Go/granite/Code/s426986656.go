
package main

import "fmt"  // Import the standard input/output library

func main() {
  var A, B int  // Declare integer variables A and B
  fmt.Scan(&A, &B)  // Read input values for A and B

  flag := false  // Declare boolean variable flag

  // Loop through numbers 1 to 3 to check if the product of A, B, and i is odd
  for i := 1; i <= 3; i++ {
    if (A*B*i)%2 == 1 {  // Check if the product is odd
      flag = true  // Set flag to true if an odd product is found
      break  // Break out of the loop
    }
  }

  if flag {  // Check if flag is true
    fmt.Println("Yes")  // Print "Yes" if an odd product was found
  } else {
    fmt.Println("No")  // Print "No" if no odd product was found
  }
}

