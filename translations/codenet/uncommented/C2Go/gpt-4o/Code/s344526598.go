package main

import (
	"fmt"
)

func main() {
	var x [10000]int
	i := 0

	for i < 10000 {
		x[i] = 0
		i++
	}

	i = 0
	fmt.Scan(&x[i])

	for x[i] != 0 {
		i++
		fmt.Scan(&x[i])
	}

	for j := 0; j < i; j++ {
		fmt.Printf("Case %d: %d\n", j+1, x[j])
	}
}

// <END-OF-CODE>
