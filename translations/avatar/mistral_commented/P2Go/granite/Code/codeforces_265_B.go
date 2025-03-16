
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Ask the user for the number of elements in the list
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())

	// Initialize an empty list to store the integers
	l := make([]int, n)

	// Iterate n times and read each integer from the user
	for i := 0; i < n; i++ {
		// Ask the user for the next integer and store it in the list
		l[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).Scan())
	}

	// Initialize a variable to store the answer
	ans := n - 1

	// Initialize a variable to store the previous integer in the list
	last := 0

	// Iterate through each integer in the list
	for i := 0; i < n; i++ {
		// Calculate the absolute difference between the previous integer and the current integer
		// Add 1 to account for the number of steps between the two integers
		ans += int(math.Abs(float64(last - l[i]))) + 1

		// Update the value of the previous integer
		last = l[i]
	}

	// Print the value of the answer
	fmt.Println(ans)
}
