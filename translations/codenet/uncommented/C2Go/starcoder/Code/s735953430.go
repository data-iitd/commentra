package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var i_min, min int
	var i, j, k int
	var X, N int
	fmt.Scanf("%d %d", &X, &N)
	if N == 0 {
		fmt.Printf("%d\n", X)
		os.Exit(0)
	}
	plus := make([]int, 256)
	minus := make([]int, 256)
	for i = 0; i < 256; i++ {
		plus[i] = i
		minus[i] = (-1 * i)
	}
	for i = 0; i < N; i++ {
		fmt.Scanf("%d", &j)
		plus[j] = 0
	}
	i_min = 0
	min = 1000
	for i = 255; i >= 0; i-- {
		if plus[i] == 0 && i > 0 {
			continue
		}
		k = X - plus[i]
		if k < 0 {
			k *= -1
		}
		if k <= min {
			min = k
			i_min = i
		}
	}
	fmt.Printf("%d\n", i_min)
}

