package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	pre := math.Inf(0)
	ans := 0

	sort.Sort(sort.Reverse(sort.IntSlice(a)))

	for j := 0; j < n; j++ {
		ans += int(math.Max(0, math.Min(pre-1, float64(a[j]))))
		pre = math.Min(pre-1, float64(a[j]))
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
