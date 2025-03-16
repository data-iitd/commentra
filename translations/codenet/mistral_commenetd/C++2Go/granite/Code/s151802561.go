
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Print("Enter the number of elements: ")
	fmt.Scanln(&n)

	A := make([]int, n)
	fmt.Print("Enter ", n, " integers:\n")
	for i := 0; i < n; i++ {
		fmt.Scanln(&A[i])
	}

	fmt.Println("Sorting the array using Selection Sort algorithm:")
	sw := 0
	for i := 0; i < n; i++ {
		mini := i
		for j := i; j < n; j++ {
			if A[j] < A[mini] {
				mini = j
			}
		}
		t := A[i]
		A[i] = A[mini]
		A[mini] = t

		if i!= mini {
			sw++
		}
	}

	fmt.Print("Sorted array: ")
	for i := 0; i < n; i++ {
		if i!= 0 {
			fmt.Print(" ")
		}
		fmt.Print(A[i])
	}
	fmt.Println()

	fmt.Println("Number of swaps:", sw)
}

