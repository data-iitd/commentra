package main

import (
	"fmt"
)

func main() {
	var A [100]int // An array of integers with a maximum size of 100
	var n int // The number of elements in the array
	var i, j, t, sw int // Variables used in the sorting algorithm
	var mini int

	fmt.Print("Enter the number of elements: ")
	fmt.Scan(&n) // Read the number of elements from the standard input

	fmt.Printf("Enter %d integers:\n", n)
	for i = 0; i < n; i++ { // Read %d integers from the standard input and store them in the array A
		fmt.Scan(&A[i])
	}

	fmt.Println("Sorting the array using Selection Sort algorithm:")
	for i = 0; i < n; i++ { // The outer loop runs n times
		mini = i // Initialize mini as i
		for j = i; j < n; j++ { // The inner loop finds the minimum element in the unsorted part of the array
			if A[j] < A[mini] { // If A[j] is smaller than A[mini], update mini
				mini = j
			}
		}
		t = A[i] // Swap A[i] with the minimum element
		A[i] = A[mini]
		A[mini] = t

		if i != mini { sw++ } // Increment sw only if a swap is made
	}

	fmt.Print("Sorted array: ")
	for i = 0; i < n; i++ { // Print the sorted array to the standard output
		if i > 0 { fmt.Print(" ") }
		fmt.Print(A[i])
	}
	fmt.Println()

	fmt.Printf("Number of swaps: %d\n", sw)
}

