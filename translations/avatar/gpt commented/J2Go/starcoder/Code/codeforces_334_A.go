package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read n from stdin
	fmt.Print("Enter n: ")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	// Calculate the square of n
	square := n * n

	// Initialize slices to hold odd and even numbers
	odd := make([]int, 0)
	even := make([]int, 0)

	// Populate the odd and even slices with numbers from 1 to square
	for i := 1; i <= square; i++ {
		if i%2 == 0 {
			even = append(even, i)
		} else {
			odd = append(odd, i)
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
				fmt.Printf("%d %d ", odd[0], even[len(even)-1])
				odd = odd[1:]
				even = even[:len(even)-1]
			} else {
				// For even rows, print an even number and the last odd number
				fmt.Printf("%d %d ", even[0], odd[len(odd)-1])
				even = even[1:]
				odd = odd[:len(odd)-1]
			}
		}
		// Move to the next line after printing pairs for the current row
		fmt.Println()
	}
}

