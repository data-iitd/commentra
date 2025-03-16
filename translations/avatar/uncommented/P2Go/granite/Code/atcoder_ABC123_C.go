
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	var N int
	fmt.Fscanf(in, "%d\n", &N)
	A := make([]int, 5)
	for i := 0; i < 5; i++ {
		fmt.Fscanf(in, "%d\n", &A[i])
	}
	fmt.Fprintf(out, "%d\n", math.Ceil(float64(N)/float64(min(A))))
	out.Flush()
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

