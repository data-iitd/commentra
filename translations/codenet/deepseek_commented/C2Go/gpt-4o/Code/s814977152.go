package main

import (
	"fmt"
	"sort"
)

// Comparator function for sorting
type IntSlice []int

func (p IntSlice) Len() int           { return len(p) }
func (p IntSlice) Less(i, j int) bool { return p[i] < p[j] }
func (p IntSlice) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }

func binarySearch(arr []int, target int) int {
	left, right := 0, len(arr)-1
	for left <= right {
		mid := left + (right-left)/2
		if arr[mid] == target {
			return mid
		} else if arr[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return -1 // Not found
}

func main() {
	var N int
	fmt.Scan(&N)

	A := make([]int, N)
	tomatu := make([]int, N)
	mikakosi := make([]bool, N)

	// Read the array A from the input and simultaneously copy it to tomatu
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
		tomatu[i] = A[i]
	}

	// Sort the array tomatu
	sort.Sort(IntSlice(tomatu))

	// Store unique elements in tomatu
	yukinnko := 1
	for i := 1; i < N; i++ {
		if tomatu[i] != tomatu[yukinnko-1] {
			tomatu[yukinnko] = tomatu[i]
			yukinnko++
		}
	}

	// Iterate over the array A, use binarySearch to find the index, and toggle mikakosi
	for i := 0; i < N; i++ {
		kugyu := binarySearch(tomatu[:yukinnko], A[i])
		if kugyu != -1 {
			mikakosi[kugyu] = !mikakosi[kugyu]
		}
	}

	// Count and print the number of elements in mikakosi that are set to true
	emirinn := 0
	for i := 0; i < yukinnko; i++ {
		if mikakosi[i] {
			emirinn++
		}
	}
	fmt.Println(emirinn)
}

// <END-OF-CODE>
