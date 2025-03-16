package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables
var (
	n int
	k int
)

// Function to check if the number of days needed to cut the logs of given length is greater than or equal to k
func nei(mid int, logsLength []int, k int) bool {
	daysNeeded := 0
	for _, log := range logsLength {
		daysNeeded += (log + mid - 1) / mid
		k -= daysNeeded
		if k < 0 {
			return false
		}
	}
	return true
}

// Function to find the minimum day such that the number of days needed to cut the logs is greater than or equal to k
func binarySearch(logsLength []int, k int) int {
	min := 1
	max := 1e9 + 1000
	for min < max {
		mid := (min + max) / 2
		if nei(mid, logsLength, k) {
			max = mid
		} else {
			min = mid + 1
		}
	}
	return min
}

// Function to read input from stdin
func readInput() {
	// Read the number of logs
	fmt.Scanf("%d", &n)

	// Read the number of days
	fmt.Scanf("%d", &k)

	// Read the length of each log
	logsLength := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &logsLength[i])
	}
}

// Function to print output to stdout
func printOutput(min int) {
	// Print the minimum day as the output
	fmt.Printf("%d\n", min)
}

// Main function
func main() {
	readInput()
	min := binarySearch(logsLength, k)
	printOutput(min)
}

// 