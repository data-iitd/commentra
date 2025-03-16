package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Take an integer input `n` which represents the number of lists to be provided as input.
	var n int
	fmt.Scan(&n)

	// Initialize a counter `c` to 0. This will keep track of the number of lists where the sum of elements is greater than 1.
	c := 0

	// Loop `n` times to process each list of integers.
	for i := 0; i < n; i++ {
		// Take a list of integers as input.
		var input string
		fmt.Scan(&input)

		// Split the input string by spaces and convert them to integers.
		strs := strings.Split(input, " ")
		sum := 0
		for _, str := range strs {
			num, _ := strconv.Atoi(str)
			sum += num
		}

		// If the sum is greater than 1, increment the counter `c` by 1.
		if sum > 1 {
			c++
		}
	}

	// After the loop completes, print the final value of `c`, which represents the number of lists where the sum of elements is greater than 1.
	fmt.Println(c)
}

// <END-OF-CODE>
