package main

import (
	"fmt"
)

func main() {
	var i, j int
	var x [10000]int

	for i = 0; i < 10000; i++ {
		x[i] = 0
	}
	i = 0
	fmt.Scan(&x[i])

	for x[i] != 0 {
		i++
		fmt.Scan(&x[i])
	}

	for j = 0; j < i; j++ {
		fmt.Printf("Case %d: %d\n", j+1, x[j])
	}
}

