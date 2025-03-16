package main // Defining the main package

import (
	"fmt" // Importing the fmt package for formatted I/O
	"sort" // Importing the sort package for sorting slices
)

func main() { // Defining the main function that is executed when the program runs
	var n int // Declaring an integer variable n
	var k int64 // Declaring a long integer variable k

	fmt.Scan(&n) // Reading the first integer value n from the standard input
	fmt.Scan(&k) // Reading the long integer value k from the standard input

	arr := make([]int64, n) // Creating a slice named arr of length n to store long integer values
	set := make(map[int64]struct{}) // Creating an empty map named set to store unique long integer values

	for i := 0; i < n; i++ { // Iterating through the slice arr from index 0 to n-1
		fmt.Scan(&arr[i]) // Reading a long integer value from the standard input and storing it in the arr[i] index
	}

	sort.Slice(arr, func(i, j int) bool { // Sorting the arr slice in ascending order
		return arr[i] < arr[j]
	})

	count := 0 // Initializing the count variable to 0

	for i := 0; i < n; i++ { // Iterating through the sorted arr slice from index 0 to n-1
		if arr[i]%k != 0 { // Checking if the arr[i] value is not divisible by k
			count++ // Incrementing the count variable if the condition is true
			set[arr[i]] = struct{}{} // Adding the arr[i] value to the set if it is not already present
		} else if _, exists := set[arr[i]/k]; !exists { // Checking if the arr[i] value is divisible by k and if its quotient is not present in the set
			count++ // Incrementing the count variable if the condition is true
			set[arr[i]] = struct{}{} // Adding the arr[i] value to the set if it is not already present
		}
	}

	fmt.Println(count) // Printing the count value to the standard output
}

// <END-OF-CODE>
