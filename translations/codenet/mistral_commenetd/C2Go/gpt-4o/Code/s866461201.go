package main // We declare the main package

import (
	"fmt" // We import the fmt package for formatted I/O
)

func main() { // The main function is the entry point of the program
	var n int // An integer variable named 'n' to store the number of inputs
	fd := make([]int, 6) // An integer slice named 'fd' of size 6, initialized with zeros
	var height float64 // A float64 variable named 'height' to store the height of a person

	fmt.Scan(&n) // Read an integer value from the standard input and store it in the variable 'n'
	for n > 0 { // As long as 'n' is greater than zero, execute the following block of code
		n-- // Decrement the value of 'n'
		fmt.Scan(&height) // Read a floating point value from the standard input and store it in the variable 'height'
		if height >= 185.0 {
			fd[5]++ // If the height is greater than or equal to 185 cm, increment the sixth element of the 'fd' slice
		} else if height >= 180.0 {
			fd[4]++ // Else if the height is greater than or equal to 180 cm, increment the fifth element of the 'fd' slice
		} else if height >= 175.0 {
			fd[3]++ // Else if the height is greater than or equal to 175 cm, increment the fourth element of the 'fd' slice
		} else if height >= 170.0 {
			fd[2]++ // Else if the height is greater than or equal to 170 cm, increment the third element of the 'fd' slice
		} else if height >= 165.0 {
			fd[1]++ // Else if the height is greater than or equal to 165 cm, increment the second element of the 'fd' slice
		} else {
			fd[0]++ // Else, increment the first element of the 'fd' slice
		}
	}

	for i := 0; i < 6; i++ { // Iterate through the 'fd' slice using a for loop
		fmt.Printf("%d:", i+1) // Print the index of the current element of the slice followed by a colon
		for j := 0; j < fd[i]; j++ { // Iterate through the number of occurrences of the current element in the slice
			fmt.Print("*") // Print a star for each occurrence
		}
		fmt.Println() // Print a newline character after each group of stars
	}
}

// <END-OF-CODE>
