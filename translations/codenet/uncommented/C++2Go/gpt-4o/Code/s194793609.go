package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	absA := make([]int64, n)
	for i := 0; i < n; i++ {
		if a[i] < 0 {
			absA[i] = -a[i]
		} else {
			absA[i] = a[i]
		}
	}

	var ans int64 = 0
	min := absA[0]
	for _, e := range absA {
		ans += e
		if min > e {
			min = e
		}
	}

	numNegative := 0
	for _, e := range a {
		if e < 0 {
			numNegative++
		}
	}

	if numNegative%2 != 0 {
		ans -= min * 2
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
