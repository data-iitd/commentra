package main  // Define the main package

import (  // Import necessary packages
	"fmt"  // Import the fmt package for formatted I/O
)

func main() {  // Define the main function
	var x int  // Declare an integer variable
	fmt.Scanf("%d", &x)  // Read an integer from the user
	fmt.Println(x * x * x)  // Calculate and print the cube of the input value
}  // End of the main function

// <END-OF-CODE>
