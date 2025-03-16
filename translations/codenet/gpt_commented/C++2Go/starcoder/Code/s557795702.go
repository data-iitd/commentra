package main

import (
	"fmt"
	"os"
	"sort"
)

// Define a type alias for long long
type LL int64

// Define the maximum size for the array
const MAXN = 2*1e5 + 10

// Define the array and temporary arrays for merging
var a [MAXN]int
var L [MAXN/2]int
var R [MAXN/2]int

// Function to merge two halves of the array and count inversions
func merge(left, mid, right int) LL {
	var i, j, k LL
	var cnt LL = 0
	var n1, n2 int = mid - left, right - mid

	// Copy data to temporary arrays L and R
	for i = 0; i < n1; i++ {
		L[i] = a[left + i]
	}
	for i = 0; i < n2; i++ {
		R[i] = a[mid + i]
	}

	// Sentinel values to avoid out-of-bounds access
	L[n1] = R[n2] = 1e18

	i, j = 0, 0
	// Merge the two subarrays back into the original array
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

// Function to perform mergesort and count inversions
func mergesort(left, right int) LL {
	var mid, v1, v2, v3 LL
	// Base case: if the subarray has more than one element
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
	var n, ans LL
	fmt.Fscan(os.Stdin, &n)
	for i := 0; i < n; i++ {
		fmt.Fscan(os.Stdin, &a[i])
	}
	ans = mergesort(0, n)
	fmt.Println(ans)
}

