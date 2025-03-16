package main

import (
	"fmt"
	"math"
)

const MAXN = 200000 + 10 // maximum size of the array
const INF = math.MaxInt32

var a [MAXN]int
var L, R [MAXN / 2]int // auxiliary arrays 'L' and 'R'

func merge(left, mid, right int) int64 { // function to merge two sorted subarrays
	n1 := mid - left
	n2 := right - mid
	cnt := int64(0) // counter to store the number of inversions

	// copy the elements of the first subarray to 'L' array
	for i := 0; i < n1; i++ {
		L[i] = a[left+i]
	}

	// copy the elements of the second subarray to 'R' array
	for i := 0; i < n2; i++ {
		R[i] = a[mid+i]
	}

	// set the last elements of 'L' and 'R' arrays as INF
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
			cnt += int64(n1 - i) // update the counter 'cnt' with the number of inversions caused by this swap
		}
	}

	return cnt // return the number of inversions caused by merging the two subarrays
}

func mergesort(left, right int) int64 { // recursive function to sort the subarrays using merge sort algorithm
	if left+1 < right { // if the size of the subarray is greater than 1
		mid := (left + right) / 2 // find the middle index
		v1 := mergesort(left, mid) // recursively sort the left subarray and calculate the number of inversions
		v2 := mergesort(mid, right) // recursively sort the right subarray and calculate the number of inversions
		v3 := merge(left, mid, right) // merge the two sorted subarrays and calculate the number of inversions
		return v1 + v2 + v3 // return the total number of inversions caused by sorting the subarrays
	}
	return 0 // if the size of the subarray is 1, the array is already sorted and there are no inversions
}

func main() { // main function to read the input and call the mergesort function
	var n int
	fmt.Scan(&n) // read the size of the array
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // read the elements of the array
	}
	ans := mergesort(0, n) // call the mergesort function to sort the array and calculate the number of inversions
	fmt.Println(ans) // print the number of inversions
}

// <END-OF-CODE>
