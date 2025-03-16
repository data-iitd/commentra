package main

import (
	"fmt"
)

// Function to read a long long integer
func cin() int64 {
	var n int64
	fmt.Scan(&n)
	return n
}

// Main function
func main() {
	// Read input values for l, r, and d
	l := cin()
	r := cin()
	d := cin()

	// Count the multiples of d in the range [l, r]
	ans := int64(0)
	for i := l; i <= r; i++ {
		if i%d == 0 {
			ans++
		}
	}

	// Output the result
	fmt.Println(ans)
}

// <END-OF-CODE>
