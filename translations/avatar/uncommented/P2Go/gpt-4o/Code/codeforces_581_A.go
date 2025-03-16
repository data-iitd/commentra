package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	minVal := a
	if b < a {
		minVal = b
	}
	maxVal := a
	if b > a {
		maxVal = b
	}
	fmt.Println(minVal, (maxVal-minVal)/2)
}

// <END-OF-CODE>
