
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter x:")
	x, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter y:")
	y, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter a:")
	a, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter b:")
	b, _ := strconv.Atoi(reader.ReadString('\n'))

	// Initialize a counter variable
	count := 0

	// Find the number of pairs (i, j) that satisfy the condition i < j
	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			// If i is less than j, continue to the next iteration of the inner loop
			if i <= j {
				continue
			}

			// Increment the counter if the condition is satisfied
			count++
		}
	}

	// Print the result
	fmt.Println(count)

	// Print all pairs (i, j) that satisfy the condition i < j
	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			// If i is less than j, print the pair
			if i <= j {
				fmt.Println(i, j)
			}
		}
	}
}

