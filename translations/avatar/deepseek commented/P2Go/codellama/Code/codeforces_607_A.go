
package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	l := make([]int, 1000010)
	dp := make([]int, 1000010)

	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
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

	fmt.Println(n - mx)
}

