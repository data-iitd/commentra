package main

import (
	"fmt"
	"math"
)

const INF = math.MaxInt32 // Define a constant INF for initializing arrays.
const MAXN = 200010       // Define a constant MAXN for the maximum number of elements in the array.

var a [MAXN]int
var L, R [MAXN / 2]int // Declare arrays L and R to temporarily store the left and right halves of the array during merge sort.

func merge(left, mid, right int) int64 {
	var cnt int64 = 0
	n1 := mid - left
	n2 := right - mid

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
			cnt += int64(n1 - i)
		}
	}
	return cnt
}

func mergesort(left, right int) int64 {
	if left+1 < right {
		mid := (left + right) / 2
		v1 := mergesort(left, mid)
		v2 := mergesort(mid, right)
		v3 := merge(left, mid, right)
		return v1 + v2 + v3
	}
	return 0
}

func main() {
	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	ans := mergesort(0, n)
	fmt.Println(ans)
}

// <END-OF-CODE>
