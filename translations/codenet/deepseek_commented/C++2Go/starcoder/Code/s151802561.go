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
		A []int
		n int
		i int
		j int
		t int
		sw int = 0
		mini int
	)

	// Step 1: Reading the number of elements (n)
	fmt.Scanf("%d", &n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &A[i])
	}

	// Step 2: Reading the elements of the array
	// Step 3: Selection Sort Implementation
	for i = 0; i < n; i++ {
		mini = i
		// Find the index of the minimum element in the unsorted part of the array
		for j = i; j < n; j++ {
			if A[j] < A[mini] {
				mini = j
			}
		}
		// Swap the found minimum element with the first element of the unsorted part
		t = A[i]
		A[i] = A[mini]
		A[mini] = t
		// Increment the swap counter if a swap was made
		if i!= mini {
			sw++
		}
	}

	// Step 4: Counting the number of swaps
	// Step 5: Printing the sorted array
	for i = 0; i < n; i++ {
		if i!= 0 {
			fmt.Printf(" ")
		}
		fmt.Printf("%d", A[i])
	}
	fmt.Printf("\n")

	// Step 6: Printing the number of swaps
	fmt.Printf("%d\n", sw)
}

