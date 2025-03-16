package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read two integers n and m from user input
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter n: ")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Print("Enter m: ")
	m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))

	// Initialize an array of size m to hold the results
	a := make([]int, m)

	// Check if n is divisible by m
	if n%m == 0 {
		// If divisible, fill the array with equal parts
		for i := 0; i < m; i++ {
			a[i] = n / m
		}
	} else {
		// If not divisible, calculate the base value for each part
		sub := n / m
		for i := 0; i < m; i++ {
			a[i] = sub
		}

		// Calculate the remainder that needs to be distributed
		test := n - (sub * m)
		count := 0

		// Distribute the remainder across the first few elements of the array
		for i := 0; i < test; i++ {
			a[count] = a[count] + 1
			count++

			// Wrap around if count exceeds the array length
			if count >= m {
				count = 0
			}
		}
	}

	// Print the array in reverse order
	for i := (m - 1); i >= 0; i-- {
		fmt.Print(a[i], " ")
	}
}

