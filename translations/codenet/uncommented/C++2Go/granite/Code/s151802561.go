
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)
	A := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &A[i])
	}

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

	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(A[i])
	}
	fmt.Println()
	fmt.Println(sw)
}
