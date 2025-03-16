
package main

import "fmt"

// Function main is the entry point of the program
func main() {
	// Declare a variable n of type int and initialize it to zero
	var n int
	// Read an integer value from the standard input and store it in the variable n
	fmt.Scan(&n)
	// Declare a variable ans of type int and initialize it to zero
	ans := 0
	// Use a for loop to iterate through all possible factors of n
	for i := 1; i*i < n {
		// Check if i is a factor of n
		if n%i == 0 {
			// Check if i is the last factor of n
			if n%(n/i-1) == i {
				// If both conditions are true, add the last factor to the answer
				ans += n / i - 1
			}
		}
	}
	// Print the answer to the standard output
	fmt.Println(ans)
	// End of the code
}