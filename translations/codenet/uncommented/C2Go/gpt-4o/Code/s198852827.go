package main

import (
	"fmt"
	"math"
)

func ABS(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

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
		nx, ny, nt = x, y, t // Update nx, ny, nt for the next iteration
	}
	fmt.Println("Yes")
}
