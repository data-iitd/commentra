package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

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

func merge(a []int, left, mid, right int) int {
	L := make([]int, mid-left)
	R := make([]int, right-mid)
	for i := 0; i < mid-left; i++ {
		L[i] = a[left+i]
	}
	for i := 0; i < right-mid; i++ {
		R[i] = a[mid+i]
	}
	L = append(L, INF)
	R = append(R, INF)
	i, j := 0, 0
	cnt := 0
	for k := left; k < right; k++ {
		if L[i] <= R[j] {
			a[k] = L[i]
			i++
		} else {
			a[k] = R[j]
			j++
			cnt += mid - i
		}
	}
	return cnt
}

const INF = 1000000000

