package main

import (
	"fmt"
)

func main() {
	var n, d int
	fmt.Scan(&n, &d)

	x := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i])
	}

	m := 0
	for a := 0; a < n-1; a++ {
		if x[a] >= x[a+1] {
			q := (x[a] - x[a+1]) / d + 1
			m += q
			x[a+1] += q * d
		}
	}
	fmt.Println(m)
}

// <END-OF-CODE>
