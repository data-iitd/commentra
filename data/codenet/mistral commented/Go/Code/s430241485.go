package main

import "fmt" // Import the "fmt" package for formatted I/O

func main(){ // Define the main function, entry point of our program
	// Declare two variables, s and t, both of type string
	var s, t string

	// Use the "fmt.Scan" function to read input from the standard input (keyboard)
	// and store it in variables s and t respectively
	fmt.Scan(&s, &t)

	// Print the concatenated string of t and s using the "fmt.Println" function
	fmt.Println(t + s)
}

