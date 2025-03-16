package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	arr := make([]float64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	var fractionalParts []float64
	for _, x := range arr {
		fractionalPart := x - float64(int(x))
		if fractionalPart != 0 {
			fractionalParts = append(fractionalParts, fractionalPart)
		}
	}

	sort.Float64s(fractionalParts)
	o := 2*n - len(fractionalParts)
	arrSum := 0.0
	for _, x := range fractionalParts {
		arrSum += x
	}

	res := 2e9
	for i := 0; i <= n; i++ {
		if i+o >= n {
			res = int(math.Min(float64(res), math.Abs(float64(i)-arrSum)))
		}
	}

	fmt.Printf("%.3f\n", float64(res))
}

// <END-OF-CODE>
