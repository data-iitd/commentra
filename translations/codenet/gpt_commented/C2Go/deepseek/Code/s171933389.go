package main

import (
	"fmt"
	"sort"
)

// Macro definitions for maximum and minimum
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// Function to read four integers from standard input
func getInt4(a1, a2, a3, a4 *int) {
	fmt.Scanf("%d %d %d %d", a1, a2, a3, a4)
}

// Function to read an array of int64_t from standard input
func fgetArray(arr []int64, size int) {
	for i := 0; i < size; i++ {
		fmt.Scan(&arr[i])
	}
}

// Constants defining maximum sizes for arrays and ranks
const (
	NUM_MAX  = 1000
	NUM2_MAX = NUM_MAX * NUM_MAX
	RANK_MAX = 3000
)

// Comparison function for ascending order used in qsort
func asc(a1, a2 interface{}) int {
	aa1 := a1.(int64)
	aa2 := a2.(int64)
	if aa1 > aa2 {
		return 1
	}
	if aa1 == aa2 {
		return 0
	}
	return -1
}

// Comparison function for descending order used in qsort
func desc(a1, a2 interface{}) int {
	aa1 := a1.(int64)
	aa2 := a2.(int64)
	if aa1 > aa2 {
		return -1
	}
	if aa1 == aa2 {
		return 0
	}
	return 1
}

// Constants defining maximum values for calculations
const (
	VAL_MAX = int64(1e+10)
	SUM_MAX = VAL_MAX * 3
)

// Structure to represent a range with start and end indices
type range struct {
	start int
	end   int
}

// Function to find the lower bound index of a key in a sorted array
func lowerBound(arr []int64, r range, key int64) int {
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

func main() {
	// Variables to hold input values and rank
	var x, y, z, rank int
	getInt4(&x, &y, &z, &rank) // Read the dimensions and rank

	// Arrays to hold input values
	xrr := make([]int64, NUM_MAX)
	yrr := make([]int64, NUM_MAX)
	zrr := make([]int64, NUM_MAX)

	// Read the arrays from input
	fgetArray(xrr, x)
	fgetArray(yrr, y)
	fgetArray(zrr, z)

	// Initialize min and max sums
	minSum := VAL_MAX + 1
	maxSum := int64(0)

	// Calculate minimum and maximum values from zrr
	for i := 0; i < z; i++ {
		minSum = min(minSum, zrr[i])
		maxSum = max(maxSum, zrr[i])
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
	sort.Slice(pair, func(i, j int) bool {
		return pair[i] < pair[j]
	})

	// Update min and max sums with the smallest and largest pair sums
	minSum += pair[0]
	maxSum += pair[len(pair)-1]

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
				r := range{cache[i] - 1, len(pair)}
				tmp := lowerBound(pair, r, mid-pivot)
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

