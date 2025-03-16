package main

import (
	"fmt"  // Import the format package for formatted I/O
)

func main() {  // Define the main function
	var x int  // Declare an integer variable
	fmt.Scan(&x)  // Read an integer from the user
	fmt.Println(x * x * x)  // Calculate and print the cube of the input value
}

