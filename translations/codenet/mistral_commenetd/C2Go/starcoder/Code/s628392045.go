// Include necessary header files
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

// Declare and initialize variables
var n int
var h [100001]int
var max int = -1
var flag int = 0

func main() {
  // Read the number of test cases
  fmt.Scanf("%d", &n)

  // Read and process input
  for i := 0; i < n; i++ {
    // Read the next integer from standard input and store it in the array h
    fmt.Scanf("%d", &h[i])

    // Update the maximum height if the current height is greater
    if max < h[i] {
      max = h[i]
    }

    // Check if the difference between the current height and maximum height is greater than or equal to 2
    if max-h[i] >= 2 {
      flag = 1
    }
  }

  // Check the value of the flag and print the appropriate message to the standard output
  if flag == 1 {
    fmt.Printf("No\n")
  } else {
    fmt.Printf("Yes\n")
  }
}

