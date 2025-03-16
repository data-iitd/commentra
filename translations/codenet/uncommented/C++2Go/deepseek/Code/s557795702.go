package main

import (
	"fmt"
	"math"
)

const INF = 0x3f3f3f3f

func merge(a []int, left, mid, right int) int {
	cnt := 0
	n1 := mid - left
	n2 := right - mid
	L := make([]int, n1+1)
	R := make([]int, n2+1)
	for i := 0; i < n1; i++ {
		L[i] = a[left+i]
	}
	for i := 0; i < n2; i++ {
		R[i] = a[mid+i]
	}
	L[n1] = INF
	R[n2] = INF
	i, j := 0, 0
	for k := left; k < right; k++ {
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

func mergesort(a []int, left, right int) int {
	if left+1 < right {
		mid := (left + right) / 2
		v1 := mergesort(a, left, mid)
		v2 := mergesort(a, mid, right)
		v3 := merge(a, left, mid, right)
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
	ans := mergesort(a, 0, n)
	fmt.Println(ans)
}

