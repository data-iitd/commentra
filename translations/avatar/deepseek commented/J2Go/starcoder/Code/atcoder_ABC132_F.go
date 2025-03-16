package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		n, k int
		l, r int
	)

	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &n, &k)

	// Initialize the len array
	len := make([]int, 0)
	l = 1
	for l <= n {
		r = n / (n / l)
		len = append(len, r-l+1)
		l = r + 1
	}

	// Initialize the dp array
	dp := make([]int, k*(len(len)+1))

	// Calculate the prefix sums of the lengths and store them in the dp array
	for j := 1; j <= len(len); j++ {
		dp[j] = len[j-1] + dp[j-1]
	}

	// Main loop to calculate the dynamic programming values for k iterations
	for i := 1; i < k; i++ {
		for j := 1; j <= len(len); j++ {
			dp[i*(len(len)+1)+j] = dp[i*(len(len)+1)+j-1] + dp[(i-1)*(len(len)+1)+len(len)-j+1] * len[j-1]
			dp[i*(len(len)+1)+j] %= 1000000007
		}
	}

	// Print the result stored in the dp array
	fmt.Println(dp[k*(len(len)+1)-1])
}

