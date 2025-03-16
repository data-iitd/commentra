package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create an instance of Main and call the solve method to execute the program
	solve()
}

func solve() {
	// Initialize a Scanner to read input from the console
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	// Read the number of elements N and the multiplier X
	sc.Scan()
	N := toInt(sc.Text())
	sc.Scan()
	X := toInt64(sc.Text())

	// Initialize an array to store the elements and a prefix sum array
	x := make([]int64, N)
	xsum := make([]int64, N+1)

	// Read the elements into the array and compute the prefix sums
	for i := 0; i < N; i++ {
		sc.Scan()
		x[i] = toInt64(sc.Text())
		xsum[i+1] = xsum[i] + x[i]
	}

	// Initialize the answer with the cost of processing all elements with the base cost
	ans := X * int64(N) + 5 * xsum[N]

	// Iterate through possible splits of the array
	for i := 1; i < N; i++ {
		// Calculate the cost for the current split
		cost := X * int64(i) + 5 * (xsum[N] - xsum[N-i])

		// Incrementally add costs based on the current split
		for j, k := 5, N-i; k >= 0; j, k = j+2, k-i {
			// If the current cost exceeds the best answer found, break out of the loop
			if cost > ans {
				break
			}
			// Update the cost based on the prefix sums
			if k-i > 0 {
				cost += int64(j) * (xsum[k] - xsum[k-i])
			} else {
				cost += int64(j) * xsum[k]
			}
		}
		// Update the answer with the minimum cost found
		if cost < ans {
			ans = cost
		}
	}

	// Output the final answer, which includes the base cost
	fmt.Println(ans + int64(N)*X)
}

func toInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

func toInt64(s string) int64 {
	var res int64
	for _, c := range s {
		res = res*10 + int64(c-'0')
	}
	return res
}

