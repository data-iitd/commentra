
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Take an integer input `n` which represents the number of lists to be provided as input.
	n, _ := strconv.Atoi(readInput())

	// Initialize a counter `c` to 0. This will keep track of the number of lists where the sum of elements is greater than 1.
	c := 0

	// Loop `n` times to process each list of integers.
	for i := 0; i < n; i++ {
		// Take a list of integers as input, split them by spaces, convert them to integers, and store them in `l1`.
		l1 := stringToIntegerArray(readInput())

		// Calculate the sum of the elements in `l1`.
		// If the sum is greater than 1, increment the counter `c` by 1.
		if sum(l1) > 1 {
			c = c + 1
		}
	}

	// After the loop completes, print the final value of `c`, which represents the number of lists where the sum of elements is greater than 1.
	fmt.Println(c)
}

func readInput() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func stringToIntegerArray(s string) []int {
	a := strings.Split(s, " ")
	m := make([]int, len(a))
	for i, v := range a {
		num, _ := strconv.Atoi(v)
		m[i] = num
	}
	return m
}

func sum(a []int) int {
	sum := 0
	for _, v := range a {
		sum = sum + v
	}
	return sum
}

