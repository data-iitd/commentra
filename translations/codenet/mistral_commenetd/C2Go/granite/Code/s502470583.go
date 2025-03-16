

package main // Start of the main package

import "fmt" // Import the standard input/output package

func main( ){ // Start of the main function
  var a, b, c, d int // Declare four integer variables a, b, c, and d

  // Read two integers from the user and store them in variables a and b
  fmt.Scan(&a,&b)

  // Multiply the two integers and store the result in variable c
  c=a*b

  // Multiply each integer with 2 and add them to get the value of d
  d=2*a+2*b

  // Print the values of c and d on the console
  fmt.Printf("%d %d\n",c,d)

  // End of the main function
}

// End of the code