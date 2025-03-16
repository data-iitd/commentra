package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n) // 1. Reading the input size `n`

	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // 2. Reading the array elements
	}

	absA := make([]int64, n) // 3. Creating a copy of the array with absolute values
	for i := 0; i < n; i++ {
		absA[i] = int64(math.Abs(float64(a[i])))
	}

	ans := int64(0) // 4. Calculating the sum of absolute values
	min := absA[0]
	for _, e := range absA {
		ans += e
		if min > e {
			min = e
		}
	}

	numNegative := 0 // 5. Counting the number of negative elements
	for _, e := range a {
		if e < 0 {
			numNegative++
		}
	}

	if numNegative%2 != 0 { // 6. Adjusting the sum based on the number of negative elements
		ans -= min * 2
	}

	fmt.Println(ans) // 7. Outputting the result
}

// <END-OF-CODE>
