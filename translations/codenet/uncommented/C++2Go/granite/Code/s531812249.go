
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the value of n:")
	n, _ := reader.ReadString('\n')
	fmt.Println("Enter the value of m:")
	m, _ := reader.ReadString('\n')

	// Convert string to integer
	nInt, _ := strconv.Atoi(strings.TrimSpace(n))
	mInt, _ := strconv.Atoi(strings.TrimSpace(m))

	// Calculate the result
	result := nInt*(nInt-1)/2 + mInt*(mInt-1)/2

	// Print the result
	fmt.Println("The result is:", result)
}

