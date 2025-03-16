package main

import (
	"fmt"
)

func main() {
	var n, r, i, j, p, c int
	var a, b []int

	for {
		fmt.Scan(&n, &r)
		if n == 0 && r == 0 {
			break
		}

		a = make([]int, n)
		for i = 0; i < n; i++ {
			a[i] = n - i
		}

		for i = 0; i < r; i++ {
			b = make([]int, n)
			for j = 0; j < n; j++ {
				b[j] = a[j]
			}
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

