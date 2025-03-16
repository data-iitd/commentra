package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k) // Read two integer values from the user and store them in n and k.

	n++ // Increment the value of n by 1.

	z := 0 // Initialize a variable z to 0.

	if n%k != 0 { // Check if n is not divisible by k.
		z = k - n%k // If true, calculate the difference between k and the remainder of n divided by k, and store it in z.
	}

	fmt.Println(n + z) // Print the new value of n plus the value of z.
}

