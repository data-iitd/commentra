
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initial_v = 10000
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	h := make([]int, n)
	dp := make([]int, n)
	for i := 0; i < n; i++ {
		dp[i] = initial_v
	}
	for i := 0; i < n; i++ {
		scanner.Scan()
		h[i], _ = strconv.Atoi(scanner.Text())
	}
	dp[0] = 0
	for i := 1; i < n; i++ {
		if i == 1 {
			dp[1] = abs(h[1]-h[0])
		} else {
			dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]))
		}
	}
	fmt.Println(dp[n-1])
}

func min(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	} else {
		return x
	}
}

