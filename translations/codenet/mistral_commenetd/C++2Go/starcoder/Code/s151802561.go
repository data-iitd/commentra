<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		A [100]int
		n int
		i, j, t, sw, mini int
	)

	fmt.Println("Enter the number of elements: ")
	fmt.Scanf("%d", &n) // Read the number of elements from the standard input

	fmt.Println("Enter", n, "integers:")
	for i = 0; i < n; i++ { // Read %d integers from the standard input and store them in the array A
		fmt.Scanf("%d", &A[i])
	}

	fmt.Println("Sorting the array using Selection Sort algorithm:")
	for i = 0; i < n; i++ { // The outer loop runs n times
		mini = i
		for j = i; j < n; j++ { // The inner loop finds the minimum element in the unsorted part of the array
			if A[j] < A[mini] { // If A[j] is smaller than A[mini], update mini
				mini = j
			}
		}
		t = A[i] // Swap A[i] with the minimum element
		A[i] = A[mini]
		A[mini] = t

		if i!= mini {
			sw++ // Increment sw only if a swap is made
		}
	}

	fmt.Println("Sorted array: ")
	for i = 0; i < n; i++ { // Print the sorted array to the standard output
		if i!= 0 {
			fmt.Print(" ")
		}
		fmt.Print(A[i])
	}
	fmt.Println()

	fmt.Println("Number of swaps: ", sw)
}

