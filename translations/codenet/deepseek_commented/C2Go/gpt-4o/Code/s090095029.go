package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m) // Read two integers n and m from standard input

	r0 := make([]bool, n) // Initialize array r0 with false values
	r1 := make([]int, n)  // Initialize array r1
	nr1 := 0              // Set nr1 to 0

	for i := 0; i < m; i++ {
		var a, b int
		fmt.Scan(&a, &b) // Read pairs of integers a and b

		if a > b {
			a, b = b, a // Ensure a is less than or equal to b
		}
		if a == 1 {
			r0[b-1] = true // If a is 1, set r0[b-1] to true
		}
		if b == n {
			r1[nr1] = a - 1 // If b is n, add a-1 to r1
			nr1++           // Increment nr1
		}
	}

	res := false
	for i := 0; i < nr1; i++ {
		if r0[r1[i]] {
			res = true // Check if any element in r1 has a true in r0
		}
	}

	if res {
		fmt.Println("POSSIBLE") // Print "POSSIBLE" if res is true
	} else {
		fmt.Println("IMPOSSIBLE") // Otherwise print "IMPOSSIBLE"
	}
}

// <END-OF-CODE>
