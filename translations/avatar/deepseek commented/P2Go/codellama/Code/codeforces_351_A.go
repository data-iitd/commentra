
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

	// Extract fractional parts and sort them
	arr = arr[:0]
	for _, v := range arr {
		if v-math.Floor(v) != 0 {
			arr = append(arr, v-math.Floor(v))
		}
	}
	sort.Float64s(arr)

	// Calculate the number of elements to be added to make the total number of elements equal to 2 * n
	o := 2*n - len(arr)

	// Sum of the sorted fractional parts
	arr_sum := 0.0
	for _, v := range arr {
		arr_sum += v
	}

	// Initialize the result variable to a very large number
	res := 2e9

	// Iterate to find the best position
	for i := 0; i < n+1; i++ {
		if i+o >= n {
			res = math.Min(res, math.Abs(float64(i)-arr_sum))
		}
	}

	// Print the result with three decimal places
	fmt.Printf("%.3f\n", res)
}

