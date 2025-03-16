package main

import (
	"bufio"
	"fmt"
	"os"
)

const mod = 1000000007

func main() {
	// Create a Scanner object to read input
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	// Read the length of the string and the number of queries
	sc.Scan()
	n := toInt(sc.Bytes())
	sc.Scan()
	q := toInt(sc.Bytes())

	// Read the string as a byte slice
	sc.Scan()
	c := sc.Bytes()

	// Read the ranges for the queries and store them in a 2D slice
	range_ := make([][2]int, q)
	for i := 0; i < q; i++ {
		sc.Scan()
		range_[i][0] = toInt(sc.Bytes())
		sc.Scan()
		range_[i][1] = toInt(sc.Bytes())
	}

	// Initialize arrays to count "AC" fragments and store cumulative sums
	frag := make([]int, n+1)
	rui := make([]int, n+1)

	// Process the string to find "AC" fragments
	for i := 2; i <= n; i++ {
		if c[i-2] == 'A' && c[i-1] == 'C' {
			// Increment the count of "AC" fragments at position i
			frag[i]++
		}
		// Update the cumulative sum array
		rui[i] = rui[i-1] + frag[i]
	}

	// Process the queries
	for i := 0; i < q; i++ {
		left := range_[i][0]
		right := range_[i][1]
		// Calculate the number of "AC" fragments in the given range
		fmt.Println(rui[right] - rui[left])
	}
}

// Helper function to convert byte slice to int
func toInt(b []byte) int {
	var num int
	for _, v := range b {
		num = num*10 + int(v-'0')
	}
	return num
}

