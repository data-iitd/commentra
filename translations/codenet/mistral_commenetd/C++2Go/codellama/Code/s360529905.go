package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int // declare integer N
	fmt.Scan(&N) // read the number of elements from the standard input
	a := make([]int, N) // allocate memory for an array of size N and assign the address to pointer a
	b := make([]int, N) // allocate memory for an array of size N and assign the address to pointer b

	for i := 0; i < N; i++ { // iterate through the array a and assign each element to b
		fmt.Scan(&a[i]) // read an integer from the standard input and assign it to the ith position in array a
		b[i] = a[i] // copy the value of the ith position in array a to the ith position in array b
	}

	sort.Ints(b) // sort the elements in array b in ascending order

	frontHalf := b[N/2-1] // assign the middle value of the first half of the sorted array b to frontHalf
	backHalf := b[N/2] // assign the middle value of the second half of the sorted array b to backHalf

	for i := 0; i < N; i++ { // iterate through the array a and print the appropriate middle value based on the condition
		if a[i] < backHalf { // if the value at the ith position in array a is less than the middle value of the second half of the sorted array b
			fmt.Println(backHalf) // print the middle value of the second half of the sorted array b
		} else {
			fmt.Println(frontHalf) // print the middle value of the first half of the sorted array b
		}
	}

	// deallocate the memory allocated for array a
	a = nil
	// deallocate the memory allocated for array b
	b = nil
}

