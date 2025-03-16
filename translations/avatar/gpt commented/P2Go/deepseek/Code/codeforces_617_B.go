package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	var a string
	fmt.Scanln(&a)  // Read an input line (not used in further calculations)

	// Check if the string contains any '1's
	// If there are no '1's, print 0
	// Otherwise, calculate the product of counts of '0's between '1's
	if !strings.Contains(a, "1") {
		fmt.Println(0)
	} else {
		segments := strings.Split(strings.Trim(a, "0 "), "1")
		product := 1
		for _, segment := range segments {
			product *= len(segment) + 1
		}
		fmt.Println(product)
	}
}
