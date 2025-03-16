<<<<<<< HEAD

import (
	"fmt"
	"os"
	"sort"
)

// <START-OF-CODE>

const MAXN = 2*1e5 + 10

func merge(left, mid, right int) int {
	var cnt int
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
	L[n1] = R[n2] = 1e9
	i, j := 0, 0
	for k := left; k < right; k++ {
=======
package main
import "fmt"
import "math"

// global variables
var n int
var a []int

// function to merge two sorted subarrays
func merge(left, mid, right int) int {
	var i, j, k int
	var cnt int // counter to store the number of inversions
	var n1, n2 int // size of the first subarray and the second subarray
	n1 = mid - left
	n2 = right - mid

	// copy the elements of the first subarray to 'L' array
	for i = 0; i < n1; i++ {
		L[i] = a[left+i]
	}

	// copy the elements of the second subarray to 'R' array
	for i = 0; i < n2; i++ {
		R[i] = a[mid+i]
	}

	// set the last elements of 'L' and 'R' arrays as INF
	L[n1] = R[n2] = math.MaxInt32

	// merge the two sorted subarrays and update the array 'a' accordingly
	i = j = 0
	for k = left; k < right; k++ {
>>>>>>> 98c87cb78a (data updated)
		if L[i] <= R[j] {
			a[k] = L[i]
			i++
		} else {
			a[k] = R[j]
			j++
			cnt += n1 - i
		}
	}
<<<<<<< HEAD
	return cnt
}

func mergesort(left, right int) int {
	var v1, v2, v3 int
	if left+1 < right {
		mid := (left + right) / 2
		v1 = mergesort(left, mid)
		v2 = mergesort(mid, right)
		v3 = merge(left, mid, right)
		return v1 + v2 + v3
	}
	return 0
}

func main() {
	var n int
	fmt.Fscan(os.Stdin, &n)
	for i := 0; i < n; i++ {
		fmt.Fscan(os.Stdin, &a[i])
	}
	ans := mergesort(0, n)
	fmt.Println(ans)
}

// 
=======

	return cnt
}

// recursive function to sort the subarrays using merge sort algorithm
func mergesort(left, right int) int {
	var mid int
	var v1, v2, v3 int // variables to store the number of inversions caused by sorting the subarrays

	if left+1 < right { // if the size of the subarray is greater than 1
		mid = (left+right)/2
		v1 = mergesort(left, mid) // recursively sort the left subarray and calculate the number of inversions
		v2 = mergesort(mid, right) // recursively sort the right subarray and calculate the number of inversions
		v3 = merge(left, mid, right) // merge the two sorted subarrays and calculate the number of inversions
		return v1+v2+v3 // return the total number of inversions caused by sorting the subarrays
	}
	return 0 // if the size of the subarray is 1, the array is already sorted and there are no inversions
}

func main() {
	// read the size of the array
	fmt.Scanf("%d\n", &n)

	// read the elements of the array
	for i := 0; i < n; i++ {
		fmt.Scanf("%d\n", &a[i])
	}

	// call the mergesort function to sort the array and calculate the number of inversions
	ans := mergesort(0, n)

	// print the number of inversions
	fmt.Printf("%d\n", ans)
}

>>>>>>> 98c87cb78a (data updated)
