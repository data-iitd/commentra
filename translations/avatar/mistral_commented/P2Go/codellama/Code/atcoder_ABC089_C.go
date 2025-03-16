// Import necessary libraries and modules
package main

import (
	"fmt"
	"math"
	"strings"
)

// Define constants and global variables
const (
	INF = 1000000000 + 7
	mod = 1000000007
)

var (
	N     int
	S     []string
	march = []string{"M", "A", "R", "C", "H"}
	marchLis = []int{0, 0, 0, 0, 0}
	ans   int
)

// Define functions if any
// Function to read input as integer
func input() int {
	var n int
	fmt.Scan(&n)
	return n
}

// Function to read input as list of integers
func LIST() []int {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	return arr
}

// Function to read input as list of integers with given number of inputs
func ZIP(n int) [][]int {
	arr := make([][]int, n)
	for i := 0; i < n; i++ {
		arr[i] = LIST()
	}
	return arr
}

// Set recursion limit
func setRecursionLimit(n int) {
	var rlimit int
	rlimit = n
	if rlimit > 1000 {
		rlimit = 1000
	}
	var rlim runtime.MemStats
	runtime.ReadMemStats(&rlim)
	if rlim.NumGC > rlimit {
		runtime.GC()
	}
}

// Main logic of the code
func main() {
	// Initialize march_lis with zeros
	marchLis = []int{0, 0, 0, 0, 0}
	// Iterate through each string in S and increment the count of the corresponding marching order in march_lis
	for _, s := range S {
		if strings.Contains(s, march[0]) {
			marchLis[0]++
		} else if strings.Contains(s, march[1]) {
			marchLis[1]++
		} else if strings.Contains(s, march[2]) {
			marchLis[2]++
		} else if strings.Contains(s, march[3]) {
			marchLis[3]++
		} else if strings.Contains(s, march[4]) {
			marchLis[4]++
		}
	}
	// Calculate the answer by finding the triple product of the counts of each marching order
	for _, x := range marchLis {
		for _, y := range marchLis {
			for _, z := range marchLis {
				ans += x * y * z
			}
		}
	}
	// Print the answer
	fmt.Println(ans)
}

// 