
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the values of n, k, x, and y from the standard input
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(reader))
	k, _ := strconv.Atoi(read(reader))
	x, _ := strconv.Atoi(read(reader))
	y, _ := strconv.Atoi(read(reader))

	// Initialize the sum to 0, which will accumulate the total cost
	sum := 0

	// Loop through numbers from 1 to n
	for i := 1; i <= n; i++ {
		// If the current number i is greater than k, add y to sum
		// Otherwise, add x to sum
		if i > k {
			sum += y
		} else {
			sum += x
		}
	}

	// Output the total sum, which is the cost calculated based on the input parameters
	fmt.Println(sum)
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

// 