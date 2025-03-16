/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

// Define constants
const mod = 998244353 // Define a constant for modulo arithmetic

// Function to solve the problem
func solve() {
	var n int64 // Declare a variable for taking input
	var ans int64 = 0 // Declare a variable for storing the answer
	fmt.Scan(&n) // Read input for n
	fmt.Println(n == 0) // Print output if n is not positive
}

func main() {
	n := int64(1) // Initialize a variable for number of test cases
	for n > 0 { // Loop for each test case
		solve() // Call the solve function
		n-- // Decrement the test case counter
	}
}

// <END-OF-CODE>
