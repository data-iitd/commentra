package main

import (
	"fmt"
)

func main() {
	const N = 368
	m := make([]int, N)
	f := make([]int, N)

	var T int
	fmt.Scan(&T)

	for i := 0; i < T; i++ {
		var x string
		var a, b int
		fmt.Scan(&x, &a, &b)
		b++ // Increment b by 1

		if x == "M" {
			m[a] += 2
			m[b] -= 2
		} else {
			f[a] += 2
			f[b] -= 2
		}
	}

	a, b, c := 0, 0, 0
	for i := 0; i < N; i++ {
		a += m[i]
		b += f[i]
		if min(a, b) > c {
			c = min(a, b)
		}
	}

	fmt.Println(c)
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// <END-OF-CODE>
