package main

import (
	"fmt"
	"math"
)

func main() {
	var X, N int
	fmt.Scan(&X, &N)

	if N == 0 {
		fmt.Println(X)
		return
	}

	plus := make([]int, 256)
	minus := make([]int, 256)
	for i := 0; i < 256; i++ {
		plus[i] = i
		minus[i] = -i
	}

	for i := 0; i < N; i++ {
		var j int
		fmt.Scan(&j)
		plus[j] = 0
	}

	i_min := 0
	min := math.MaxInt32
	for i := 255; i >= 0; i-- {
		if plus[i] == 0 && i > 0 {
			continue
		}
		k := X - plus[i]
		if k < 0 {
			k *= -1
		}
		if k <= min {
			min = k
			i_min = i
		}
	}

	fmt.Println(i_min)
}

// <END-OF-CODE>
