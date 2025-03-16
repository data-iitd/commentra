package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the integer n
	var str string
	fmt.Scan(&str) // Read the string str

	t := 0
	x, y := 0, 0

	// Check each character in the string
	for i := 0; i < n; i++ {
		if str[i] != '4' && str[i] != '7' {
			t = 1 // Set t to 1 if a character is neither '4' nor '7'
		}
	}

	// If t is 1, print "NO"
	if t == 1 {
		fmt.Println("NO")
	} else {
		// Calculate the sum of the first half of the string
		for i := 0; i < n/2; i++ {
			x += int(str[i] - '0') // Convert character to integer
		}
		// Calculate the sum of the second half of the string
		for i := n - 1; i >= n/2; i-- {
			y += int(str[i] - '0') // Convert character to integer
		}
		// If x equals y, print "YES", otherwise print "NO"
		if x == y {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

// <END-OF-CODE>
