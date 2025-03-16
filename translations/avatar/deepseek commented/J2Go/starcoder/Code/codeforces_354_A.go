package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	var N, L, R, QL, QR int
	var W []int
	var sum []int
	var min int64
	var firstR int
	var lCount, rCount, llCount, rrCount int
	var cand int64

	// Reading the number of items
	N, _ = strconv.Atoi(readLine(in))

	// Reading the cost coefficient for items
	L, _ = strconv.Atoi(readLine(in))

	// Reading the cost coefficient for items
	R, _ = strconv.Atoi(readLine(in))

	// Reading the cost coefficient for unbalanced left count
	QL, _ = strconv.Atoi(readLine(in))

	// Reading the cost coefficient for unbalanced right count
	QR, _ = strconv.Atoi(readLine(in))

	// Array to store the weights of items
	W = make([]int, N)

	// Array to store cumulative sums of weights
	sum = make([]int, N+1)

	// Reading the weights and calculating cumulative sums
	for n := 0; n < N; n++ {
		W[n], _ = strconv.Atoi(readLine(in))
		sum[n+1] = sum[n] + W[n]
	}

	// Initializing the minimum cost to a very large value
	min = int64(1e18)

	// Iterating over possible positions for the rightmost item
	for firstR = 0; firstR <= N; firstR++ {
		lCount = firstR
		rCount = N - lCount

		// Calculating the cost for the current position of the rightmost item
		cand = int64(sum[lCount] * L + (sum[N] - sum[lCount]) * R)

		// Calculating the additional costs for unbalanced counts
		llCount = int(math.Max(0, float64(lCount - rCount - 1)))
		rrCount = int(math.Max(0, float64(rCount - lCount - 1)))
		cand += int64(llCount * QL)
		cand += int64(rrCount * QR)

		// Updating the minimum cost found so far
		min = int64(math.Min(float64(cand), float64(min)))
	}

	// Printing the minimum cost
	fmt.Println(min)
}

func readLine(in *bufio.Reader) string {
	str, _, _ := in.ReadLine()
	return strings.TrimRight(string(str), "\r\n")
}

