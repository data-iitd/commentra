

package main // Import the standard library package

import "fmt" // Import the standard input/output package

func main(){ // Start of the main function
  var a, b, x, y int // Declare variables a, b, x, and y as integers

  fmt.Scanf("%d%d",&a,&b) // Read two integers from the standard input and store them in variables a and b

  x = a*b // Multiply the values of variables a and b and store the result in variable x
  y = (a+b)*2 // Add the values of variables a and b, then multiply the result by 2 and store it in variable y

  fmt.Printf("%d %d\n",x,y) // Print the values of variables x and y to the standard output, followed by a newline character
}

