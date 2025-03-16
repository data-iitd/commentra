package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
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

	var fractionalPart []float64
	for _, x := range arr {
		if x-float64(int(x)) != 0 {
			fractionalPart = append(fractionalPart, x-float64(int(x)))
		}
	}

	sort.Float64s(fractionalPart)
	o := 2*n - len(fractionalPart)
	arrSum := 0.0
	for _, x := range fractionalPart {
		arrSum += x
	}

	res := math.Pow(2, 19)
	for i := 0; i <= n; i++ {
		if i+o >= n {
			res = math.Min(res, math.Abs(float64(i)-arrSum))
		}
	}

	fmt.Printf("%.3f\n", res)
}

