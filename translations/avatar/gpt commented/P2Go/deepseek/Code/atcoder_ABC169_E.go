package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	low := make([]int, n)
	high := make([]int, n)

	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		low[i] = a
		high[i] = b
	}

	sort.Ints(low)
	sort.Ints(high)

	if n%2 == 1 {
		fmt.Println(high[(n+1)/2-1] - low[(n+1)/2-1] + 1)
	} else {
		hh := (high[n/2-1] + high[n/2]) / 2.0
		ll := (low[n/2-1] + low[n/2]) / 2.0
		fmt.Println(int((hh-ll)*2) + 1)
	}
}

