package main

import (
	"fmt"
)

func main() {
	var n, r, i, j, p, c int
	a := make([]int, 100)
	b := make([]int, 100)

	for {
		fmt.Scan(&n, &r)
		if n == 0 && r == 0 {
			break
		}

		for i = 0; i < n; i++ {
			a[i] = n - i
		}

		for i = 0; i < r; i++ {
			copy(b, a) // Copy current state of a to b
			fmt.Scan(&p, &c)

			for j = 0; j < c; j++ {
				a[j] = b[p-1+j]
			}

			for j = c; j < c+p-1; j++ {
				a[j] = b[j-c]
			}
		}
		fmt.Println(a[0])
	}
}

// <END-OF-CODE>
