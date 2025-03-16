<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare and initialize variables
	var N int
	fmt.Scanf("%d\n", &N)
	A := make([]int, N+1)
	B := make([]int, N)
	var i int

	// Read the elements of array A from the standard input
	for i = 0; i < N+1; i++ {
		fmt.Scanf("%d\n", &A[i])
	}

	// Read the elements of array B from the standard input
	for i = 0; i < N; i++ {
		fmt.Scanf("%d\n", &B[i])
	}

	ans := 0

	// Nested for loop to compare each pair of elements from arrays A and B
	for i = 0; i < N; i++ {
		//site i
		if A[i] >= B[i] {
			ans = ans + B[i]
			A[i] = A[i] - B[i]
			B[i] = 0
		} else {
			ans = ans + A[i]
			B[i] = B[i] - A[i]
			A[i] = 0
		}

		//site i + 1
		if A[i+1] >= B[i] {
			ans = ans + B[i]
			A[i+1] = A[i+1] - B[i]
			B[i] = 0
		} else {
			ans = ans + A[i+1]
			B[i] = B[i] - A[i+1]
			A[i+1] = 0
		}
	}

	// Print the final answer
	fmt.Printf("%d\n", ans)
}

