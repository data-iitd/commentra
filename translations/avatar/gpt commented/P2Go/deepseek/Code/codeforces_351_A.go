package main

import (
	"fmt"
	"sort"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	var arr []float64
	for i := 0; i < n; i++ {
		var x float64
		fmt.Scan(&x)
		arr = append(arr, x)
	}

	var fractionalParts []float64
	for _, x := range arr {
		if math.Floor(x) != x {
			fractionalParts = append(fractionalParts, x - math.Floor(x))
		}
	}

	sort.Float64s(fractionalParts)

	o := 2 * n - len(fractionalParts)
	arrSum := 0.0
	for _, x := range fractionalParts {
		arrSum += x
	}

	res := int(2e9)
	for i := 0; i <= n; i++ {
		if i + o >= n {
			res = int(math.Min(float64(res), math.Abs(float64(i - arrSum))))
		}
	}

	fmt.Printf("%.3f\n", float64(res))
}
