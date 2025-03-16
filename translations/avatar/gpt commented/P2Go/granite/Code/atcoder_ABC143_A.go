
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read two integers A and B from user input, separated by a space
	AStr, _ := reader.ReadString(' ')
	BStr, _ := reader.ReadString('\n')
	A, _ := strconv.Atoi(AStr)
	B, _ := strconv.Atoi(BStr)

	// Calculate the result by subtracting twice the value of B from A
	ans := A - 2*B

	// If the result is negative, set it to zero
	if ans < 0 {
		ans = 0
	}

	// Print the final result
	fmt.Println(ans)
}
