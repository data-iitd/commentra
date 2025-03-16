package main

import "fmt"

func run() {
	var n, k int
	fmt.Scanf("%d%d", &n, &k)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	dp := make([]int, k+1)
	for i := 1; i <= k; i++ {
		win := 0
		for j := 0; j < n && a[j] <= i; j++ {
			if dp[i-a[j]] == 0 {
				win = 1
			}
		}
		dp[i] = win
	}
	fmt.Printf("%s\n", dp[k] == 0 ? "First" : "Second")
}

func main() {
	run()
}

