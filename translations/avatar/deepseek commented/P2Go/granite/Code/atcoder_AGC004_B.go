
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the values of n and x
	reader := bufio.NewReader(os.Stdin)
	nStr, _ := reader.ReadString('\n')
	xStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr)
	x, _ := strconv.Atoi(xStr)

	// Read the list of integers a
	aStr, _ := reader.ReadString('\n')
	aStr = aStr[:len(aStr)-1]  // Remove the trailing newline
	a := make([]int, n)
	for i, s := range strings.Split(aStr, " ") {
		a[i], _ = strconv.Atoi(s)
	}

	// Initialize a 2D list b with None values
	// b[j][i] will store the minimum value in the circular array from i to j
	b := make([][]int, n)
	for i := range b {
		b[i] = make([]int, n)
	}

	// Calculate the minimum value in a circular array for each starting position i and ending position j
	for i := 0; i < n; i++ {
		m := a[i]  // Initialize m with the current element
		for j := 0; j < n; j++ {
			k := i - j  // Calculate the index in the circular array
			if k < 0 {
				k += n  // Adjust k if it is negative
			}
			m = min(m, a[k])  // Update m with the minimum value in the circular array
			b[j][i] = m  // Store the minimum value in b
		}
	}

	// Find the minimum sum of each row in b plus x times the row index
	m := 1000000000
	for i, j := range b {
		sum := 0
		for _, v := range j {
			sum += v
		}
		sum += x * i
		m = min(m, sum)
	}

	// Print the minimum value found
	fmt.Println(m)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

