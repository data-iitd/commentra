package main

import (
	"fmt"
	"sort"
)

func resolve() {
	var n int
	fmt.Scan(&n)
	low := make([]int, 0, n)
	high := make([]int, 0, n)

	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		low = append(low, a)
		high = append(high, b)
	}

	sort.Ints(low)
	sort.Ints(high)

	if n%2 == 1 {
		fmt.Println(high[(n+1)/2-1] - low[(n+1)/2-1] + 1)
	} else {
		hh := float64(high[n/2-1]+high[n/2]) / 2
		ll := float64(low[n/2-1]+low[n/2]) / 2
		fmt.Println(int((hh-ll)*2) + 1)
	}
}

func main() {
	resolve()
}

// <END-OF-CODE>
