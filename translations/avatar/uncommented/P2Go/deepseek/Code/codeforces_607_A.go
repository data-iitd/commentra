package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	l := make([]int, 1000010)
	dp := make([]int, 1000010)

	for i := 0; i < n; i++ {
		var a, b int
		fmt.Fscan(reader, &a, &b)
		l[a] = b
	}

	if l[0] > 0 {
		dp[0] = 1
	}

	mx := 0
	for i := 1; i < 1000010; i++ {
		if l[i] == 0 {
			dp[i] = dp[i-1]
		} else {
			if l[i] >= i {
				dp[i] = 1
			} else {
				dp[i] = dp[i-l[i]-1] + 1
			}
		}
		if dp[i] > mx {
			mx = dp[i]
		}
	}

	fmt.Fprintln(writer, n-mx)
}

