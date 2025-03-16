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
	
	d := 0
	for i := 0; i < N; i++ {
		d += L[i]
		if d > X {
			break
		}
	}

	fmt.Println(i + 1)
}

