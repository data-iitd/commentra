package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read an integer input from the user
	var N int
	fmt.Fscan(reader, &N)

	// Read 5 integer inputs from the user and store them in a slice A
	A := make([]int, 5)
	for i := 0; i < 5; i++ {
		fmt.Fscan(reader, &A[i])
	}

	// Calculate the minimum value from the slice A, divide N by this minimum value,
	// take the ceiling of the result, and add 4 to it before printing the final result
	minA := A[0]
	for _, value := range A {
		if value < minA {
			minA = value
		}
	}
	result := math.Ceil(float64(N) / float64(minA)) + 4
	fmt.Fprintln(writer, int(result))
}
