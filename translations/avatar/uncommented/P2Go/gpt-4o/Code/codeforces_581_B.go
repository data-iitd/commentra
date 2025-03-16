package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	ans := make([]int, n)
	mx := arr[n-1]

	for i := n - 2; i >= 0; i-- {
		ans[i] = int(math.Max(0, float64(mx-arr[i]+1)))
		if arr[i] > mx {
			mx = arr[i]
		}
	}

	for _, value := range ans {
		fmt.Print(value, " ")
	}
	fmt.Println()
}

// <END-OF-CODE>
