
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var len int
	var a []int
	var l, r int
	var flag, isTrue bool
	var i int
	var s string
	var err error

	// Read the length of the array
	fmt.Scan(&len)
	// Initialize the array with the length read
	a = make([]int, len)
	for i = 0; i < len; i++ {
		// Read the elements of the array
		fmt.Scan(&a[i])
	}
	l = 0
	r = 0
	flag = false
	isTrue = false
	for i = 0; i < len; i++ {
		if a[i] != i+1 && !flag {
			// Check for the first misplaced element
			l = i + 1
			flag = true
			continue
		}
		if a[i] != i+1 && flag {
			// Check for the second misplaced element
			r = i + 1
			if (a[r-1] - a[r-2]) > 0 {
				// Check if the segment is unsorted
				isTrue = true
				break
			}
		}
	}
	if !isTrue {
		fmt.Println(l, r)
	} else {
		fmt.Println("0", "0")
	}
}

