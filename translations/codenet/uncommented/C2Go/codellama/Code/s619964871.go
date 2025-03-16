/*
 * FileName:     the_number_of_inversions_fix
 * CreatedDate:  2020-06-05 16:25:10 +0900
 * LastModified: 2020-07-06 22:22:35 +0900
 */

package main

import (
	"fmt"
	"math"
)

func sort(a []int, left, middle, right int) int {
	l_arr := make([]int, middle-left+1)
	r_arr := make([]int, right-middle+1)
	cnt := 0
	for i := 0; i < middle-left; i++ {
		l_arr[i] = a[i+left]
	}
	for i := 0; i < right-middle; i++ {
		r_arr[i] = a[i+middle]
	}
	l_arr[middle-left] = math.MaxInt64
	r_arr[right-middle] = math.MaxInt64
	l, r := 0, 0
	for i := 0; i < right-left; i++ {
		if l_arr[l] <= r_arr[r] {
			a[left+i] = l_arr[l]
			l++
		} else {
			a[left+i] = r_arr[r]
			r++
			cnt += middle - left - l
		}
	}
	return cnt
}

func merge(a []int, left, right int) int {
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
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	fmt.Println(merge(a, 0, n))
}

