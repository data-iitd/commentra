package main

import (
	"fmt"
	"math"
)

func merge(left, mid, right int) int {
	var i, j, k int
	var cnt int = 0
	var n1 int = mid - left
	var n2 int = right - mid

	L := make([]int, n1)
	R := make([]int, n2)

	for i = 0; i < n1; i++ {
		L[i] = a[left+i]
	}
	for i = 0; i < n2; i++ {
		R[i] = a[mid+i]
	}

	L[n1] = math.MaxInt32
	R[n2] = math.MaxInt32

	i = 0
	j = 0
	for k = left; k < right; k++ {
		if L[i] <= R[j] {
			a[k] = L[i]
			i++
		} else {
			a[k] = R[j]
			j++
			cnt += n1 - i
		}
	}
	return cnt
}

func mergesort(left, right int) int {
	var mid int
	var v1, v2, v3 int
	if left+1 < right {
		mid = (left + right) / 2
		v1 = mergesort(left, mid)
		v2 = mergesort(mid, right)
		v3 = merge(left, mid, right)
		return v1 + v2 + v3
	}
	return 0
}

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	ans := mergesort(0, n)
	fmt.Println(ans)
}

