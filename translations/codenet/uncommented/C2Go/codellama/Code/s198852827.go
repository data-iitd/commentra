package main

import (
	"fmt"
)

func main() {
	var N, t, x, y, nx, ny, nt int
	fmt.Scan(&N)
	for i := 0; i < N; i++ {
		fmt.Scan(&t, &x, &y)
		tmp := t - nt - (ABS(x-nx) + ABS(y-ny))
		if tmp < 0 || tmp%2 != 0 {
			fmt.Println("No")
			return
		}
	}
	fmt.Println("Yes")
}

func ABS(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

