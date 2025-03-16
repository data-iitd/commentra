
package main  // Define the main package for the Go program.

import "fmt"  // Import the necessary package for input and output operations.

func main(){  // Define the main function which is the entry point of the program.
  var n int  // Declare an integer variable 'n' to store the number of elements.
  fmt.Scan(&n)  // Input the number of elements for the array 'a'.
  a := make([]int, n)  // Create an array 'a' of size 'n' to store the integer inputs.
  for i := 0; i < n; i++ {  // Loop to take 'n' integer inputs and store them in the array 'a'.
    fmt.Scan(&a[i])
  }
  fmt.Print(a[n-1])  // Output the last element of the array 'a'.
  for i := 1; i < n; i++ {  // Loop to output the remaining elements of the array 'a' in reverse order.
    fmt.Printf(" %d", a[n-i-1])
  }
  fmt.Println()  // End the line after outputting all the elements.
}


