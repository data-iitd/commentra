

package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(reader.ReadLine())
	A := make([]int, 5)
	for i := 0; i < 5; i++ {
		A[i], _ = strconv.Atoi(reader.ReadLine())
	}
	fmt.Println(math.Ceil(float64(N)/float64(min(A))) + 4)
}

func min(A []int) int {
	m := A[0]
	for _, a := range A {
		if a < m {
			m = a
		}
	}
	return m
}

// Step 1: Import necessary modules for mathematical operations and input/output operations.

// Step 2: Read an integer input N which represents some quantity or value.

// Step 3: Read five integer inputs and store them in a slice A. This slice will be used to determine the minimum value among these integers.

// Step 4: Calculate the result by dividing N by the smallest value in A and rounding up to the nearest integer, then add 4 to the result. Finally, print the result.

