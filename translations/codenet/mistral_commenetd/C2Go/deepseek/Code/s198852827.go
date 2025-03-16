package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	var t, x, y, nx, ny, nt int
	var i, j, k int
	var tmp int

	fmt.Scan(&N)

	for i = 0; i < N; i++ {
		fmt.Scan(&t, &x, &y)

		tmp = t - nt - int(math.Abs(float64(x-nx)) + math.Abs(float64(y-ny)))

		if tmp < 0 || tmp%2 != 0 {
			fmt.Println("No")
			return
		}

		nx = x
		ny = y
		nt = t
	}

	fmt.Println("Yes")
}

