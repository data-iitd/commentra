package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N) // Read the first integer N from the standard input

	L := make([]int, N) // Create a slice of integers with a length of N

	for i := 0; i < N; i++ { // Read N integers from the standard input and add them to the slice
		fmt.Scan(&L[i])
	}

	sort.Ints(L) // Sort the slice using the sort package

	count := 0 // Initialize a counter variable to 0

	for i := 0; i < N; i++ { // Iterate through all pairs of elements in the sorted slice
		for j := i + 1; j < N; j++ {
			a := L[i] // Get the first integer of the pair
			b := L[j] // Get the second integer of the pair
			res := find(L, j+1, a+b) // Call the find() function to find the number of elements greater than the sum of the pair
			count += res // Add the result of the find() function to the counter variable
		}
	}

	fmt.Println(count) // Print the final value of the counter variable
}

func find(li []int, from, target int) int { // Define the find() function
	low := from // Initialize the lower bound of the binary search
	upp := len(li) - 1 // Initialize the upper bound of the binary search

	if upp-low < 0 { // Check if the slice is empty or the target integer is less than the first element
		return 0
	} else if li[from] >= target { // Check if the target integer is greater than or equal to the first element
		return 0
	} else if li[upp] < target { // Check if the target integer is less than the last element
		return upp - low + 1
	}

	for upp-low > 1 { // Perform the binary search
		mid := (low + upp) / 2 // Calculate the middle index of the binary search

		if li[mid] >= target { // If the middle element is greater than or equal to the target, update the upper bound of the search
			upp = mid
		} else { // If the middle element is less than the target, update the lower bound of the search
			low = mid
		}
	}

	return low - from + 1 // Return the index of the middle element minus the starting index plus one
}

// <END-OF-CODE>
