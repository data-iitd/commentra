package main

import (
	"fmt"
)

func main() {
	var n int
	var a [10000]int
	var min, max int
	var sum int64 = 0

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		sum += int64(a[i])
	}

	max = a[0]
	min = a[0]
	for i := 1; i < n; i++ {
		if a[i] > max {
			max = a[i]
		}
		if a[i] < min {
			min = a[i]
		}
	}

	fmt.Printf("%d %d %d\n", min, max, sum)
}

// <END-OF-CODE>
