package main

import (
	"fmt"
	"sort"
)

// Constants defining maximum sizes for arrays and ranks
const (
	NUM_MAX   = 1000
	NUM2_MAX  = NUM_MAX * NUM_MAX
	RANK_MAX  = 3000
	VAL_MAX   = int64(1e+10)
	SUM_MAX   = VAL_MAX * 3
)

// Structure to represent a range with start and end indices
type Range struct {
	start int
	end   int
}

// Function to read four integers from standard input
func getInt4() (int, int, int, int) {
	var a1, a2, a3, a4 int
	fmt.Scan(&a1, &a2, &a3, &a4)
	return a1, a2, a3, a4
}

// Function to read an array of int64 from standard input
func fgetArray(arr []int64) {
	for i := range arr {
		fmt.Scan(&arr[i])
	}
}

// Comparison function for ascending order used in sort
func asc(a, b int64) bool {
	return a < b
}

// Function to find the lower bound index of a key in a sorted array
func lowerBound(arr []int64, r Range, key int64) int {
	low := r.start
	high := r.end
	for low+1 < high {
		mid := (low + high) / 2
		if arr[mid] < key {
			low = mid
		} else {
			high = mid
		}
	}
	return low + 1 // Return the index of the first element greater than key
}

// Main function
func main() {
	// Variables to hold input values and rank
	x, y, z, rank := getInt4() // Read the dimensions and rank

	// Arrays to hold input values
	xrr := make([]int64, x)
	yrr := make([]int64, y)
	zrr := make([]int64, z)

	// Read the arrays from input
	fgetArray(xrr)
	fgetArray(yrr)
	fgetArray(zrr)

	// Initialize min and max sums
	minSum := VAL_MAX + 1
	maxSum := int64(0)

	// Calculate minimum and maximum values from zrr
	for _, val := range zrr {
		if val < minSum {
			minSum = val
		}
		if val > maxSum {
			maxSum = val
		}
	}

	// Create an array to hold the sums of pairs from xrr and yrr
	pair := make([]int64, NUM2_MAX)
	idx := 0

	// Calculate all possible sums of pairs from xrr and yrr
	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			pair[idx] = xrr[i] + yrr[j]
			idx++
		}
	}

	// Sort the pair array in ascending order
	sort.Slice(pair[:idx], func(i, j int) bool {
		return asc(pair[i], pair[j])
	})

	// Update min and max sums with the smallest and largest pair sums
	minSum += pair[0]
	maxSum += pair[idx-1]

	// Arrays for caching and counting
	cache := make([]int, NUM_MAX)
	cntMap := make([]int, NUM_MAX)
	ans := make([]int64, RANK_MAX)

	// Calculate the size of the combined array
	size := x * y * z
	prev := minSum

	// Iterate to find the rank-th largest sum
	for r := rank; r >= 1; r-- {
		low := prev - 1
		high := maxSum + 1

		// Binary search to find the appropriate sum
		for low+1 < high {
			mid := (low + high) / 2
			cnt := 0

			// Count how many sums are less than or equal to mid
			for i := 0; i < z; i++ {
				pivot := zrr[i]
				rng := Range{cache[i] - 1, idx}
				tmp := lowerBound(pair, rng, mid-pivot)
				cntMap[i] = tmp
				cnt += tmp
			}

			// Adjust the search range based on the count
			if cnt <= size-r {
				copy(cache, cntMap)
				low = mid
			} else {
				high = mid
			}
		}

		// Store the found sum in the answer array
		ans[r-1] = low
		if low == maxSum {
			break // Stop if we reach the maximum sum
		}
		prev = low // Update previous sum for the next iteration
	}

	// Print the results for each rank
	for i := 0; i < rank; i++ {
		if ans[i] == 0 {
			fmt.Println(maxSum)
		} else {
			fmt.Println(ans[i])
		}
	}
}

// <END-OF-CODE>
