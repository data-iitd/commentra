package main

import (
	"fmt"
	"math"
)

const INF = 0x3f3f3f3f
const MAXN = 2 * 1e5 + 10

var a [MAXN]int
var n int
var L [MAXN / 2]int
var R [MAXN / 2]int

// Merge function: Merges two sorted halves of the array a from index left to right.
func merge(left, mid, right int) int {
	var i, j, k int
	var cnt int
	n1 := mid - left
	n2 := right - mid
	for i = 0; i < n1; i++ {
		L[i] = a[left+i]
	}
	for i = 0; i < n2; i++ {
		R[i] = a[mid+i]
	}
	L[n1] = INF
	R[n2] = INF
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

// Merge sort function: Recursively divides the array into halves and sorts them using merge sort.
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

// Main function: Synchronizes the input/output streams, reads the number of elements and the elements themselves, calls the merge sort function to sort the array and compute the number of inversions, and prints the number of inversions.
func main() {
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	ans := mergesort(0, n)
	fmt.Println(ans)
}

