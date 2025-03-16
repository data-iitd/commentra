
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Constants defining maximum values for calculations
const (
	VAL_MAX = 1000000000
	SUM_MAX = VAL_MAX * 3
)

// Structure to represent a range with start and end indices
type range struct {
	start int
	end   int
}

// Function to find the lower bound index of a key in a sorted array
func lower_bound(arr []int64, r range, key int64) int {
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
	var x, y, z, rank int
	fmt.Scan(&x, &y, &z, &rank) // Read the dimensions and rank

	// Arrays to hold input values
	xrr := make([]int64, x)
	yrr := make([]int64, y)
	zrr := make([]int64, z)

	// Read the arrays from input
	for i := 0; i < x; i++ {
		fmt.Scan(&xrr[i])
	}
	for i := 0; i < y; i++ {
		fmt.Scan(&yrr[i])
	}
	for i := 0; i < z; i++ {
		fmt.Scan(&zrr[i])
	}

	// Initialize min and max sums
	min_sum := VAL_MAX + 1
	max_sum := 0

	// Calculate minimum and maximum values from zrr
	for i := 0; i < z; i++ {
		min_sum = min(min_sum, zrr[i])
		max_sum = max(max_sum, zrr[i])
	}

	// Create an array to hold the sums of pairs from xrr and yrr
	pair := make([]int64, x*y)
	idx := 0

	// Calculate all possible sums of pairs from xrr and yrr
	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			pair[idx] = xrr[i] + yrr[j]
			idx++
		}
	}

	// Sort the pair array in ascending order
	sort.Slice(pair, func(i, j int) bool { return pair[i] < pair[j] })

	// Update min and max sums with the smallest and largest pair sums
	min_sum += pair[0]
	max_sum += pair[idx-1]

	// Arrays for caching and counting
	cache := make([]int, z)
	cnt_map := make([]int, z)
	ans := make([]int64, rank)

	// Calculate the size of the combined array
	size := x * y * z
	prev := min_sum
	var r int

	// Iterate to find the rank-th largest sum
	for r = rank; r >= 1; r-- {
		low := prev - 1
		high := max_sum + 1

		// Binary search to find the appropriate sum
		for low+1 < high {
			mid := (low + high) / 2
			cnt := 0

			// Count how many sums are less than or equal to mid
			for i := 0; i < z; i++ {
				pivot := zrr[i]
				r := range{cache[i] - 1, idx}
				tmp := lower_bound(pair, r, mid-pivot)
				cnt_map[i] = tmp
				cnt += tmp
			}

			// Adjust the search range based on the count
			if cnt <= size-r {
				copy(cache, cnt_map)
				low = mid
			} else {
				high = mid
			}
		}

		// Store the found sum in the answer array
		ans[r-1] = low
		if low == max_sum {
			break // Stop if we reach the maximum sum
		}
		prev = low // Update previous sum for the next iteration
	}

	// Print the results for each rank
	for i := 0; i < rank; i++ {
		fmt.Println(ans[i])
	}
}

// Function to find the minimum of two values
func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// Function to find the maximum of two values
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// Function to read four integers from standard input
func get_int4(a1, a2, a3, a4 *int) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	fmt.Sscanf(scanner.Text(), "%d %d %d %d", a1, a2, a3, a4)
}

// Function to read an array of int64_t from standard input
func fget_array(arr []int64, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_str(arr []string, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		arr[i] = scanner.Text()
	}
}

// Function to read an array of int64_t from standard input
func fget_array_int(arr []int, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_int64(arr []int64, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_float64(arr []float64, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%f", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_bool(arr []bool, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%t", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_complex64(arr []complex64, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%f", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_complex128(arr []complex128, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%f", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_uint(arr []uint, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_uint8(arr []uint8, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_uint16(arr []uint16, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_uint32(arr []uint32, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_uint64(arr []uint64, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_byte(arr []byte, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_rune(arr []rune, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_float32(arr []float32, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%f", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_int32(arr []int32, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_int16(arr []int16, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_int8(arr []int8, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_uintptr(arr []uintptr, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_string(arr []string, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		arr[i] = scanner.Text()
	}
}

// Function to read an array of int64_t from standard input
func fget_array_int64(arr []int64, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_uint64(arr []uint64, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_float64(arr []float64, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%f", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_complex128(arr []complex128, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%f", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_complex64(arr []complex64, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%f", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_bool(arr []bool, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < size; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%t", &arr[i])
	}
}

// Function to read an array of int64_t from standard input
func fget_array_rune(arr []rune, size int) {
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0;