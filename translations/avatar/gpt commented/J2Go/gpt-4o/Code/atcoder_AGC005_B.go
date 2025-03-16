package main

import (
	"container/list"
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)

	// Initialize a slice to hold the input values
	a := make([]int, N)

	// Populate the slice with input values
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}

	// Slices to hold the counts of elements to the left and right of each element
	leftl := make([]int, N)
	rightl := make([]int, N)

	// List to help with calculating the left and right counts
	que := list.New()

	// Calculate the right counts for each element
	for index := 0; index < N; index++ {
		// While the list is not empty and the current element is smaller than the element at the front of the list
		for que.Len() > 0 && a[que.Back().Value.(int)] > a[index] {
			// Remove the index from the list and calculate the right count
			ind := que.Remove(que.Back()).(int)
			rightl[ind] = index - ind - 1
		}
		// Push the current index onto the list
		que.PushBack(index)
	}

	// For any remaining indices in the list, calculate the right counts
	for que.Len() > 0 {
		ind := que.Remove(que.Back()).(int)
		rightl[ind] = N - ind - 1
	}

	// Reset index to calculate left counts
	for index := N - 1; index >= 0; index-- {
		// While the list is not empty and the current element is smaller than the element at the front of the list
		for que.Len() > 0 && a[que.Back().Value.(int)] > a[index] {
			// Remove the index from the list and calculate the left count
			ind := que.Remove(que.Back()).(int)
			leftl[ind] = ind - index - 1
		}
		// Push the current index onto the list
		que.PushBack(index)
	}

	// For any remaining indices in the list, calculate the left counts
	for que.Len() > 0 {
		ind := que.Remove(que.Back()).(int)
		leftl[ind] = ind - N + 1
	}

	// Calculate the final answer based on the left and right counts
	var ans int64 = 0
	for i := 0; i < N; i++ {
		// For each element, multiply its value by the number of valid subarrays it can form
		ans += int64(a[i]) * int64(leftl[i]+1) * int64(rightl[i]+1)
	}

	// Output the final result
	fmt.Println(ans)
}

// <END-OF-CODE>
