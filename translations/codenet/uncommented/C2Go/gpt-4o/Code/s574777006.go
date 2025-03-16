package main

import (
	"fmt"
)

func main() {
	var n, q int
	var sum int
	x := make([]int, 10000)
	y := make([]int, 500)

	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		fmt.Scan(&x[i])
	}

	fmt.Scan(&q)

	for i := 0; i < q; i++ {
		fmt.Scan(&y[i])
	}

	for i := 0; i < q; i++ {
		for j := 0; j < n; j++ {
			if y[i] == x[j] {
				sum++
				break
			}
		}
	}

	fmt.Println(sum)
}

// <END-OF-CODE>
