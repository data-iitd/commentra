package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read the number of intervals
	n, _ := strconv.Atoi(readLine())

	// Initialize lists to store the lower and upper bounds of the intervals
	low := make([]int, n)
	high := make([]int, n)

	// Read each interval and store the lower and upper bounds
	for i := 0; i < n; i++ {
		a, _ := strconv.Atoi(readLine())
		low[i] = a
		high[i] = a
	}

	// Sort the lower and upper bounds
	sort.Ints(low)
	sort.Ints(high)

	// Check if the number of intervals is odd
	if n % 2 == 1 {
		// For odd number of intervals, calculate the range of the median interval
		fmt.Println(high[(n+1)/2-1]-low[(n+1)/2-1]+1)
	} else {
		// For even number of intervals, calculate the average of the two middle values
		hh := (high[n/2-1] + high[n/2]) / 2
		ll := (low[n/2-1] + low[n/2]) / 2
		// Calculate the range and print the result
		fmt.Println(int((hh - ll) * 2) + 1)
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	str, _, _ := buf.ReadLine()
	return strings.TrimRight(string(str), "\r\n")
}

