package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to check if it is possible to distribute weights
func check(n, wei int, book []int) bool {
	tmp := wei // Temporary variable to hold the remaining weight
	n-- // Decrease the number of available books by one
	for i := 0; i < len(book); i++ {
		// If the current weight exceeds the available weight
		if tmp < book[i] {
			// If there are still books left to use
			if n > 0 {
				n-- // Use one book
				tmp = wei // Reset the temporary weight to the original weight
				// Check again if the current weight exceeds the available weight
				if tmp < book[i] {
					return false // Not possible to distribute
				}
			} else {
				return false // No books left to use
			}
		}
		// Deduct the current book's weight from the temporary weight
		tmp -= book[i]
	}
	return true // Successfully distributed the weights
}

func main() {
	in := bufio.NewScanner(os.Stdin)
	for in.Scan() {
		m, _ := strconv.Atoi(in.Text())
		in.Scan()
		n, _ := strconv.Atoi(in.Text())
		if m == 0 {
			break
		}

		book := []int{} // Slice to store the weights of the books
		// Read the weights of the books
		for i := 0; i < n; i++ {
			in.Scan()
			tmp, _ := strconv.Atoi(in.Text()) // Read each book's weight
			book = append(book, tmp) // Add weight to the slice
		}

		l := 0 // Lower bound for binary search
		r := 1500000 // Upper bound for binary search
		ans := 0 // Variable to store the answer
		// Perform binary search to find the maximum weight that can be distributed
		for l < r {
			// Check if the middle weight can be distributed
			if check(m, (l+r)/2, book) {
				ans = (l + r) / 2 // Update answer
				// If the upper bound equals the middle, break the loop
				if r == (l+r)/2 {
					break
				}
				r = (l + r) / 2 // Move the upper bound down
			} else {
				// If the lower bound equals the middle, break the loop
				if l == (l+r)/2 {
					break
				}
				l = (l + r) / 2 // Move the lower bound up
			}
		}
		fmt.Println(ans) // Output the maximum weight that can be distributed
	}
}

