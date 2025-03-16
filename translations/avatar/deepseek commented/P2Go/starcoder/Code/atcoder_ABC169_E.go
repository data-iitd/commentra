package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read the number of pairs
	n, _ := strconv.Atoi(strings.TrimSpace(string(readLine())))

	// Initialize lists to store the lower and higher values of each pair
	low := make([]int, n)
	high := make([]int, n)

	// Loop to read each pair and append values to the lists
	for i := 0; i < n; i++ {
		a, _ := strconv.Atoi(strings.TrimSpace(string(readLine())))
		low[i], high[i] = a, a
	}

	// Sort the lists
	sort.Ints(low)
	sort.Ints(high)

	// Check if the number of pairs is odd or even
	if n%2 == 1 {
		// If odd, calculate the range between the middle elements
		fmt.Println(high[(n+1)/2-1]-low[(n+1)/2-1]+1)
	} else {
		// If even, calculate the average of the middle elements and print the range
		hh := (high[(n)/2-1] + high[(n)/2]) / 2
		ll := (low[(n)/2-1] + low[(n)/2]) / 2
		fmt.Println(int((hh-ll)*2) + 1)
	}
}

// 