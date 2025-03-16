
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables n and m for input size
	var n, m int

	// Read input values for n and m
	fmt.Scanln(&n, &m)

	// Declare variables k and a for intermediate calculations
	var k, a int

	// Initialize an array x of size 31 with zeros
	x := make([]int, 31)

	// Process each input value for n times
	for i := 0; i < n; i++ {
		fmt.Scanln(&k) // Read the number of elements in the current input

		// Process each element in the current input
		for j := 0; j < k; j++ {
			fmt.Scanln(&a) // Read the value of the current element
			x[a-1]++      // Increment the count of the current value in the array x
		}
	}

	// Initialize answer variable to zero
	ans := 0

	// Check each value from 1 to m and increment the answer if the count is equal to n
	for i := 0; i < m; i++ {
		if x[i] == n { // Check if the count of the current value is equal to n
			ans++ // Increment the answer if true
		}
	}

	// Output the final answer
	fmt.Println(ans)
}

