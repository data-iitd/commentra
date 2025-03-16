package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read two integers n and m from input
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	// Read a list of n integers from input
	input, _ = reader.ReadString('\n')
	parts = strings.Split(strings.TrimSpace(input), " ")
	l := make([]int, n)
	for i := 0; i < n; i++ {
		l[i], _ = strconv.Atoi(parts[i])
	}

	// Initialize an empty list to store the results after processing the input list
	l2 := make([]int, n)

	// Iterate through each element in the input list
	for i := 0; i < n; i++ {
		// If the current element is divisible by m, append the quotient to l2
		if l[i] % m == 0 {
			l2[i] = l[i] / m
		} else {
			// If the current element is not divisible by m, append the quotient plus one to l2
			l2[i] = l[i] / m + 1
		}
	}

	// Find the maximum value in the processed list l2
	mx := l2[0]
	ind := 0
	for i := 1; i < n; i++ {
		if l2[i] > mx {
			mx = l2[i]
			ind = i
		}
	}

	// Print the index of the maximum value (1-based index)
	fmt.Println(ind + 1)
}
