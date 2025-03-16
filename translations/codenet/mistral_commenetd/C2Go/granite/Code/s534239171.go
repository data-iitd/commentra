

package main // Import the standard package

import "fmt" // Import the standard input/output package

func main(){ // Beginning of main function

 var a, b, n int // Declare three integer variables

 fmt.Println("Enter two integers:") // Prompt user to enter two integers
 fmt.Scan(&a,&b) // Read two integers from standard input and store in variables a and b

 n=(a+b)/2 // Calculate the average of a and b and store the result in variable n

 fmt.Printf("The average of %d and %d is: %d\n",a,b,n) // Display the average on standard output
}

