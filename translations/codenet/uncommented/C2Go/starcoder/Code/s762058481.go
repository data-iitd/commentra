package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	n, _ := strconv.Atoi(os.Args[1])
	h := make([]int, n)
	for i := 0; i < n; i++ {
		h[i], _ = strconv.Atoi(os.Args[i + 2])
	}
	dp := make([]int, n)
	dp[0] = 0
	for i := 1; i < n; i++ {
		if i == 1 {
			dp[1] = int(math.Abs(float64(h[1] - h[0])))
		} else {
			dp[i] = int(math.Min(float64(dp[i-1] + int(math.Abs(float64(h[i] - h[i-1])))), float64(dp[i-2] + int(math.Abs(float64(h[i] - h[i-2]))))))
		}
	}
	fmt.Println(dp[n-1])
}

