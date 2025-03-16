

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

#define max(a,b) ((a) > (b)? (a) : (b))
#define min(a,b) ((a) > (b)? (b) : (a))

func get_int4(a1 *int, a2 *int, a3 *int, a4 *int) int {
	// Read 4 integers from the standard input and store them in the given pointers
	fmt.Fscanf(os.Stdin, "%d %d %d %d", a1, a2, a3, a4)
	// Return 0 to indicate successful execution
	return 0
}

func fget_array(arr []int64, size int) int {
	var i int
	// Iterate through the given size and read each 64-bit integer from the standard input and store it in the given array
	for i = 0; i < size; i++ {
		fmt.Fscanf(os.Stdin, "%d", &arr[i])
	}
	// Return 0 to indicate successful execution
	return 0
}

#define NUM_MAX 1000
#define NUM2_MAX (NUM_MAX*NUM_MAX)
#define RANK_MAX 3000

// Comparator function for sort.Sort to sort an array of 64-bit integers in ascending order
type Int64Slice []int64

func (p Int64Slice) Len() int           { return len(p) }
func (p Int64Slice) Less(i, j int) bool { return p[i] < p[j] }
func (p Int64Slice) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }

// Comparator function for sort.Sort to sort an array of 64-bit integers in descending order
type Int64SliceDesc []int64

func (p Int64SliceDesc) Len() int           { return len(p) }
func (p Int64SliceDesc) Less(i, j int) bool { return p[i] > p[j] }
func (p Int64SliceDesc) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }

#define VAL_MAX (int64)(1e+10)
#define SUM_MAX (VAL_MAX*3)

type Range struct {
	Start int
	End   int
}

// Function to find the index of the first element greater than or equal to the given key in the sorted array arr, within the given range r
func lower_bound(arr []int64, r Range, key int64) int {
	low := r.Start
	high := r.End
	// Binary search to find the index of the first element greater than or equal to the given key in the sorted array arr, within the given range r
	for low+1 < high {
		mid := (low + high) / 2
		if arr[mid] < key {
			low = mid
		} else {
			high = mid
		}
	}
	// Return the index of the first element greater than or equal to the given key, or the size of the array if no such element exists
	return low + 1
}

func main() {
	var x, y, z, rank int
	// Read 4 integers x, y, z, and rank from the standard input
	get_int4(&x, &y, &z, &rank)
	var xrr [NUM_MAX]int64 // Declare an array xrr of size NUM_MAX to store the first array of 64-bit integers
	var yrr [NUM_MAX]int64 // Declare an array yrr of size NUM_MAX to store the second array of 64-bit integers
	var zrr [NUM_MAX]int64 // Declare an array zrr of size NUM_MAX to store the third array of 64-bit integers
	// Read the three arrays of 64-bit integers from the standard input using the function fget_array()
	fget_array(xrr[:], x)
	fget_array(yrr[:], y)
	fget_array(zrr[:], z)
	minSum := VAL_MAX + 1 // Initialize minSum with a value larger than any possible sum
	maxSum := int64(0)    // Initialize maxSum with an initial value of 0
	i, j := 0, 0          // Initialize loop variables i and j with initial values of 0
	// Iterate through the third array zrr and update minSum and maxSum accordingly
	for i = 0; i < z; i++ {
		minSum = min(minSum, zrr[i])
		maxSum += zrr[i]
	}

	var pair [NUM2_MAX]int64 // Declare an array pair of size NUM2_MAX to store the sum of each pair of elements from the first and second arrays
	idx := 0                  // Initialize an index variable idx to 0
	// Iterate through the first array xrr and the second array yrr, and compute the sum of each pair, storing it in the array pair
	for i = 0; i < x; i++ {
		for j = 0; j < y; j++ {
			pair[idx] = xrr[i] + yrr[j]
			idx++
		}
	}
	// Sort the array pair in ascending order using the sort.Sort() function and the Int64Slice type
	sort.Sort(Int64Slice(pair[:idx]))
	// Update minSum and maxSum with the sum of the first and last elements in the sorted array pair, respectively
	minSum += pair[0]
	maxSum += pair[idx-1]

	var cache [NUM_MAX]int // Declare an array cache of size NUM_MAX to store the index of the last element less than or equal to the current pivot in the sorted array pair, for each pivot in the third array zrr
	var cntMap [NUM_MAX]int // Declare an array cntMap of size NUM_MAX to store the number of elements in the sorted array pair less than or equal to the current pivot, for each pivot in the third array zrr
	var ans [RANK_MAX]int64 // Declare an array ans of size RANK_MAX to store the answer for each rank
	size := x * y * z // Compute the size of the array pair
	prev := minSum    // Initialize prev with the initial value of minSum
	r := rank          // Initialize a loop variable r with an initial value of rank
	// Iterate through the ranks from rank down to 1, and find the answer for each rank using binary search
	for r > 0 {
		low := prev - 1 // Initialize the lower bound of the binary search with prev-1
		high := maxSum + 1 // Initialize the upper bound of the binary search with maxSum+1
		// Binary search to find the index of the first element greater than or equal to the current rank in the sorted array ans, using the lower_bound() function
		for low+1 < high {
			mid := (low + high) / 2
			// Compute the number of elements in the sorted array pair less than or equal to the current pivot, for each pivot in the third array zrr
			for i = 0; i < z; i++ {
				pivot := zrr[i]
				r := Range{cache[i] - 1, idx} // Define the range r for the current pivot
				tmp := lower_bound(pair, r, mid-pivot) // Find the index of the first element greater than or equal to mid-pivot in the sorted array pair, within the range r
				cntMap[i] = tmp // Store the number of elements in the sorted array pair less than or equal to the current pivot, for the current pivot
			}
			// Check if the total number of elements in the sorted array pair less than or equal to the current pivot, for all pivots in the third array zrr, is greater than or equal to the size of the array pair minus the current rank
			if sum(cntMap[:], z) >= size-r {
				// If so, update prev with mid and continue the outer loop
				low = mid
			} else {
				// Otherwise, update high with mid and continue the inner loop
				high = mid
			}
		}
		// Store the index of the first element greater than or equal to the current rank in the sorted array ans
		ans[r-1] = low
		// If the index found is equal to maxSum, break the outer loop as there is no solution for the current rank
		if low == maxSum {
			break
		}
		// Update prev with the index found
		prev = low
		r--
	}
	// Print the answer for each rank, except for the last rank which may not have a solution
	for i := 0; i < rank; i++ {
		if ans[i] == 0 {
			fmt.Println(maxSum)
		} else {
			fmt.Println(ans[i])
		}
	}
}

