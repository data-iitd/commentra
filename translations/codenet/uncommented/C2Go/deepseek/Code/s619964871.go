package main

import (
	"fmt"
	"os"
)

const unko = 1e12

func sort(a []int64, left, middle, right int) int64 {
	lArr := make([]int64, middle-left+1)
	rArr := make([]int64, right-middle+1)
	cnt := int64(0)
	for i := 0; i < middle-left; i++ {
		lArr[i] = a[left+i]
	}
	for i := 0; i < right-middle; i++ {
		rArr[i] = a[middle+i]
	}
	lArr[middle-left] = unko
	rArr[right-middle] = unko
	l, r := 0, 0
	for i := 0; i < right-left; i++ {
		if lArr[l] <= rArr[r] {
			a[left+i] = lArr[l]
			l++
		} else {
			a[left+i] = rArr[r]
			r++
			cnt += int64(middle - left - l)
		}
	}
	return cnt
}

func merge(a []int64, left, right int) int64 {
	if left+1 < right {
		middle := (left + right) / 2
		x1 := merge(a, left, middle)
		x2 := merge(a, middle, right)
		x3 := sort(a, left, middle, right)
		return x1 + x2 + x3
	} else {
		return 0
	}
}

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	result := merge(a, 0, n)
	fmt.Println(result)
}

