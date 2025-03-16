// The code starts by including necessary headers for input/output operations, string manipulation, and memory management.
package main

import (
	"fmt"
	"sort"
)

// Macros are defined to set the maximum sizes for arrays and other constants.
const (
	NUM_MAX  = 1000
	NUM2_MAX = NUM_MAX * NUM_MAX
	RANK_MAX = 3000
)

// This function reads four integers from the standard input and stores them in the provided variables.
func getInt4(a1, a2, a3, a4 *int) {
	fmt.Scanf("%d %d %d %d", a1, a2, a3, a4)
}

// This function reads an array of integers from the standard input.
func fgetArray(arr []int64, size int) {
	for i := 0; i < size; i++ {
		fmt.Scanf("%d", &arr[i])
	}
}

// These functions are used to compare integers for sorting in ascending and descending order.
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

// Constants are defined for the maximum values of various quantities.
const (
	VAL_MAX = int64(1e+10)
	SUM_MAX = VAL_MAX * 3
)

// A structure is defined to represent a range of indices.
type range struct {
	start int
	end   int
}

// This function finds the lower bound of a key in a sorted array within a given range.
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
	return low + 1
}

// The main function reads input, processes data, and outputs the result based on the given rank.
func main() {
	var x, y, z, rank int
	getInt4(&x, &y, &z, &rank)
	xrr := make([]int64, x)
	yrr := make([]int64, y)
	zrr := make([]int64, z)
	fgetArray(xrr, x)
	fgetArray(yrr, y)
	fgetArray(zrr, z)
	minSum := VAL_MAX + 1
	maxSum := int64(0)
	for i := 0; i < z; i++ {
		minSum = min(minSum, zrr[i])
	}
	for i := 0; i < z; i++ {
		maxSum = max(maxSum, zrr[i])
	}

	pair := make([]int64, NUM2_MAX)
	idx := 0
	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			pair[idx] = xrr[i] + yrr[j]
			idx++
		}
	}
	sort.Slice(pair, func(i, j int) bool { return asc(pair[i], pair[j]) < 0 })
	minSum += pair[0]
	maxSum += pair[idx-1]

	cache := make([]int, NUM_MAX)
	cntMap := make([]int, NUM_MAX)
	ans := make([]int64, RANK_MAX)
	size := x * y * z
	prev := minSum
	for r := rank; r >= 1; r-- {
		low := prev - 1
		high := maxSum + 1
		for low+1 < high {
			mid := (low + high) / 2
			cnt := 0
			for i := 0; i < z; i++ {
				pivot := zrr[i]
				r := range{cache[i] - 1, idx}
				tmp := lowerBound(pair, r, mid-pivot)
				cntMap[i] = tmp
				cnt += tmp
			}
			if cnt <= size-r {
				copy(cache, cntMap)
				low = mid
			} else {
				high = mid
			}
		}
		ans[r-1] = low
		if low == maxSum {
			break
		}
		prev = low
	}
	for i := 0; i < rank; i++ {
		fmt.Println((ans[i] == 0) ? maxSum : ans[i])
	}
}

// 