<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

// Function to print the binary representation of an integer x with a specified number of bits
func binPrint(x int, bits int){
  for i:=bits-1; i>=0; i--{
    fmt.Printf("%d", x&(1<<i)>0)
  }
  fmt.Println()
}

func main(){
  var a,b uint32
  fmt.Scanf("%d %d", &a, &b)  // Read two unsigned integers from standard input

  binPrint(a&b, 32)  // Print the binary AND of a and b
  binPrint(a|b, 32)  // Print the binary OR of a and b
  binPrint(a^b, 32)  // Print the binary XOR of a and b
  
  fmt.Println("