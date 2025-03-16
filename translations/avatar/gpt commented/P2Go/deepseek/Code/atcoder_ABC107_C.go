package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read two integers N and K from input
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	N, _ := strconv.Atoi(parts[0])
	K, _ := strconv.Atoi(parts[1])

	// Read a list of integers from input
	input, _ = reader.ReadString('\n')
	lstStr := strings.Split(strings.TrimSpace(input), " ")
	lst := make([]int, N)
	for i := 0; i < N; i++ {
		lst[i], _ = strconv.Atoi(lstStr[i])
	}

	// Initialize lists to hold positive and negative numbers
	lst_p := []int{}
	lst_m := []int{}

	// Iterate through the list to categorize numbers
	for i := 0; i < N; i++ {
		// Decrease K for each zero encountered
		if lst[i] == 0 {
			K--
		}
		// Add positive numbers to lst_p
		if lst[i] > 0 {
			lst_p = append(lst_p, lst[i])
		}
		// Add negative numbers to lst_m
		else if lst[i] < 0 {
			lst_m = append(lst_m, lst[i])
		}
	}

	// Initialize variables to track the last indices of positive and negative lists
	p := 0
	m := 0
	x, y := 0, len(lst_m) - 1
	lastx := len(lst_p)
	lasty := len(lst_m)

	// Define a function to check the minimum value based on K
	check := func(k int) int {
		ans := 1000000000 // Initialize answer with a large number
		// Iterate through possible counts of positive numbers used
		for j := 0; j <= k; j++ {
			// Check if the current count of positives and negatives is valid
			if j > lastx || k-j > lasty {
				continue // Skip invalid combinations
			} else {
				// Determine the maximum positive number used
				if j == 0 {
					p = 0 // No positive numbers used
				} else {
					p = lst_p[j-1] // Get the largest positive number used
				}

				// Determine the maximum negative number used
				if k-j == 0 {
					m = 0 // No negative numbers used
				} else {
					m = lst_m[lasty-(k-j)] // Get the largest negative number used
				}

				// Calculate the minimum value based on the current combination
				ans = min(ans, 2*p+abs(m), p+2*abs(m))
			}
		}
		return ans // Return the minimum value found
	}

	// Print the result of the check function with K
	fmt.Println(check(K))
}

func min(a, b, c int) int {
	if a < b {
		if a < c {
			return a
		}
	} else {
		if b < c {
			return b
		}
	}
	return c
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
