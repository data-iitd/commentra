package main // Declare the main package

import ( // Import necessary packages
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // The main function is the entry point of the program
	var r int // Declare an integer variable named "r"

	// Read the value of "r" from standard input using fmt.Scan
	fmt.Scan(&r)

	// Output the square of "r" to standard output using fmt.Println
	fmt.Println(r * r)

	// The program ends here
}

// <END-OF-CODE>
