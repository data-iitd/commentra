
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	// Read an integer input from the user
	N, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[2:])

	// Read 5 integer inputs from the user and store them in a slice A
	A := make([]int, 5)
	for i := 0; i < 5; i++ {
		A[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[2:])
	}

	// Calculate the minimum value from the slice A, divide N by this minimum value,
	// take the ceiling of the result, and add 4 to it before printing the final result
	fmt.Println(int(math.Ceil(float64(N)/float64(min(A)))))
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

