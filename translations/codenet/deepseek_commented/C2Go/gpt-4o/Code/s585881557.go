package main  // Define the main package

import (  // Import necessary packages
	"fmt"  // Import the fmt package for formatted I/O
)

func main() {  // Define the main function, the entry point of the program
	var h, r int  // Declare two integer variables
	fmt.Scanf("%d%d", &h, &r)  // Read two integers from the standard input and store them in h and r
	if r > -h {  // Check if r is greater than -h
		fmt.Println("1")  // If true, print 1
	} else if r == -h {  // If the condition in the if statement is false, check if r is equal to -h
		fmt.Println("0")  // If true, print 0
	} else {  // If neither of the above conditions is true
		fmt.Println("-1")  // Print -1
	}
}  // End of main function
// <END-OF-CODE>
