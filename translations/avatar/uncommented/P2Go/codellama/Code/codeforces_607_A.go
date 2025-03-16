package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	l := make([]int, 1000010)
	dp := make([]int, 1000010)
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		l[a] = b
		if l[0] > 0 {
			dp[0] = 1
		}
		mx := 0
		for j := 1; j < 1000010; j++ {
			if l[j] == 0 {
				dp[j] = dp[j-1]
			} else {
				if l[j] >= j {
					dp[j] = 1
				} else {
					dp[j] = dp[j-l[j]-1] + 1
				}
			}
			if dp[j] > mx {
				mx = dp[j]
			}
		}
		fmt.Println(n - mx)
	}
}

