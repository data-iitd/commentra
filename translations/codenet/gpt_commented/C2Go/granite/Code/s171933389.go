
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Function to read four integers from standard input
func get_int4(a1 *int, a2 *int, a3 *int, a4 *int) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	tokens := strings.Split(scanner.Text(), " ")
	*a1, _ = strconv.Atoi(tokens[0])
	*a2, _ = strconv.Atoi(tokens[1])
	*a3, _ = strconv.Atoi(tokens[2])
	*a4, _ = strconv.Atoi(tokens[3])
}

// Function to read an array of int64 from standard input
func fget_array(arr []int64, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		arr[i], _ = strconv.ParseInt(scanner.Text(), 10, 64)
	}
}

// Constants defining maximum sizes for arrays and ranks
const (
	NUM_MAX  = 1000
	NUM2_MAX = NUM_MAX * NUM_MAX
	RANK_MAX = 3000
)

// Comparison function for ascending order used in sort.Sort
type Int64Slice []int64

func (p Int64Slice) Len() int           { return len(p) }
func (p Int64Slice) Less(i, j int) bool { return p[i] < p[j] }
func (p Int64Slice) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }

// Constants defining maximum values for calculations
const (
	VAL_MAX = int64(1e+10)
	SUM_MAX = VAL_MAX * 3
)

// Main function
func main() {
	// Variables to hold input values and rank
	var x, y, z, rank int
	get_int4(&x, &y, &z, &rank) // Read the dimensions and rank

	// Arrays to hold input values
	xrr := make([]int64, x)
	yrr := make([]int64, y)
	zrr := make([]int64, z)

	// Read the arrays from input
	fget_array(xrr, x)
	fget_array(yrr, y)
	fget_array(zrr, z)

	// Initialize min and max sums
	minSum := VAL_MAX + 1
	maxSum := int64(0)

	// Calculate minimum and maximum values from zrr
	for i := 0; i < z; i++ {
		if zrr[i] < minSum {
			minSum = zrr[i]
		}
		if zrr[i] > maxSum {
			maxSum = zrr[i]
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
	sort.Sort(Int64Slice(pair))

	// Update min and max sums with the smallest and largest pair sums
	minSum += pair[0]
	maxSum += pair[idx-1]

	// Arrays for caching and counting
	cache := make([]int, z)
	cntMap := make([]int, z)
	ans := make([]int64, RANK_MAX)

	// Calculate the size of the combined array
	size := x * y * z
	prev := minSum
	r := rank

	// Iterate to find the rank-th largest sum
	for r >= 1 {
		low := prev - 1
		high := maxSum + 1

		// Binary search to find the appropriate sum
		for low+1 < high {
			mid := (low + high) / 2
			cnt := 0

			// Count how many sums are less than or equal to mid
			for i := 0; i < z; i++ {
				pivot := zrr[i]
				cache[i] = lowerBound(pair, mid-pivot)
				cntMap[i] = cache[i]
				cnt += cache[i]
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
		r--
	}

	// Print the results for each rank
	for i := 0; i < rank; i++ {
		if ans[i] == 0 {
			ans[i] = maxSum
		}
		fmt.Println(ans[i])
	}
}

// Function to find the lower bound index of a key in a sorted array
func lowerBound(arr []int64, key int64) int {
	low := 0
	high := len(arr)

	for low < high {
		mid := (low + high) / 2
		if arr[mid] < key {
			low = mid + 1
		} else {
			high = mid
		}
	}
	return low
}

// Translate the above Go code to C and end with comment "