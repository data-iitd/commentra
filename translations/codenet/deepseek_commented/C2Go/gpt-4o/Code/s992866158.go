package main // Declare the main package

import (
	"fmt" // Import the fmt package for input and output
)

func main() {
	var n, k, cnt int // Declare necessary variables

	fmt.Scan(&n, &k) // Read input values
	cnt = 0 // Initialize the count variable
	for n > 0 { // Use a for loop to read each height
		var h int

		fmt.Scan(&h) // Read each height
		if h >= k { // Check if the height is suitable
			cnt++ // Increment the count if the height is greater than or equal to k
		}
		n-- // Decrement n
	}
	fmt.Println(cnt) // Print the final count
}

// <END-OF-CODE>
