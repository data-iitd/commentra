
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables
	var n int
	var a []int
	var cnt int = 1
	var isup bool
	var issame bool = false

	// Read the number of elements from the user
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)

	// Read the elements of the array from the user
	a = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &a[i])
	}

	// Determine if the first two elements form an increasing subsequence
	if a[0] < a[1] {
		isup = true
	} else if a[0] > a[1] {
		isup = false
	} else {
		issame = true
	}

	// Check for increasing subsequences in the array
	for i := 1; i < n-1; i++ {
		// If the previous subsequence is made of same elements
		if issame {
			// If the current element is not the same as the next one
			if a[i]!= a[i+1] {
				// Reset the flags and determine if the new subsequence is increasing or not
				issame = false
				if a[i] < a[i+1] {
					isup = true
				} else {
					isup = false
				}
				cnt++
			}
		} else {
			// If the subsequence is increasing
			if isup && a[i] <= a[i+1] {
				// Continue the loop
				continue
			} else if!isup && a[i] >= a[i+1] {
				// The subsequence is decreasing, reset the flags and continue the loop
				isup = false
				issame = false
				cnt++
			} else {
				// Check for the next element to determine if it starts a new increasing subsequence
				if i+2 < n {
					if a[i+1] < a[i+2] {
						isup = true
					} else if a[i+1] > a[i+2] {
						isup = false
					} else {
						issame = true
					}
					cnt++
				} else {
					// Reach the end of the array, increment the counter and break the loop
					cnt++
					break
				}
			}
		}
	}

	// Print the number of increasing subsequences
	fmt.Println(cnt)
}

