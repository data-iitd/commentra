package main

import (
	"fmt"
	"sort"
)

// Function to perform binary search on the sorted array
func binarySearch(arr []int, target int) int {
	left, right := 0, len(arr)-1
	for left <= right {
		mid := left + (right-left)/2
		if arr[mid] == target {
			return mid // Found the element
		} else if arr[mid] < target {
			left = mid + 1 // Search in the right half
		} else {
			right = mid - 1 // Search in the left half
		}
	}
	return -1 // Element not found
}

func main() {
	var N int // Number of elements
	fmt.Scan(&N)

	A := make([]int, N) // Array to hold input elements
	tomatu := make([]int, N) // Array to hold sorted elements
	mikakosi := make([]int, N) // Array to track occurrences of elements

	// Read the elements into array A and copy to tomatu
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
		tomatu[i] = A[i] // Copying input to sorted array
	}

	// Sort the array of elements
	sort.Ints(tomatu)

	// Remove duplicates from the sorted array
	yukinnko := 1 // Count of unique elements
	for i := 1; i < N; i++ {
		if tomatu[i] != tomatu[yukinnko-1] {
			tomatu[yukinnko] = tomatu[i] // Add unique element
			yukinnko++
		}
	}

	// Track occurrences of each element in the original array
	for i := 0; i < N; i++ {
		kugyu := binarySearch(tomatu[:yukinnko], A[i]) // Find index of element in sorted array
		if kugyu != -1 {
			mikakosi[kugyu] = 1 - mikakosi[kugyu] // Toggle occurrence
		}
	}

	// Count the number of unique elements
	emirinn := 0 // Counter for unique elements
	for i := 0; i < yukinnko; i++ {
		if mikakosi[i] == 1 {
			emirinn++ // Increment count for unique occurrences
		}
	}

	// Output the count of unique elements
	fmt.Println(emirinn)
}
