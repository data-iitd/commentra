package main

import (
	"fmt"
	"math"
)

func main() {
	var x, y int64
	fmt.Scan(&x, &y)  // Read two integers from standard input
	if math.Abs(float64(x-y)) <= 1 {
		fmt.Println("Brown")  // Check if the absolute difference is less than or equal to 1
	} else {
		fmt.Println("Alice")  // Otherwise, print "Alice"
	}
}

