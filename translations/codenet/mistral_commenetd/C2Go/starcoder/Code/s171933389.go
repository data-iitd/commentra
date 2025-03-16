
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Function to read an array of 4 integers from the standard input
func get_int4(a1 *int, a2 *int, a3 *int, a4 *int) {
	// Read 4 integers from the standard input and store them in the given pointers
	fmt.Scanf("%d %d %d %d", a1, a2, a3, a4)
}

// Function to read an array of 64-bit integers from the standard input
func fget_array(arr []int64, size int) {
	// Iterate through the given size and read each 64-bit integer from the standard input and store it in the given array
	for i := 0; i < size; i++ {
		fmt.Scanf("%d", &arr[i])
	}
}

// Function to find the index of the first element greater than or equal to the given key in the sorted array arr, within the given range r
func lower_bound(arr []int64, r struct{ start, end int }, key int64) int {
	low := r.start
	high := r.end
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
	xrr := make([]int64, x) // Declare an array xrr of size x to store the first array of 64-bit integers
	yrr := make([]int64, y) // Declare an array yrr of size y to store the second array of 64-bit integers
	zrr := make([]int64, z) // Declare an array zrr of size z to store the third array of 64-bit integers
	// Read the three arrays of 64-bit integers from the standard input using the function fget_array()
	fget_array(xrr, x)
	fget_array(yrr, y)
	fget_array(zrr, z)
	min_sum := int64(1e+10) // Initialize min_sum with a value larger than any possible sum
	max_sum := int64(0)     // Initialize max_sum with an initial value of 0
	// Iterate through the third array zrr and update min_sum and max_sum accordingly
	for i := 0; i < z; i++ {
		min_sum = min(min_sum, zrr[i])
		max_sum += zrr[i]
	}

	pair := make([]int64, x*y) // Declare an array pair of size x*y to store the sum of each pair of elements from the first and second arrays
	idx := 0                   // Initialize an index variable idx to 0
	// Iterate through the first array xrr and the second array yrr, and compute the sum of each pair, storing it in the array pair
	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			pair[idx] = xrr[i] + yrr[j]
			idx++
		}
	}
	// Sort the array pair in ascending order using the sort.Slice() function and the asc() comparator function
	sort.Slice(pair, func(i, j int) bool { return pair[i] < pair[j] })
	// Update min_sum and max_sum with the sum of the first and last elements in the sorted array pair, respectively
	min_sum += pair[0]
	max_sum += pair[len(pair)-1]

	cache := make([]int, z) // Declare an array cache of size z to store the index of the last element less than or equal to the current pivot in the sorted array pair, for each pivot in the third array zrr
	cnt_map := make([]int, z) // Declare an array cnt_map of size z to store the number of elements in the sorted array pair less than or equal to the current pivot, for each pivot in the third array zrr
	ans := make([]int64, rank) // Declare an array ans of size rank to store the answer for each rank
	size := x*y*z // Compute the size of the array pair
	prev := min_sum // Initialize prev with the initial value of min_sum
	r := rank // Initialize a loop variable r with an initial value of rank
	// Iterate through the ranks from rank down to 1, and find the answer for each rank using binary search
	for r >= 1 {
		low := prev - 1 // Initialize the lower bound of the binary search with prev-1
		high := max_sum + 1 // Initialize the upper bound of the binary search with max_sum+1
		// Binary search to find the index of the first element greater than or equal to the current rank in the sorted array ans, using the lower_bound() function
		for low+1 < high {
			mid := (low + high) / 2
			// Compute the number of elements in the sorted array pair less than or equal to the current pivot, for each pivot in the third array zrr
			for i := 0; i < z; i++ {
				pivot := zrr[i]
				r := struct{ start, end int }{cache[i]-1, len(pair)} // Define the range r for the current pivot
				tmp := lower_bound(pair, r, mid-pivot) // Find the index of the first element greater than or equal to mid-pivot in the sorted array pair, within the range r
				cnt_map[i] = tmp // Store the number of elements in the sorted array pair less than or equal to the current pivot, for the current pivot
			}
			// Check if the total number of elements in the sorted array pair less than or equal to the current pivot, for all pivots in the third array zrr, is greater than or equal to the size of the array pair minus the current rank
			if sum(cnt_map, z) >= size-r {
				// If so, update prev with mid and continue the outer loop
				low = mid
			} else {
				// Otherwise, update high with mid and continue the inner loop
				high = mid
			}
		}
		// Store the index of the first element greater than or equal to the current rank in the sorted array ans
		ans[r-1] = low
		// If the index found is equal to max_sum, break the outer loop as there is no solution for the current rank
		if low == max_sum {
			break
		}
		// Update prev with the index found
		prev = low
		r--
	}
	// Print the answer for each rank, except for the last rank which may not have a solution
	for i := 0; i < rank; i++ {
<<<<<<< HEAD
		fmt.Printf("%d\n", (ans[i] == 0)? max_sum : ans[i])
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func sum(arr []int, size int) int {
	var s int
	for i := 0; i < size; i++ {
		s += arr[i]
	}
	return s
}

=======
		fmt.Printf("%d\n", ans[i])
	}
}

>>>>>>> 98c87cb78a (data updated)
