package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	// Convert integer b to string to determine its length.
	bStr := strconv.Itoa(b)

	// Calculate a new number, num, by multiplying a with 10 raised to the power of the length of b (in string form), and then adding b to it.
	num := a * int(math.Pow(10, float64(len(bStr)))) + b

	// Check for a perfect square root of num.
	sqrt := int(math.Sqrt(float64(num)))
	if sqrt*sqrt == num {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
