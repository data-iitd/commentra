
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Initialize answer variable to 0
var ans int64 = 0

// Function to calculate the sum of digits from position 'a' to the end
func get(a int64) int64 {
	ret := int64(0) // Initialize result to 0
	now := int64(1) // Initialize current position to 1
	t := int64(1)   // Initialize multiplier to 1
	for {
		// Calculate the sum of digits from current position to the end
		if now*10 > a {
			ret += (a - now + 1) * t // Add the sum of digits from current position to the end
			break
		}
		ret += now*9*t // Add the sum of digits from current position to the next position
		now *= 10      // Move to the next position
		t++            // Increment the multiplier
	}
	return ret // Return the sum of digits
}

// Binary search function to find the position of the number that satisfies the condition
func binarySearch(k, l, r, x int64) int64 {
	// Base case: if the search range is empty, return -1
	if r >= l {
		mid := l + (r-l)/2 // Calculate the middle index
		// Check if the middle index is the answer and if it satisfies the condition
		if mid > ans && mid*k <= x {
			ans = mid // Update the answer if it satisfies the condition
		}

		// Check if the middle index is the answer
		if k*mid == x {
			return mid // Return the answer if it is the answer
		}

		// Recursively search in the left subtree if the condition is not satisfied
		if k*mid > x {
			return binarySearch(k, l, mid-1, x)
		}

		// Recursively search in the right subtree if the condition is not satisfied
		return binarySearch(k, mid+1, r, x)
	}

	// Base case: if the search range is empty, return -1
	return -1
}

// Initialize input and output streams
var br = bufio.NewReader(os.Stdin)
var pw = bufio.NewWriter(os.Stdout)

// Main function to read input and calculate the answer
func main() {
	// Read input
	gen, _ := strconv.ParseInt(readLine(), 10, 64)
	st, _ := strconv.ParseInt(readLine(), 10, 64)
	tim, _ := strconv.ParseInt(readLine(), 10, 64)
	gen /= tim // Calculate the number of generations per second
	beg := st - 1
	end := int64(math.Pow(10, 18)) // Initialize the search range
	// Binary search to find the position of the number that satisfies the condition
	for {
		med := (beg + end) / 2 + 1 // Calculate the middle index
		if get(med) - get(st-1) > gen { // Check if the middle index generates more digits than the given limit
			end = med - 1 // Narrow the search range to the left if it generates more digits
		} else {
			beg = med // Narrow the search range to the right if it generates less digits
		}
		if beg == end { // Check if the search range is empty
			fmt.Println(beg - st + 1) // Print the answer if the search range is empty
			break
		}
	}
}

// Read input from stdin
func readLine() string {
	buf := make([]byte, 0, 1024)
	for {
		line, isPrefix, err := br.ReadLine()
		if err!= nil {
			panic(err)
		}
		buf = append(buf, line...)
		if!isPrefix {
			break
		}
	}
	return strings.TrimSpace(string(buf))
}

