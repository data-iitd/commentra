
package main

import (
	"fmt"
	"math"
	"sort"
)

func getInt4(a1, a2, a3, a4 *int) {
	fmt.Scanf("%d %d %d %d", a1, a2, a3, a4)
}

func fgetArray(arr []int64, size int) {
	for i := 0; i < size; i++ {
		fmt.Scanf("%d", &arr[i])
	}
}

func asc(a1, a2 interface{}) int {
	aa1 := a1.(int64)
	aa2 := a2.(int64)
	if aa1 > aa2 {
		return 1
	} else if aa1 == aa2 {
		return 0
	} else {
		return -1
	}
}

func desc(a1, a2 interface{}) int {
	aa1 := a1.(int64)
	aa2 := a2.(int64)
	if aa1 > aa2 {
		return -1
	} else if aa1 == aa2 {
		return 0
	} else {
		return 1
	}
}

func lowerBound(arr []int64, r struct{ start, end int }, key int64) int {
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

func main() {
	var x, y, z, rank int
	getInt4(&x, &y, &z, &rank)
	xrr := make([]int64, x)
	yrr := make([]int64, y)
	zrr := make([]int64, z)
	fgetArray(xrr, x)
	fgetArray(yrr, y)
	fgetArray(zrr, z)
	minSum := int64(math.MaxInt64)
	maxSum := int64(0)
	for i := 0; i < z; i++ {
		minSum = min(minSum, zrr[i])
		maxSum += zrr[i]
	}
	pair := make([]int64, x*y)
	idx := 0
	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			pair[idx] = xrr[i] + yrr[j]
			idx++
		}
	}
	sort.Slice(pair, func(i, j int) bool { return pair[i] < pair[j] })
	minSum += pair[0]
	maxSum += pair[idx-1]
	cache := make([]int, z)
	cntMap := make([]int, z)
	ans := make([]int64, rank)
	size := x * y * z
	prev := minSum
	for r := rank; r >= 1; r-- {
		low := prev - 1
		high := maxSum + 1
		for low+1 < high {
			mid := (low + high) / 2
			for i := 0; i < z; i++ {
				pivot := zrr[i]
				r := struct{ start, end int }{cache[i] - 1, idx}
				cntMap[i] = lowerBound(pair, r, mid-pivot)
			}
			if sum(cntMap, z) >= size-r {
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
		fmt.Println(ans[i])
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	} else {
		return b
	}
}

func sum(arr []int, size int) int {
	sum := 0
	for i := 0; i < size; i++ {
		sum += arr[i]
	}
	return sum
}

