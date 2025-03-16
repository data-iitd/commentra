package main

import (
	"fmt"
	"math"
)

func main() {
	var n, c int // Declare variables n and c for number of elements and capacity
	fmt.Scan(&n, &c) // Read input values for n and c from standard input

	x := make([]int, n+1) // Declare and initialize two arrays x and v of size n+1 with zero values
	v := make([]int, n+1)

	for i := 1; i < n+1; i++ { // Loop through each element in the array
		fmt.Scan(&x[i], &v[i]) // Read input values for x[i] and v[i] from standard input
	}

	// Calculate left prefix sums
	lefttotal := make([]int, n+1)
	maxlefttotal := make([]int, n+1)
	for i := 1; i < n+1; i++ {
		lefttotal[i] = lefttotal[i-1] + v[i] // Calculate prefix sums of vector v
		maxlefttotal[i] = int(math.Max(float64(maxlefttotal[i-1]), float64(lefttotal[i]-x[i]))) // Calculate maximum prefix sums excluding current element
	}

	// Calculate right prefix sums
	righttotal := make([]int, n+1)
	maxrighttotal := make([]int, n+1)
	for i := 1; i < n+1; i++ {
		righttotal[i] = righttotal[i-1] + v[n-i+1] // Calculate prefix sums of reversed vector v
		maxrighttotal[i] = int(math.Max(float64(maxrighttotal[i-1]), float64(righttotal[i]-(c-x[n+1-i])))) // Calculate maximum prefix sums excluding current element
	}

	// Calculate answer
	ans := 0
	for i := 1; i < n+1; i++ {
		ans = int(math.Max(float64(ans), float64(lefttotal[i]-x[i]))) // Calculate maximum sum by including current element in left sum
		ans = int(math.Max(float64(ans), float64(lefttotal[i]-2*x[i]+maxrighttotal[n-i]))) // Calculate maximum sum by excluding current element in left sum and including it in right sum
		ans = int(math.Max(float64(ans), float64(righttotal[i]-(c-x[n+1-i])))) // Calculate maximum sum by including current element in right sum
		ans = int(math.Max(float64(ans), float64(righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i]))) // Calculate maximum sum by excluding current element in right sum and including it in left sum
	}

	// Output answer
	fmt.Println(ans)
}

