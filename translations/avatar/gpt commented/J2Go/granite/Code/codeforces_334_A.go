
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a Scanner object for input and a PrintWriter for output
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	// Read an integer n from input
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(in)))

	// Calculate the square of n
	square := n * n

	// Initialize slices to hold odd and even numbers
	odd := make([]int, 0)
	even := make([]int, 0)

	// Populate the odd and even slices with numbers from 1 to square
	for i := 1; i <= square; i++ {
		if i%2 == 0 {
			even = append(even, i) // Add to even slice if the number is even
		} else {
			odd = append(odd, i) // Add to odd slice if the number is odd
		}
	}

	// Calculate the number of loops and the division for pairing
	loop := square / n
	div := loop / 2

	// Debug output to check the value of div
	fmt.Println("div:", div)

	// Loop through the number of rows to print the pairs
	for i := 1; i <= loop; i++ {
		// For each row, print div pairs of numbers
		for j := 0; j < div; j++ {
			// Alternate between odd and even pairs based on the row number
			if i%2 == 1 {
				// For odd rows, print an odd number and the last even number
				out.WriteString(strconv.Itoa(odd[0]) + " " + strconv.Itoa(even[len(even)-1]) + " ")
				odd = odd[1:]
				even = even[:len(even)-1]
			} else {
				// For even rows, print an even number and the last odd number
				out.WriteString(strconv.Itoa(even[0]) + " " + strconv.Itoa(odd[len(odd)-1]) + " ")
				odd = odd[:len(odd)-1]
				even = even[1:]
			}
		}
		// Move to the next line after printing pairs for the current row
		out.WriteString("\n")
	}

	// Flush the output
	out.Flush()
}

// Read a single line from the input reader
func readLine(in *bufio.Reader) string {
	line, _, err := in.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(line)
}

// Debug method to print the contents of the passed objects
func debug(obj...interface{}) {
	fmt.Fprintln(os.Stderr, obj...)
}

// End of code