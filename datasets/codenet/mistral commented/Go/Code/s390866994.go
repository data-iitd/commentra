
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func out(x ...interface{}) {
	fmt.Println(x...)
}

// Initialize scanner
var sc = bufio.NewScanner(os.Stdin)

// Function to read an integer from standard input
func getInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

// Function to read a string from standard input
func getString() string {
	sc.Scan()
	return sc.Text()
}

// Function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Function to find the absolute value of an integer
func abs(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}

// Main function
func main() {
	// Initialize scanner and read input
	sc.Split(bufio.ScanWords)

	// Read input: N, C, K
	N, C, K := getInt(), getInt(), getInt()

	// Initialize array t of size N
	t := make([]int, N)

	// Read input: t[i] for i from 0 to N-1
	for i := 0; i < N; i++ {
		t[i] = getInt()
	}

	// Sort array t in ascending order
	sort.Ints(t)

	// Initialize variables: answer counter ans, counter cnt, and end index end
	ans := 1
	cnt := 1
	end := t[0] + K

	// Iterate through array t from index 1 to N-1
	for i := 1; i < N; i++ {
		// If counter cnt is less than C and current element t[i] is within the range [end, end+K], increment counter cnt
		if cnt < C && t[i] <= end {
			cnt++
		} else {
			// Reset counter cnt and update end index end to the current element t[i] plus K
			cnt = 1
			end = t[i] + K
			// Increment answer counter ans
			ans++
		}
	}

	// Print the final answer
	out(ans)

