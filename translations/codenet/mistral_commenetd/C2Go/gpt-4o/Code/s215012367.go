package main // Declaring the main package

import "fmt" // Importing the fmt package for formatted I/O

func main() { // Declaring the main function
	var a, b, s int // Declaring three integer variables a, b, and s

	fmt.Scanf("%d %d", &a, &b) // Reading two integers from the user and storing them in variables a and b

	s = (a * b) - (a + b) + 1 // Calculating the value of s by multiplying a and b, subtracting the sum of a and b, and adding 1

	// The following line prints the value of s to the console
	fmt.Println(s)

} // Indicating that the program has run successfully
// <END-OF-CODE>
