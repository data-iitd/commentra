package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	// Initialize a boolean array to keep track of digits that have been seen
	d := make([]bool, 10)
	for i := 0; i < k; i++ {
		var a int
		fmt.Scan(&a)
		d[a] = true
	}

	// Keep generating numbers until a valid one is found
	for {
		x := n
		hantei := true

		// Check each digit in the number 'x'
		for x > 0 {
			if d[x%10] {
				hantei = false
				break
			}
			x /= 10
		}

		// If the current number is valid, print it and exit the loop
		if hantei {
			fmt.Println(n)
			break
		}

		// If the current number is not valid, increment 'n' and continue checking
		n++
	}
}

