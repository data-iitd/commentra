package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	nums := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&nums[i])
	}
	var bin int
	var diff int
	for i := 0; i < N; i++ {
		if (bin%2) != (i%2) {
			diff++
		}
		bin++
		bin %= 2
	}
	ans := diff / 2
	fmt.Println(ans)
}

