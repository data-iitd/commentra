package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)

	var N, L, R, QL, QR int
	var W []int
	var sum []int

	// Reading the number of items
	in.Scan()
	fmt.Sscan(in.Text(), &N)

	// Reading the cost coefficients
	in.Scan()
	fmt.Sscan(in.Text(), &L)
	in.Scan()
	fmt.Sscan(in.Text(), &R)
	in.Scan()
	fmt.Sscan(in.Text(), &QL)
	in.Scan()
	fmt.Sscan(in.Text(), &QR)

	// Initializing the arrays
	W = make([]int, N)
	sum = make([]int, N+1)

	// Reading the weights and calculating cumulative sums
	for n := 0; n < N; n++ {
		in.Scan()
		fmt.Sscan(in.Text(), &W[n])
		sum[n+1] = sum[n] + W[n]
	}

	// Initializing the minimum cost to a very large value
	min := int(^uint(0) >> 1)

	// Iterating over possible positions for the rightmost item
	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR
		rCount := N - lCount

		// Calculating the cost for the current position of the rightmost item
		cand := sum[lCount]*L + (sum[N]-sum[lCount])*R

		// Calculating the additional costs for unbalanced counts
		llCount := max(0, lCount-rCount-1)
		rrCount := max(0, rCount-lCount-1)
		cand += llCount * QL
		cand += rrCount * QR

		// Updating the minimum cost found so far
		if cand < min {
			min = cand
		}
	}

	// Printing the minimum cost
	fmt.Println(min)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

