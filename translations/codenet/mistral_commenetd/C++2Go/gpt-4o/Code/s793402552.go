package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	// Read two integers `a` and `b` from the standard input
	var a, b int
	fmt.Scan(&a, &b)

	// Convert the integer `b` to a string `bstr`
	bstr := strconv.Itoa(b)

	// Calculate the number `num` as the product of `a` and 10 raised to the power of the length of the string `bstr`, plus the integer `b`
	num := a*int(math.Pow(10, float64(len(bstr)))) + b

	// Initialize a loop counter `i`
	var i int

	// Enter a `for` loop that runs from `1` to `100100`
	for i = 1; i <= 100100; i++ {
		// Inside the loop, check if the square of `i` is equal to the number `num`
		if i*i == num {
			// If it is, break out of the loop
			break
		}
	}

	// If the loop completes without finding a square root of `num`, print "No" to the standard output
	if i > 100100 {
		fmt.Println("No")
	} else {
		// If we find a square root of `num` inside the loop, print "Yes" to the standard output
		fmt.Println("Yes")
	}
}

// <END-OF-CODE>
