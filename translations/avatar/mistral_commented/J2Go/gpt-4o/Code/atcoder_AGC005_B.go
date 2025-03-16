package main

import (
	"container/list"
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N) // Reading the number of elements in the array from the console
	a := make([]int, N) // Creating an integer slice of size N

	// Reading the elements of the array from the console and storing them in the slice
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}

	leftl := make([]int, N) // Creating a slice to store the length of the left segment for each element
	rightl := make([]int, N) // Creating a slice to store the length of the right segment for each element
	que := list.New() // Creating a new list to implement a double ended queue

	index := 0 // Initializing the index variable to traverse the array

	// Finding the length of the left and right segments for each element using two stacks
	for index < N {
		for que.Len() > 0 && a(que.Back().Value.(int)) > a[index] { // Popping the elements from the queue whose right segment length is to be calculated
			ind := que.Remove(que.Back()).(int) // Storing the index of the popped element
			rightl[ind] = index - ind - 1 // Calculating the length of the right segment for the popped element
		}
		que.PushBack(index) // Pushing the current index into the queue
		index++
	}

	// Calculating the length of the right segment for the last element
	for que.Len() > 0 {
		ind := que.Remove(que.Back()).(int)
		rightl[ind] = N - ind - 1
	}

	index = N - 1 // Initializing the index variable to traverse the array in reverse order

	// Finding the length of the left segments for each element using two stacks in reverse order
	for index >= 0 {
		for que.Len() > 0 && a(que.Back().Value.(int)) > a[index] { // Popping the elements from the queue whose left segment length is to be calculated
			ind := que.Remove(que.Back()).(int)
			leftl[ind] = ind - index - 1 // Calculating the length of the left segment for the popped element
		}
		que.PushBack(index) // Pushing the current index into the queue
		index--
	}

	// Calculating the length of the left segment for the first element
	for que.Len() > 0 {
		ind := que.Remove(que.Back()).(int)
		leftl[ind] = ind - index - 1
	}

	ans := int64(0) // Initializing the variable to store the final answer

	// Calculating the answer by multiplying the element, left segment length, and right segment length for each element
	for i := 0; i < N; i++ {
		ans += int64(a[i]) * int64(leftl[i]+1) * int64(rightl[i]+1)
	}

	// Printing the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
