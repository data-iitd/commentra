package main

import (
	"fmt"
	"math"
)

func main() {
	// Step 1: Input Reading
	var n, c int
	fmt.Scan(&n, &c)

	// Step 2: Vector Initialization
	x := make([]int, n+1)
	v := make([]int, n+1)

	// Step 3: Reading Positions and Values
	for i := 1; i < n+1; i++ {
		fmt.Scan(&x[i], &v[i])
	}

	// Step 4: Calculate Total Value Moving Left
	lefttotal := make([]int, n+1)
	maxlefttotal := make([]int, n+1)
	for i := 1; i < n+1; i++ {
		lefttotal[i] = lefttotal[i-1] + v[i]
	}

	// Step 5: Calculate Maximum Value Left
	for i := 1; i < n+1; i++ {
		maxlefttotal[i] = int(math.Max(float64(maxlefttotal[i-1]), float64(lefttotal[i]-x[i])))
	}

	// Step 6: Calculate Total Value Moving Right
	righttotal := make([]int, n+1)
	maxrighttotal := make([]int, n+1)
	for i := 1; i < n+1; i++ {
		righttotal[i] = righttotal[i-1] + v[n-i+1]
	}

	// Step 7: Calculate Maximum Value Right
	for i := 1; i < n+1; i++ {
		maxrighttotal[i] = int(math.Max(float64(maxrighttotal[i-1]), float64(righttotal[i]-(c-x[n+1-i]))))
	}

	// Step 8: Calculate the Maximum Value
	ans := 0
	for i := 1; i < n+1; i++ {
		ans = int(math.Max(float64(ans), float64(lefttotal[i]-x[i])))
		ans = int(math.Max(float64(ans), float64(lefttotal[i]-2*x[i]+maxrighttotal[n-i])))
		ans = int(math.Max(float64(ans), float64(righttotal[i]-(c-x[n+1-i]))))
		ans = int(math.Max(float64(ans), float64(righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i])))
	}

	// Step 9: Output the Result
	fmt.Println(ans)
}

