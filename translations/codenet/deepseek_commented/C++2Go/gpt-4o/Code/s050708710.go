package main

import (
	"fmt"
)

func main() {
	var r, g, b, n int // Declare four integer variables to store input values.
	fmt.Scan(&r, &g, &b, &n) // Read four integers from the standard input.
	ans := 0 // Initialize a variable 'ans' to 0 to store the count of valid combinations.

	// Start a nested loop to iterate through possible values of 'i' and 'j' that represent the number of times 'r' and 'g' are used, respectively.
	for i := 0; i <= n/r; i++ {
		for j := 0; j <= n/g; j++ {
			num := n - r*i - g*j // Calculate the remaining value after using 'r * i' and 'g * j'.
			if num >= 0 && num%b == 0 { // Check if 'num' is non-negative and divisible by 'b'.
				ans++ // Increment 'ans' if the conditions are met.
			}
		}
	}

	fmt.Println(ans) // Print the value of 'ans' which represents the count of valid combinations.
}

// <END-OF-CODE>
