
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of test cases from standard input
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])

	// Initialize variables
	h := make([]int, n)
	max := -1
	flag := 0

	// Read and process input
	for i := 0; i < n; i++ {
		// Read the next integer from standard input and store it in the array h
		h[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])

		// Update the maximum height if the current height is greater
		if max < h[i] {
			max = h[i]
		}

		// Check if the difference between the current height and maximum height is greater than or equal to 2
		if max-h[i] >= 2 {
			flag = 1
		}
	}

	// Check the value of the flag and print the appropriate message to the standard output
	if flag == 1 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}

