
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Initialize a new scanner to read input from standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first line of input containing 4 integers and store them in ns slice
	fmt.Println("Reading input")
	scanner.Scan()
	fmt.Sscanf(scanner.Text(), "%d %d %d %d", &ns[0], &ns[1], &ns[2], &ns[3])

	// Sort the ns slice in ascending order
	fmt.Println("Sorting the numbers in ns slice")
	sort.Sort(sort.IntSlice(ns))

	// Check if the sorted ns slice matches the specific condition (1, 4, 7, 9)
	fmt.Println("Checking the condition")
	if ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9 {
		fmt.Println("The condition is true, print YES")
		fmt.Println("Output: YES")
		fmt.Println()
		fmt.Println("End of the program")
		return
	} else {
		fmt.Println("The condition is false, print NO")
		fmt.Println("Output: NO")
		fmt.Println()
		fmt.Println("End of the program")
		return
	}
}

