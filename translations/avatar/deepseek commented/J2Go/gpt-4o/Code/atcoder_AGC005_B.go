package main

import (
	"container/list"
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N) // Reading the number of elements N
	a := make([]int, N) // Initializing the array a with size N

	// Reading N elements and storing them in the array a
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}

	// Initializing slices to store the distances to the nearest smaller elements
	leftl := make([]int, N)
	rightl := make([]int, N)

	// Using a list to find the nearest smaller element to the right
	que := list.New()
	index := 0
	for index < N {
		for que.Len() > 0 && a[que.Back().Value.(int)] > a[index] {
			ind := que.Remove(que.Back()).(int)
			rightl[ind] = index - ind - 1 // Calculating the distance
		}
		que.PushBack(index) // Adding the current index to the deque
		index++
	}
	for que.Len() > 0 {
		ind := que.Remove(que.Back()).(int)
		rightl[ind] = N - ind - 1 // Calculating the distance for remaining elements
	}

	// Using a list to find the nearest smaller element to the left
	index = N - 1
	for index >= 0 {
		for que.Len() > 0 && a[que.Back().Value.(int)] > a[index] {
			ind := que.Remove(que.Back()).(int)
			leftl[ind] = ind - index - 1 // Calculating the distance
		}
		que.PushBack(index) // Adding the current index to the deque
		index--
	}
	for que.Len() > 0 {
		ind := que.Remove(que.Back()).(int)
		leftl[ind] = ind - index - 1 // Calculating the distance for remaining elements
	}

	// Calculating the result by summing up the products
	var ans int64 = 0
	for i := 0; i < N; i++ {
		ans += int64(a[i]) * int64(leftl[i]+1) * int64(rightl[i]+1)
	}

	// Printing the result
	fmt.Println(ans)
}

// <END-OF-CODE>
