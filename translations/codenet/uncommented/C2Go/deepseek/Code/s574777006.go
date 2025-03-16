package main

import (
	"fmt"
)

func main() {
	var n, i, j, q int
	var x [10000]int
	var y [500]int
	var sum int

	fmt.Scan(&n)

	for i = 0; i < n; i++ {
		fmt.Scan(&x[i])
	}

	fmt.Scan(&q)

	for i = 0; i < q; i++ {
		fmt.Scan(&y[i])
	}

	for i = 0; i < q; i++ {
		for j = 0; j < n; j++ {
			if y[i] == x[j] {
				sum = sum + 1
				break
			}
		}
	}

	fmt.Println(sum)
}

