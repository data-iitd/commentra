/*
 * FileName:     the_number_of_inversions_fix
 * CreatedDate:  2020-06-05 16:25:10 +0900
 * LastModified: 2020-07-06 22:22:35 +0900
 */

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to merge two halves of an array and count inversions
func sort(a []int, left, middle, right int) int {
	// Create temporary arrays for left and right halves
	l_arr := make([]int, middle-left+1)
	r_arr := make([]int, right-middle+1)
	cnt := 0  // Initialize inversion count

	// Copy data to temporary arrays
	for i := 0; i < middle-left; i++ {
		l_arr[i] = a[i+left]
	}
	for i := 0; i < right-middle; i++ {
		r_arr[i] = a[i+middle]
	}

	// Add sentinel values to the end of the temporary arrays
	l_arr[middle-left] = 1e12
	r_arr[right-middle] = 1e12

	l := 0
	r := 0  // Initialize pointers for left and right arrays

	// Merge the two halves back into the original array
	for i := 0; i < right-left; i++ {
		if l_arr[l] <= r_arr[r] {
			a[left+i] = l_arr[l]
			l++
		} else {
			a[left+i] = r_arr[r]
			cnt += middle - left - l
			r++
		}
	}
	return cnt
}

// Function to recursively divide the array and count inversions
func merge(a []int, left, right int) int {
	if left+1 < right {
		middle := (left + right) / 2
		x1 := merge(a, left, middle)
		x2 := merge(a, middle, right)
		x3 := sort(a, left, middle, right)
		return x1 + x2 + x3
	} else {
		return 0
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of elements: ")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Print("Enter the element: ")
		input, _ := reader.ReadString('\n')
		a[i], _ = strconv.Atoi(strings.TrimSpace(input))
	}
	fmt.Printf("The number of inversions: %d\n", merge(a, 0, n))
}

