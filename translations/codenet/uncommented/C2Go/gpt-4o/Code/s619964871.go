package main

import (
	"fmt"
	"math"
)

const unko = 1e12

func sort(a []int64, left, middle, right int) (cnt int64) {
	lArr := make([]int64, middle-left+1)
	rArr := make([]int64, right-middle+1)

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
			cnt += int64(middle-left-l)
		}
	}
	return
}

func merge(a []int64, left, right int) (cnt int64) {
	if left+1 < right {
		middle := (left + right) / 2
		cnt += merge(a, left, middle)
		cnt += merge(a, middle, right)
		cnt += sort(a, left, middle, right)
	}
	return
}

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	fmt.Println(merge(a, 0, n))
}

// <END-OF-CODE>
