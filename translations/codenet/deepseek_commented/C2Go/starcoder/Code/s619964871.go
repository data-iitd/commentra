/*
 * FileName:     the_number_of_inversions_fix
 * CreatedDate:  2020-06-05 16:25:10 +0900
 * LastModified: 2020-07-06 22:22:35 +0900
 */

<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to merge two subarrays and count inversions
func sort(a []int, left, middle, right int) int {
	l_arr := make([]int, middle-left+1)
	r_arr := make([]int, right-middle+1)
	cnt := 0
	// Copy elements into temporary arrays
	for i := 0; i < middle-left; i++ {
		l_arr[i] = a[i+left]
	}
	for i := 0; i < right-middle; i++ {
		r_arr[i] = a[i+middle]
	}
	// Sentinel values to simplify merging
	l_arr[middle-left] = 1e12
	r_arr[right-middle] = 1e12
	l, r := 0, 0
	// Merge the two subarrays while counting inversions
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

// Recursive function to count inversions in the array
func merge(a []int, left, right int) int {
	if left+1 < right {
		middle := (left + right) / 2
		// Recursively count inversions in the left and right halves
		x1 := merge(a, left, middle)
		x2 := merge(a, middle, right)
		// Merge the two halves and count inversions in the merge step
		x3 := sort(a, left, middle, right)
		return x1 + x2 + x3
	} else {
		return 0
	}
}

// Main function to read input, count inversions, and print the result
func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the size of the array: ")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))
	a := make([]int, n)
	fmt.Print("Enter the elements of the array: ")
	for i := 0; i < n; i++ {
		input, _ := reader.ReadString('\n')
		a[i], _ = strconv.Atoi(strings.TrimSpace(input))
	}
	fmt.Printf("The number of inversions is %d\n", merge(a, 0, n))
}

