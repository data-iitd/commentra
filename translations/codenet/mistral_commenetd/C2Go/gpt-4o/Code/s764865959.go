package main // Declaring the main package

import "fmt" // Importing the fmt package for formatted I/O

func main() { // Starting the main function
	var x int // Declaring an integer variable x

	fmt.Scanf("%d", &x) // Reading an integer value from the user and storing it in variable x

	// The following block of code calculates x raised to the power of 3
	x = x * x * x

	// Printing the result to the console
	fmt.Println(x)

} // Indicating successful execution of the program
// <END-OF-CODE>
