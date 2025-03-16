package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	bb := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&bb[i])
	}

	// Initialize an array to store the result
	aa := make([]int, n)
	m := 0

	// Process the array bb in reverse order
	for a := n - 1; a >= 0; a-- {
		j := 0
		for bb[a] > 0 {
			if aa[j] >= a+k {
				bb[a]--
			}
			j++
		}
		for j_ := m; j_ > j; j_-- {
			aa[j_] = aa[j_-1]
		}
		aa[j] = a
		m++
	}

	// Print the contents of the array aa, incrementing each element by 1
	for i := 0; i < n; i++ {
		fmt.Print(aa[i]+1, " ")
	}
	fmt.Println()
}

// <END-OF-CODE>
