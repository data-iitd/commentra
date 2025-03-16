package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func check(lis []int, k int, mid int) bool {
	// Initialize a loop to iterate through each element in the list
	for _, i := range lis {
		// If the current element is divisible by mid, increment k
		if i%mid == 0 {
			k++
		}
		// Decrease k by the number of times mid fits into the current element
		k -= (i / mid)
	}
	// Return true if k is non-negative, indicating the condition is satisfied
	return k >= 0
}

func main() {
	// Read input values for n (number of elements) and k (threshold value)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())
	// Read the list of integers
	lis := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		lis[i], _ = strconv.Atoi(scanner.Text())
	}

	// Initialize the binary search bounds
	a, b := 1, lis[0]
	for _, i := range lis {
		if i > b {
			b = i
		}
	}
	// Set the initial answer to the maximum value in the list
	ans := b

	// Perform binary search to find the optimal mid value
	for a <= b {
		// Calculate the mid value
		mid := (a + b) / 2
		// Check if the current mid value satisfies the condition using the check function
		if check(lis, k, mid) {
			// If it does, update the answer and narrow the search to the left half
			ans = mid
			b = mid - 1
		} else {
			// If it doesn't, narrow the search to the right half
			a = mid + 1
		}
	}

	// Print the final answer
	fmt.Println(ans)
}
