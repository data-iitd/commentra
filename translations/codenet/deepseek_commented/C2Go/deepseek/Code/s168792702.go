package main

import (
	"fmt"  // Import the fmt package for formatted I/O operations
)

func main() {
	var a, b, c int  // Declare three integer variables
	fmt.Scan(&a, &b, &c)  // Read three integers from the user and store them in variables a, b, and c
	
	if a < b && b < c {  // Check if a is less than b and b is less than c
		fmt.Println("Yes")  // Print "Yes" if the condition is true
	} else {
		fmt.Println("No")  // Print "No" if the condition is not met
	}
}

