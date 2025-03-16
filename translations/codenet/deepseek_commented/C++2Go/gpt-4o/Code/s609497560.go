package main // Declare the main package

import "fmt" // Import the fmt package for formatted I/O

func main() {
	var a int // Declare an integer variable 'a'
	fmt.Scan(&a) // Read a value from the user and store it in 'a'
	fmt.Println(a + (a * a) + (a * a * a)) // Calculate and print the sum of 'a', 'a^2', and 'a^3'
}

// <END-OF-CODE>
