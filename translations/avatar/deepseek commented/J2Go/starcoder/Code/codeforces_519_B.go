
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
	fmt.Println("Enter the number of elements")
	// Read the number of elements
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	// Initialize sums of subsets
	a, b, c := 0, 0, 0
	// Sum all n elements
	for i := 0; i < n; i++ {
		fmt.Println("Enter element", i+1)
		// Read the element
		x, _ := strconv.Atoi(reader.ReadString('\n'))
		a += x
	}
	// Sum n-1 elements
	for i := 0; i < n-1; i++ {
		fmt.Println("Enter element", i+1)
		// Read the element
		x, _ := strconv.Atoi(reader.ReadString('\n'))
		b += x
	}
	// Sum n-2 elements
	for i := 0; i < n-2; i++ {
		fmt.Println("Enter element", i+1)
		// Read the element
		x, _ := strconv.Atoi(reader.ReadString('\n'))
		c += x
	}
	// Calculate the differences
	x := a - b
	y := b - c
	// Output the results
	fmt.Println(x)
	fmt.Println(y)
}

