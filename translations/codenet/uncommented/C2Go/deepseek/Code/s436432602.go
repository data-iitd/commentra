package main

import (
	"bufio"
	"fmt"
	"os"
)

func run() {
	var n, k int
	fmt.Scan(&n, &k)
	a := make([]int, 100)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
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
	if dp[k] == 1 {
		fmt.Println("First")
	} else {
		fmt.Println("Second")
	}
}

func main() {
	run()
}

