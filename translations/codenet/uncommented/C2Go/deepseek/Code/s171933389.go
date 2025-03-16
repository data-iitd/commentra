package main

import (
	"fmt"
	"sort"
)

func getInt4(a1, a2, a3, a4 *int) {
	fmt.Scan(&*a1, &*a2, &*a3, &*a4)
}

func fgetArray(arr []int64, size int) {
	for i := 0; i < size; i++ {
		fmt.Scan(&arr[i])
	}
}

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

func main() {
	var x, y, z, rank int
	fmt.Scan(&x, &y, &z, &rank)
	var xrr = make([]int64, x)
	var yrr = make([]int64, y)
	var zrr = make([]int64, z)
	fgetArray(xrr, x)
	fgetArray(yrr, y)
	fgetArray(zrr, z)
	minSum := int64(1e10) + 1
	maxSum := int64(0)
	for i := 0; i < z; i++ {
		if zrr[i] < minSum {
			minSum = zrr[i]
		}
		if zrr[i] > maxSum {
			maxSum = zrr[i]
		}
	}
	var pair = make([]int64, x*y)
	idx := 0
	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			pair[idx] = xrr[i] + yrr[j]
			idx++
		}
	}
	sort.Slice(pair, func(i, j int) bool {
		return pair[i] < pair[j]
	})
	minSum += pair[0]
	maxSum += pair[len(pair)-1]

	var cache = make([]int, z)
	var cntMap = make([]int, z)
	var ans = make([]int64, rank)
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
				r := range{cache[i] - 1, len(pair)}
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
		if ans[i] == 0 {
			fmt.Println(maxSum)
		} else {
			fmt.Println(ans[i])
		}
	}
}

