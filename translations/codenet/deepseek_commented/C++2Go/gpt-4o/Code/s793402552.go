package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	// Convert b to string to determine its length
	bstr := strconv.Itoa(b)

	// Calculate num by multiplying a with 10 raised to the power of the length of b, then adding b
	num := a*int(math.Pow(10, float64(len(bstr)))) + b

	var i int
	for i = 1; i <= 100100; i++ {
		if i*i == num {
			break
		}
	}

	// Check if the loop finished due to finding a perfect square root of num
	if i > 100100 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}

// <END-OF-CODE>
