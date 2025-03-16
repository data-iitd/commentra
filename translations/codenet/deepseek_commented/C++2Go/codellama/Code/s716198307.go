package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	var a [100]int
	var avg float64
	var s float64
	var ans int

	// Step 1: Input the number of elements (n) and the array elements (a[100])
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		avg += float64(a[i])
	}

	// Step 2: Calculate the average of the array elements
	avg /= float64(n)

	// Step 3: Find the element closest to the average
	s = math.Abs(float64(a[0]) - avg)
	ans = 0
	for i := 1; i < n; i++ {
		if s > math.Abs(float64(a[i])-avg) {
			s = math.Abs(float64(a[i]) - avg)
			ans = i
		}
	}

	// Step 4: Output the index of the closest element
	fmt.Println(ans)
}

