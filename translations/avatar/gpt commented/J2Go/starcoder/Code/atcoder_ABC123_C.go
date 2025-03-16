package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read a long integer N from user input
	var N int64
	fmt.Scanf("%d", &N)

	// Initialize a variable to hold the minimum value
	var min int64

	// Loop to read five long integers and find the minimum
	for i := 0; i < 5; i++ {
		// For the first iteration, directly assign the value to min
		if i == 0 {
			fmt.Scanf("%d", &min)
		} else {
			// For subsequent iterations, update min if a smaller value is found
			var x int64
			fmt.Scanf("%d", &x)
			if x < min {
				min = x
			}
		}
	}

	// Calculate the result by dividing N by min, rounding up, and adding 4
	fmt.Printf("%d\n", int64(math.Ceil(float64(N)/float64(min)))+4)
}

