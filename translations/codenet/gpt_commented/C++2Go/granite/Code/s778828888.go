
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables for the number of elements (n), number of inputs (m), and the starting point (x)
	var n, m, x int
	// Initialize an array to keep track of the presence of numbers (size 105 to accommodate possible values)
	a := make([]int, 105)
	// Initialize a scanner to read input from standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the values of n, m, and x from standard input
	fmt.Fscanf(scanner, "%d %d %d\n", &n, &m, &x)

	// Read m numbers from input and mark their presence in the array 'a'
	for i := 0; i < m; i++ {
		// Read a number and set the corresponding index in array 'a' to 1
		fmt.Fscanf(scanner, "%d", &n)
		a[n] = 1
	}

	// Initialize counters for the number of present elements to the right (ansr) and left (ansl) of x
	ansl := 0
	ansr := 0
	i := x

	// Count how many numbers are present from x to n (right side)
	for i <= n {
		ansr += a[i] // Increment ansr if a[i] is 1 (indicating presence)
		i++
	}

	// Count how many numbers are present from x to 0 (left side)
	for i >= 0 {
		ansl += a[i] // Increment ansl if a[i] is 1 (indicating presence)
		i--
	}

	// Output the minimum of the counts from both sides
	fmt.Println(strconv.Itoa(int(math.Min(float64(ansl), float64(ansr)))))
}

