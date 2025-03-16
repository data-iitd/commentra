package main

import (
	"fmt"
	"math"
)

const INF = 1 << 29
const MOD = 1000000007

func main() {
	var n, c int64
	fmt.Scan(&n, &c)

	// Step 2: Slice Initialization
	x := make([]int64, n+1)
	v := make([]int64, n+1)

	// Step 3: Reading Positions and Values
	for i := int64(1); i <= n; i++ {
		fmt.Scan(&x[i], &v[i])
	}

	// Step 4: Calculate Total Value Moving Left
	lefttotal := make([]int64, n+1)
	maxlefttotal := make([]int64, n+1)
	for i := int64(1); i <= n; i++ {
		lefttotal[i] = lefttotal[i-1] + v[i]
	}

	// Step 5: Calculate Maximum Value Left
	for i := int64(1); i <= n; i++ {
		maxlefttotal[i] = int64(math.Max(float64(maxlefttotal[i-1]), float64(lefttotal[i]-x[i])))
	}

	// Step 6: Calculate Total Value Moving Right
	righttotal := make([]int64, n+1)
	maxrighttotal := make([]int64, n+1)
	for i := int64(1); i <= n; i++ {
		righttotal[i] = righttotal[i-1] + v[n-i+1]
	}

	// Step 7: Calculate Maximum Value Right
	for i := int64(1); i <= n; i++ {
		maxrighttotal[i] = int64(math.Max(float64(maxrighttotal[i-1]), float64(righttotal[i]-(c-x[n+1-i]))))
	}

	// Step 8: Calculate the Maximum Value
	ans := int64(0)
	for i := int64(1); i <= n; i++ {
		ans = int64(math.Max(float64(ans), float64(lefttotal[i]-x[i])))
		ans = int64(math.Max(float64(ans), float64(lefttotal[i]-2*x[i]+maxrighttotal[n-i])))
		ans = int64(math.Max(float64(ans), float64(righttotal[i]-(c-x[n+1-i]))))
		ans = int64(math.Max(float64(ans), float64(righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i])))
	}

	// Step 9: Output the Result
	fmt.Println(ans)
}

// <END-OF-CODE>
