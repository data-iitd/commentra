package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements
	n, _ := strconv.Atoi(readLine(os.Stdin))
	// Calculate the target value m based on the number of elements
	m := n * (n + 1) / 4
	// Read the input array and convert it to a list of integers
	a := strings.Split(readLine(os.Stdin), " ")
	d := make(map[int]int)
	// Create a sorted list of unique values from a, including 0
	_a := make([]int, 0)
	for _, x := range a {
		_a = append(_a, x)
	}
	_a = append(_a, 0)
	// Map original values to their indices in the sorted list
	for i, x := range _a {
		d[x] = i
	}
	// Replace original values in a with their corresponding indices
	for i, x := range a {
		a[i] = d[x]
	}
	// Function to check if a certain value X can be achieved
	check := func(X int) bool {
		// Create a new list b where each element indicates if the corresponding a[i] is >= X
		b := make([]int, len(a)+1)
		for i, x := range a {
			if x >= X {
				b[i+1] = 2
			} else {
				b[i+1] = -1
			}
		}
		// Calculate the prefix sums of b
		for i := 1; i < len(b); i++ {
			b[i] += b[i-1]
		}
		c := min(b) // Find the minimum value in b
		for i := 1; i < len(b); i++ {
			b[i] -= c
		}
		bit := make([]int, max(b)+2) // Initialize a BIT for the range of b
		ans := 0                     // Initialize the answer counter
		// Count the number of valid pairs using the BIT
		for _, x := range b {
			ans += bit[x+1]
			bit[x+1]++
		}
		return ans >= m // Return whether the count is at least m
	}
	// Initialize the binary search bounds
	t := []int{len(_a), 0}
	// Perform binary search to find the maximum value that satisfies the condition
	for t[0]-t[1] > 1 {
		mid := (t[0] + t[1]) / 2 // Calculate the midpoint
		t[check(mid)] = mid      // Update the bounds based on the check function
	}
	// Print the result corresponding to the found index
	fmt.Println(_a[t[1]])
}

func readLine(file *os.File) string {
	reader := bufio.NewReader(file)
	var text []byte
	var isPrefix bool = true
	for isPrefix && len(text) < 1024 {
		var buf [128]byte
		n, err := reader.Read(buf[0:])
		isPrefix = err == nil && n > 0
		text = append(text, buf[0:n]...)
	}
	return string(text)
}

func min(a []int) int {
	min := a[0]
	for _, x := range a {
		if x < min {
			min = x
		}
	}
	return min
}

func max(a []int) int {
	max := a[0]
	for _, x := range a {
		if x > max {
			max = x
		}
	}
	return max
}

// 