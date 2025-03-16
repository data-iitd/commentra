package main

import (
	"fmt"
	"sort"
)

const (
	NUM_MAX   = 1000
	NUM2_MAX  = NUM_MAX * NUM_MAX
	RANK_MAX  = 3000
	VAL_MAX   = int64(1e+10)
	SUM_MAX   = VAL_MAX * 3
)

type Range struct {
	start int
	end   int
}

// Function to read an array of 4 integers from the standard input
func getInt4() (int, int, int, int) {
	var a1, a2, a3, a4 int
	fmt.Scan(&a1, &a2, &a3, &a4)
	return a1, a2, a3, a4
}

// Function to read an array of 64-bit integers from the standard input
func fgetArray(arr []int64) {
	for i := range arr {
		fmt.Scan(&arr[i])
	}
}

// Comparator function for sorting in ascending order
func asc(a, b int64) bool {
	return a < b
}

// Comparator function for sorting in descending order
func desc(a, b int64) bool {
	return a > b
}

// Function to find the index of the first element greater than or equal to the given key in the sorted array arr, within the given range r
func lowerBound(arr []int64, r Range, key int64) int {
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

// Function to sum elements of an array
func sum(arr []int) int {
	total := 0
	for _, v := range arr {
		total += v
	}
	return total
}

func main() {
	x, y, z, rank := getInt4()
	xrr := make([]int64, NUM_MAX)
	yrr := make([]int64, NUM_MAX)
	zrr := make([]int64, NUM_MAX)

	fgetArray(xrr[:x])
	fgetArray(yrr[:y])
	fgetArray(zrr[:z])

	minSum := VAL_MAX + 1
	maxSum := int64(0)

	for i := 0; i < z; i++ {
		if zrr[i] < minSum {
			minSum = zrr[i]
		}
		maxSum += zrr[i]
	}

	pair := make([]int64, NUM2_MAX)
	idx := 0

	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			pair[idx] = xrr[i] + yrr[j]
			idx++
		}
	}

	sort.Slice(pair[:idx], func(i, j int) bool {
		return asc(pair[i], pair[j])
	})

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

			for i := 0; i < z; i++ {
				pivot := zrr[i]
				rng := Range{cache[i] - 1, idx}
				tmp := lowerBound(pair, rng, mid-pivot)
				cntMap[i] = tmp
			}

			if sum(cntMap[:z]) >= size-r {
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
		if ans[i] == 0 {
			fmt.Println(maxSum)
		} else {
			fmt.Println(ans[i])
		}
	}
}

// <END-OF-CODE>
