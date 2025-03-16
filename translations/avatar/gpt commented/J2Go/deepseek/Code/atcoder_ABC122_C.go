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
	
	// Read the number of characters (n) and the number of queries (q)
	sc.Scan()
	n := toInt(sc.Text())
	sc.Scan()
	q := toInt(sc.Text())
	
	// Read the character array from input
	sc.Scan()
	c := sc.Text()
	
	// Initialize a 2D slice to store the ranges for each query
	range_ := make([][]int, q)
	for i := 0; i < q; i++ {
		range_[i] = make([]int, 2)
		sc.Scan()
		range_[i][0] = toInt(sc.Text())
		sc.Scan()
		range_[i][1] = toInt(sc.Text())
	}
	
	// Initialize arrays to track fragments and cumulative sums
	frag := make([]int, n + 1)
	rui := make([]int, n + 1)
	
	// Loop through the character array to count occurrences of "AC"
	for i := 2; i <= n; i++ {
		// Check if the current and previous characters form "AC"
		if c[i - 2] == 'A' && c[i - 1] == 'C' {
			frag[i]++
		}
		// Update the cumulative sum of fragments
		rui[i] = rui[i - 1] + frag[i]
	}
	
	// Process each query to find the number of "AC" in the specified range
	for i := 0; i < q; i++ {
		left := range_[i][0]
		right := range_[i][1]
		
		// Calculate and print the result for the current query
		fmt.Println(rui[right] - rui[left])
	}
}

// Helper function to convert string to integer
func toInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

