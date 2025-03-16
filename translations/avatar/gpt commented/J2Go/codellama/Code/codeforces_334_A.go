package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object for input and a PrintWriter for output
	in := bufio.NewScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// Read an integer n from input
	in.Scan()
	n, _ := strconv.Atoi(in.Text())

	// Calculate the square of n
	square := n * n

	// Initialize ArrayLists to hold odd and even numbers
	odd := make([]int, 0)
	even := make([]int, 0)

	// Populate the odd and even ArrayLists with numbers from 1 to square
	for i := 1; i <= square; i++ {
		if i%2 == 0 {
			even = append(even, i) // Add to even list if the number is even
		} else {
			odd = append(odd, i) // Add to odd list if the number is odd
		}
	}

	// Calculate the number of loops and the division for pairing
	loop := square / n
	div := loop / 2

	// Debug output to check the value of div
	fmt.Println(div)

	// Loop through the number of rows to print the pairs
	for i := 1; i <= loop; i++ {
		// For each row, print div pairs of numbers
		for j := 0; j < div; j++ {
			// Alternate between odd and even pairs based on the row number
			if i%2 == 1 {
				// For odd rows, print an odd number and the last even number
				fmt.Fprintf(out, "%d %d ", odd[0], even[len(even)-1])
				odd = odd[1:]
				even = even[:len(even)-1]
			} else {
				// For even rows, print an even number and the last odd number
				fmt.Fprintf(out, "%d %d ", even[0], odd[len(odd)-1])
				even = even[1:]
				odd = odd[:len(odd)-1]
			}
		}
		// Move to the next line after printing pairs for the current row
		fmt.Fprintln(out)
	}

	// Close the PrintWriter to flush the output
	out.Flush()
}

// 