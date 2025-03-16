
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read two integers n and m from input, where n is the number of elements and m is the divisor
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(reader))
	m, _ := strconv.Atoi(read(reader))

	// Read a list of n integers from input
	l := make([]int, n)
	for i := 0; i < n; i++ {
		l[i], _ = strconv.Atoi(read(reader))
	}

	// Initialize an empty list to store the results after processing the input list
	l2 := make([]int, n)

	// Iterate through each element in the input list
	for i := 0; i < n; i++ {
		// If the current element is divisible by m, append the quotient to l2
		if l[i]%m == 0 {
			l2[i] = l[i] / m
		} else {
			// If the current element is not divisible by m, append the quotient plus one to l2
			l2[i] = l[i]/m + 1
		}
	}

	// Find the maximum value in the processed list l2
	mx := 0
	for i := 0; i < n; i++ {
		if l2[i] > mx {
			mx = l2[i]
		}
	}

	// Iterate through the range of n to find the index of the maximum value in l2
	for i := 0; i < n; i++ {
		if l2[i] == mx {
			fmt.Println(i + 1)  // Print the index of the maximum value (1-based index)
			return
		}
	}
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

