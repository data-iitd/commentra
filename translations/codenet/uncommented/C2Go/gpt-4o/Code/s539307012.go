package main

import (
	"fmt"
)

func main() {
	var n, x, min, m int
	fmt.Scan(&n, &x, &min)
	x -= min

	for i := 1; i < n; i++ {
		fmt.Scan(&m)
		x -= m
		if min > m {
			min = m
		}
	}

	fmt.Println(n + x/min)
}

// <END-OF-CODE>
