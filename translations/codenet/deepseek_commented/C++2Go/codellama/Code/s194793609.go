package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n) // 1. Reading the input size `n`

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // 2. Reading the array elements
	}

	abs_a := make([]int, n)
	copy(abs_a, a) // 3. Creating a copy of the array with absolute values

	for i := 0; i < n; i++ {
		if abs_a[i] < 0 {
			abs_a[i] = -abs_a[i]
		}
	}

	ans := 0 // 4. Calculating the sum of absolute values
	min := abs_a[0]
	for _, e := range abs_a {
		ans += e
		if min > e {
			min = e
		}
	}

	num_negative := 0 // 5. Counting the number of negative elements
	for _, e := range a {
		if e < 0 {
			num_negative++
		}
	}

	if num_negative%2 != 0 { // 6. Adjusting the sum based on the number of negative elements
		ans -= min * 2
	}

	fmt.Println(ans) // 7. Outputting the result
}

