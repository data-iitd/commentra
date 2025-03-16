package main

import (
	"fmt"
)

func main() {
	var N, X int
	fmt.Scan(&N, &X)
	L := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&L[i])
	}

	var i int
	var d int
	for i = 0; i < N; i++ {
		d = d + L[i]
		if d > X {
			break
		}
	}

	fmt.Println(i + 1)
}

