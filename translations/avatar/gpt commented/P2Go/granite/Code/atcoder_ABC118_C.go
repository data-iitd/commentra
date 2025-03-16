
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input N, which represents the number of elements in the list
	N, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())

	// Read a line of input, split it into individual string elements, convert them to integers,
	// and store them in a list A
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(strings.Split(bufio.NewReader(os.Stdin).Scan(), " ")[i])
	}

	// Import necessary modules for calculating the greatest common divisor (GCD)
	import "math/big"

	// Calculate the GCD of all elements in the list A using big.Int
	gcd := big.NewInt(0)
	for _, a := range A {
		gcd.GCD(gcd, nil, gcd, big.NewInt(int64(a)))
	}

	// Print the calculated GCD
	fmt.Println(gcd)
}
