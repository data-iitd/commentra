package main

import (
	"fmt"
)

func main() {
	var sum int64 = 0
	var n, m, i, min, max int

	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		fmt.Scan(&m)
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
