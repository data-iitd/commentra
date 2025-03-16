
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables N and D, which are integers between 1 and 20
	N, D := readInt() // Read two integers from standard input
	ans, rem := divmod(N, D) // Calculate the number of complete groups and the remainder

	// If there is a remainder, it means we need one additional group
	if rem!= 0 {
		ans = ans + 1 // Increment the answer by 1
	}

	// Output the final answer
	fmt.Println(ans)
}

func readInt() (int, int) {
	// Read two integers from standard input
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	D, _ := strconv.Atoi(scanner.Text())
	return N, D
}

func divmod(a, b int) (int, int) {
	// Calculate the number of complete groups and the remainder
	return a / (b*2 + 1), a % (b*2 + 1)
}

