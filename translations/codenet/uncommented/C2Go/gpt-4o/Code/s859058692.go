package main

import (
	"fmt"
)

func main() {
	var sum int64 = 0
	var m, n, min, max int

	fmt.Scanf("%d\n", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &m)
		sum += int64(m)
		if i == 0 {
			min = m
			max = m
		}

		if min > m {
			min = m
		}
		if max < m {
			max = m
		}
	}
	fmt.Printf("%d %d %d\n", min, max, sum)
}

// <END-OF-CODE>
