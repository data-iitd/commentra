
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Ask the user for the number of elements in the list
	N, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())

	// Get a list of integers from the user input
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).Scan())
	}

	// Define a function to calculate the greatest common divisor (GCD) of two integers
	gcd := func(a, b int) int {
		for b!= 0 {
			a, b = b, a%b
		}
		return a
	}

	// Use reduce() from functools and gcd() from fractions to calculate the GCD of all integers in the list A
	gcd := A[0]
	for i := 1; i < N; i++ {
		gcd = gcd(gcd, A[i])
	}

	// Print the result, which is the GCD of all the integers in the list A
	fmt.Println(gcd)
}
