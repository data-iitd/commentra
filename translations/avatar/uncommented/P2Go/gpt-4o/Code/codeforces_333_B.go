package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	b := make([]int, n*2)
	for i := range b {
		b[i] = 1
	}
	b[0] = 0
	b[n-1] = 0
	b[n] = 0
	b[2*n-1] = 0

	for i := 0; i < m; i++ {
		var r, c int
		fmt.Scan(&r, &c)
		b[r-1] = 0
		b[n+c-1] = 0
	}

	if n%2 == 1 && b[n/2] == 1 && b[n+n/2] == 1 {
		b[n/2] = 0
	}

	sum := 0
	for _, value := range b {
		sum += value
	}

	fmt.Println(sum)
}

// <END-OF-CODE>
