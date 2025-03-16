package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input N, which represents the number of elements in the list
	var N int
	fmt.Scan(&N)

	// Read a line of input, split it into individual string elements, convert them to integers,
	// and store them in a list A
	var A []int
	fmt.Scan(&A)

	// Calculate the GCD of all elements in the list A using math.GCD
	var gcd int
	for _, a := range A {
		gcd = int(math.GCD(float64(gcd), float64(a)))
	}

	// Print the calculated GCD
	fmt.Println(gcd)
}

