package main // Defining the main package

import (
	"fmt" // Importing the fmt package for formatted I/O
	"sort" // Importing the sort package for sorting slices
)

func main() { // Defining the main function that is executed when the program runs
	var N int // Declaring a variable N to hold the number of elements
	var x int64 // Declaring a variable x to hold the target value

	fmt.Scan(&N) // Reading the number of elements in the list from standard input
	fmt.Scan(&x) // Reading the target value from standard input

	sweet := make([]int64, 0, N) // Creating a slice of int64 type named sweet to store the elements

	for i := 0; i < N; i++ { // A for loop to read and add N elements to the slice
		var a int64 // Declaring a variable a to hold the current element
		fmt.Scan(&a) // Reading an element from standard input
		sweet = append(sweet, a) // Adding the element to the slice
	}

	sort.Slice(sweet, func(i, j int) bool { // Sorting the slice in ascending order
		return sweet[i] < sweet[j]
	})

	num := 0 // Initializing a variable named num to keep track of the number of elements that can be subtracted from x

	for i := 0; i < N; i++ { // A for loop to find the number of elements that can be subtracted from x
		if x-sweet[num] >= 0 { // Checking if x is greater than or equal to the current element in the slice
			x -= sweet[num] // Subtracting the current element from x
			num++ // Incrementing the num variable
		} else { // If x is less than the current element in the slice
			break // Exiting the for loop
		}
	}

	if num == N && x > 0 { // Checking if all the elements in the slice have been subtracted from x and x is still greater than 0
		num-- // Decrementing the num variable by 1 as the last element that was subtracted from x is not included in the count
	}

	fmt.Println(num) // Printing the number of elements that can be subtracted from x
}

// <END-OF-CODE>
