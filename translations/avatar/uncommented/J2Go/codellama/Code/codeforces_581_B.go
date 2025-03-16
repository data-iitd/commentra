
package main

import (
	"fmt"
	"math"
	"os"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	dp := make([]int, n+1)
	for i := n - 1; i >= 0; i-- {
		dp[i] = math.MaxInt32
	}
	dp[n-1] = a[n-1]
	for i := n - 1; i >= 0; i-- {
		dp[i] = int(math.Max(float64(dp[i+1]), float64(a[i])))
	}
	for i := 0; i < n; i++ {
		if a[i] > dp[i+1] {
			fmt.Printf("0 ")
		} else {
			fmt.Printf("%d ", dp[i+1]-a[i]+1)
		}
	}
	fmt.Println()
}

