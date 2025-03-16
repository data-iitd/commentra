package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	// Initialize a 2D array to count occurrences of digit pairs
	var cnt [10][10]int

	// Count occurrences of digit pairs (first digit, last digit) for numbers from 1 to n
	for i := 1; i <= n; i++ {
		b := i % 10
		a := i
		for a >= 10 {
			a /= 10
		}
		cnt[a][b]++
	}

	var ans int64

	// Calculate the total number of valid pairs by multiplying counts
	for i := 1; i <= 9; i++ {
		for j := 1; j <= 9; j++ {
			ans += int64(cnt[i][j]) * int64(cnt[j][i])
		}
	}

	fmt.Println(ans)
}

