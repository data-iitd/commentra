
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	var n int
	fmt.Fscanf(r, "%d\n", &n)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(r, "%d", &a[i])
	}
	dp := make([]int64, n+1)
	for i := n - 1; i >= 0; i-- {
		dp[i] = max(dp[i+1], a[i])
	}
	for i := 0; i < n; i++ {
		if a[i] > dp[i+1] {
			fmt.Fprintf(w, "0 ")
		} else {
			fmt.Fprintf(w, "%d ", dp[i+1]-a[i]+1)
		}
	}
	fmt.Fprint(w, "\n")
	w.Flush()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// 