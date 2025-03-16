
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
		n, max int
		beacon [1000001]int
		dp     [1000001]int
	)

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)

	for i := 0; i < n; i++ {
		var a int
		fmt.Fscan(reader, &a)
		beacon[a], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}

	if beacon[0]!= 0 {
		dp[0] = 1
	}

	for i := 1; i < 1000001; i++ {
		if beacon[i]!= 0 && beacon[i] < i {
			dp[i] = dp[i-beacon[i]-1] + 1
		} else if beacon[i]!= 0 {
			dp[i] = 1
		} else {
			dp[i] = dp[i-1]
		}
		max = max(max, dp[i])
	}

	fmt.Println(n - max)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

