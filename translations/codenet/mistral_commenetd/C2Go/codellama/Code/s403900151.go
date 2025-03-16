package main

import (
	"fmt"
)

func main() {
	var n, r, p, c int
	var i, j, k, l int
	var a [51]int
	var b [51]int

	for {
		fmt.Scanf("%d %d ", &n, &r)
		if !n && !r {
			break
		}

		for i = 0; i < n; i++ {
			a[i] = i + 1
		}

		for i = 0; i < r; i++ {
			fmt.Scanf("%d %d ", &p, &c)

			for j = 0; j < c; j++ {
				b[j] = a[n-p-c+1+j]
			}

			for j = 0; j < p-1; j++ {
				a[n-p+j+1] = a[n-p+j]
			}

			for j = n - p - c + 1, k = 0; k < c; j, k = j+1, k+1 {
				a[j] = b[k]
			}

			fmt.Printf("%d\n", a[n-1])
		}
	}
}

