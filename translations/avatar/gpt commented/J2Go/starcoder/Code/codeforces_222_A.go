package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements (n) and the threshold (k)
	fmt.Println("Enter the number of elements (n) and the threshold (k):")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	n, k := strings.Split(input, " ")
	n, _ = strconv.Atoi(n)
	k, _ = strconv.Atoi(k)

	// Loop through each element to count consecutive occurrences
	l := 0
	c := 1
	for i := 0; i < n; i++ {
		// Read the next integer from input
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		a, _ := strconv.Atoi(input)

		// Check if the current number is the same as the last one
		if a == l {
			c += 1
		} else {
			c = 1
		}

		// Update the last number to the current one
		l = a
	}

	// Check if the count of consecutive numbers plus k exceeds n
	if c+k > n {
		// If true, print the number of elements that are not part of the consecutive sequence
		fmt.Println(n - c)
	} else {
		// Otherwise, print -1 indicating the condition is not met
		fmt.Println(-1)
	}
}

