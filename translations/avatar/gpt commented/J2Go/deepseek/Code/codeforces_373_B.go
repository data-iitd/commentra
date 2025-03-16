package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

// Variable to store the maximum answer found during the binary search
var ans int64 = 0

// Function to calculate the number of integers with digits less than or equal to 'a'
func get(a int64) int64 {
	var ret int64 = 0
	var now int64 = 1
	var t int64 = 1
	
	// Infinite loop to calculate the count of numbers
	for {
		// If the next base exceeds 'a', calculate the remaining numbers
		if now * 10 > a {
			ret += (a - now + 1) * t
			break
		}
		// Add the count of numbers for the current base
		ret += now * 9 * t
		now *= 10
		t++
	}
	return ret
}

// Function to perform binary search to find the maximum value of 'mid' 
// such that k * mid <= x
func binarySearch(k, l, r, x int64) int64 {
	// Check if the search range is valid
	if r >= l {
		mid := l + (r - l) / 2
		
		// Update the answer if mid is a valid candidate
		if mid > ans && mid * k <= x {
			ans = mid
		}
		
		// If mid is the exact solution, return it
		if k * mid == x {
			return mid
		}
		
		// If mid * k is greater than x, search in the left half
		if k * mid > x {
			return binarySearch(k, l, mid - 1, x)
		}
		
		// Otherwise, search in the right half
		return binarySearch(k, mid + 1, r, x)
	}
	
	return -1
}

func main() {
	// BufferedReader for fast input and PrintWriter for fast output
	br := bufio.NewReader(os.Stdin)
	pw := bufio.NewWriter(os.Stdout)
	defer pw.Flush()
	
	// Scanner to read input values
	var gen, st, tim int64
	
	// Read the input values
	fmt.Fscan(br, &gen, &st, &tim)
	
	// Calculate the effective generation count per time unit
	gen /= tim
	
	// Initialize the binary search range
	beg := st - 1
	end := int64(math.Pow(10, 18))
	
	// Perform binary search to find the maximum valid number
	for {
		med := (beg + end) / 2 + 1
		
		// Check if the count of numbers from st to med exceeds gen
		if get(med) - get(st - 1) > gen {
			end = med - 1
		} else {
			beg = med
		}
		
		// If the search range converges, print the result
		if beg == end {
			fmt.Fprintln(pw, beg - st + 1)
			break
		}
	}
}
