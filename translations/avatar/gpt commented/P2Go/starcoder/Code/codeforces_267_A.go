package main

import "fmt"

func substract(a, b int) int {
	// Check if 'a' is greater than 'b'
	if a > b {
		total := 0 // Initialize total to accumulate results
		// Loop until either 'a' or 'b' becomes zero
		for a > 0 && b > 0 {
			// Add the integer division of 'a' by 'b' to total
			total += a / b
			// Update 'a' to the remainder of 'a' divided by 'b'
			a = a % b
			// If 'a' is still greater than zero, calculate further
			if a > 0 {
				// Add the integer division of 'b' by 'a' to total
				total += b / a
				// Update 'b' to the remainder of 'b' divided by 'a'
				b = b % a
		}
		return total // Return the accumulated total
	}

	// Check if 'a' is less than 'b'
	if a < b {
		total := 0 // Initialize total to accumulate results
		// Loop until either 'a' or 'b' becomes zero
		for a > 0 && b > 0 {
			// Add the integer division of 'b' by 'a' to total
			total += b / a
			// Update 'b' to the remainder of 'b' divided by 'a'
			b = b % a
			// If 'b' is still greater than zero, calculate further
			if b > 0 {
				// Add the integer division of 'a' by 'b' to total
				total += a / b
				// Update 'a' to the remainder of 'a' divided by 'b'
				a = a % b
		}
		return total // Return the accumulated total
	}

	// If 'a' is equal to 'b', return 1
	if a == b {
		return 1
	}
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	lst := make([]int, n)
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scanf("%d %d", &a, &b)
		lst[i] = substract(a, b)
	}
	for i := 0; i < n; i++ {
		fmt.Printf("%d\n", lst[i])
	}
}

