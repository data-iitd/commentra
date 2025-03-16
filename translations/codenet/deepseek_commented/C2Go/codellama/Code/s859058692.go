package main

import (
	"fmt"
	"strconv"
)

func main() {
	var sum int64
	var min, max int
	var n, m int
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
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

	fmt.Println(min, max, sum)
}

