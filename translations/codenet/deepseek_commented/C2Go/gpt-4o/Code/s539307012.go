package main  // Declare the main package

import (
	"fmt"  // Import the fmt package for formatted I/O
)

func main() {
	var n, x, min, m int  // Declare variables to store input values
	fmt.Scan(&n, &x, &min)  // Read three integers from standard input
	x -= min  // Subtract the minimum value from x
	for i := 1; i < n; i++ {  // Start a loop from 1 to n-1
		fmt.Scan(&m)  // Read the next integer
		x -= m  // Subtract the current integer from x
		if min > m {  // Check if the current integer is less than the current min
			min = m  // Update min to the current integer if true
		}
	}
	fmt.Println(n + x/min)  // Print the result
}
