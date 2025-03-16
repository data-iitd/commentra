package main

import (
	"fmt"
	"math"
)

const MOD = 1000000007 // Constants definition

func main() {
	var n, c int64 // Declare variables n and c for number of elements and capacity
	fmt.Scan(&n, &c) // Read input values for n and c from standard input

	x := make([]int64, n+1) // Declare and initialize slice x of size n+1
	v := make([]int64, n+1) // Declare and initialize slice v of size n+1

	for i := int64(1); i <= n; i++ { // Loop through each element in the array
		fmt.Scan(&x[i], &v[i]) // Read input values for x[i] and v[i] from standard input
	}

	// Calculate left prefix sums
	lefttotal := make([]int64, n+1)
	maxlefttotal := make([]int64, n+1)
	for i := int64(1); i <= n; i++ {
		lefttotal[i] = lefttotal[i-1] + v[i] // Calculate prefix sums of vector v
		maxlefttotal[i] = int64(math.Max(float64(maxlefttotal[i-1]), float64(lefttotal[i]-x[i]))) // Calculate maximum prefix sums excluding current element
	}

	// Calculate right prefix sums
	righttotal := make([]int64, n+1)
	maxrighttotal := make([]int64, n+1)
	for i := int64(1); i <= n; i++ {
		righttotal[i] = righttotal[i-1] + v[n-i+1] // Calculate prefix sums of reversed vector v
		maxrighttotal[i] = int64(math.Max(float64(maxrighttotal[i-1]), float64(righttotal[i]-(c-x[n+1-i])))) // Calculate maximum prefix sums excluding current element
	}

	// Calculate answer
	ans := int64(0)
	for i := int64(1); i <= n; i++ {
		ans = int64(math.Max(float64(ans), float64(lefttotal[i]-x[i]))) // Calculate maximum sum by including current element in left sum
		ans = int64(math.Max(float64(ans), float64(lefttotal[i]-2*x[i]+maxrighttotal[n-i]))) // Calculate maximum sum by excluding current element in left sum and including it in right sum
		ans = int64(math.Max(float64(ans), float64(righttotal[i]-(c-x[n+1-i])))) // Calculate maximum sum by including current element in right sum
		ans = int64(math.Max(float64(ans), float64(righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i]))) // Calculate maximum sum by excluding current element in right sum and including it in left sum
	}

	// Output answer
	fmt.Println(ans)
}

// <END-OF-CODE>
