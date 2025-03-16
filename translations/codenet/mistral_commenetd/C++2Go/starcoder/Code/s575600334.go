<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

// Function to print binary representation of a number
func binPrint(x int, bits int){
  // Iterate through each bit starting from the last one
  for i := bits - 1; i >= 0; i--{
    // Print the bit value based on the bitwise AND operation with the mask (1<<i)
    fmt.Printf("%d", x & (1<<i)!= 0)
  }
  // Print newline character after printing the binary number
  fmt.Println()
}

func main() {
  // Declare unsigned integer variables a and b
  var a uint
  var b uint

  // Read integer values of a and b from the standard input
  fmt.Scan(&a, &b)

  // Print binary representation of bitwise AND of a and b
  binPrint(a & b, 32)

  // Print binary representation of bitwise OR of a and b
  binPrint(a | b, 32)

  // Print binary representation of bitwise XOR of a and b
  binPrint(a ^ b, 32)
}

