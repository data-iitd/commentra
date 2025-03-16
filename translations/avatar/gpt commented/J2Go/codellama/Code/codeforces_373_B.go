package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

// Variable to store the maximum answer found during the binary search
var ans int64

// Function to calculate the number of integers with digits less than or equal to 'a'
func get(a int64) int64 {
	var ret int64 // Variable to accumulate the result
	var now int64 // Current base (1, 10, 100, ...)
	var t int64   // Digit count (1 for single digits, 2 for double digits, etc.)

	// Infinite loop to calculate the count of numbers
	for {
		// If the next base exceeds 'a', calculate the remaining numbers
		if now*10 > a {
			ret += (a - now + 1) * t // Add the count of remaining numbers
			break                    // Exit the loop
		}
		// Add the count of numbers for the current base
		ret += now * 9 * t // 9 options for each digit place
		now *= 10           // Move to the next base (10, 100, ...)
		t++                 // Increment the digit count
	}
	return ret // Return the total count
}

// Function to perform binary search to find the maximum value of 'mid'
// such that k * mid <= x
func binarySearch(k, l, r, x int64) int64 {
	// Check if the search range is valid
	if r >= l {
		mid := l + (r-l)/2 // Calculate the mid-point

		// Update the answer if mid is a valid candidate
		if mid > ans && mid*k <= x {
			ans = mid
		}

		// If mid is the exact solution, return it
		if k*mid == x {
			return mid
		}

		// If mid * k is greater than x, search in the left half
		if k*mid > x {
			return binarySearch(k, l, mid-1, x)
		}

		// Otherwise, search in the right half
		return binarySearch(k, mid+1, r, x)
	}

	return -1 // Return -1 if no valid mid is found
}

// BufferedReader for fast input and PrintWriter for fast output
var br *bufio.Reader
var pw *bufio.Writer

func main() {
	// Scanner to read input values
	S := bufio.NewScanner(os.Stdin)
	var gen, st, tim int64

	// Read the input values
	S.Scan()
	gen, _ = strconv.ParseInt(S.Text(), 10, 64) // Total generation count
	S.Scan()
	st, _ = strconv.ParseInt(S.Text(), 10, 64)  // Starting number
	S.Scan()
	tim, _ = strconv.ParseInt(S.Text(), 10, 64) // Time factor

	// Calculate the effective generation count per time unit
	gen /= tim

	// Initialize the binary search range
	beg, end := st-1, int64(math.Pow(10, 18))

	// Perform binary search to find the maximum valid number
	for {
		mid := (beg + end) / 2 + 1 // Calculate the midpoint

		// Check if the count of numbers from st to mid exceeds gen
		if get(mid) - get(st-1) > gen {
			end = mid - 1 // Adjust the end of the search range
		} else {
			beg = mid // Adjust the beginning of the search range
		}

		// If the search range converges, print the result
		if beg == end {
			fmt.Println(beg - st + 1) // Output the count of valid numbers
			break                     // Exit the loop
		}
	}
}

