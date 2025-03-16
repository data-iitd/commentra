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
	i := 0
	for i < N {
		d += L[i]
		if d > X {
			break
		}
		i++
	}

	fmt.Println(i + 1)
}

// <END-OF-CODE>
