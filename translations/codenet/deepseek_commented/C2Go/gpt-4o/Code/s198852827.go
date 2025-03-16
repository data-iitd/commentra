package main  // Declare the main package

import (
	"fmt"  // Import the fmt package for formatted I/O
)

func ABS(x int) int {  // Define a function to return the absolute value of a number
	if x < 0 {
		return -x
	}
	return x
}

func main() {  // Start of the main function
	var N, t, x, y, nx, ny, nt int  // Declare variables to store the values of N, t, x, y, and their initial positions nx, ny, and starting time nt
	nx, ny, nt = 0, 0, 0  // Initialize nx, ny, and nt to 0

	fmt.Scan(&N)  // Read the number of movements from the standard input
	for i := 0; i < N; i++ {  // Start a loop that runs N times
		fmt.Scan(&t, &x, &y)  // Read the time and coordinates for each movement
		tmp := t - nt - (ABS(x-nx) + ABS(y-ny))  // Calculate the difference between the required time and the actual time needed to reach the coordinates
		if tmp < 0 || tmp%2 != 0 {  // Check if the difference is less than 0 or if it is odd
			fmt.Println("No")  // Output "No" and terminate the program
			return
		}
		nx, ny, nt = x, y, t  // Update the current x-coordinate, y-coordinate, and time
	}
	fmt.Println("Yes")  // If the loop completes without issues, output "Yes"
}

// <END-OF-CODE>
