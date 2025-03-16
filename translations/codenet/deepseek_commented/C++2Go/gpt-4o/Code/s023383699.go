package main // Declare the main package

import "fmt" // Import the fmt package for formatted I/O

func main() { // The main function is the entry point of the program
	var x int // Declare an integer variable x
	fmt.Scan(&x) // Take an integer input from the user and store it in x
	fmt.Println(x * x * x) // Output the cube of the input value x
}

// <END-OF-CODE>
