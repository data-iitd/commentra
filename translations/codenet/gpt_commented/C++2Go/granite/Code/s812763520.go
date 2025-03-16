
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables to hold the number of characters and the answer
	var n int
	var ans int = 0
	var a, b, c string

	// Read the number of characters and the three strings from input
	reader := bufio.NewReader(os.Stdin)
	nStr, _ := reader.ReadString('\n')
	n, _ = strconv.Atoi(nStr)
	a, _ = reader.ReadString('\n')
	b, _ = reader.ReadString('\n')
	c, _ = reader.ReadString('\n')

	// Iterate through each character index from 0 to n-1
	for i := 0; i < n; i++ {
		// Check if all three characters at index i are the same
		if string(a[i]) == string(b[i]) && string(b[i]) == string(c[i]) {
			// Do nothing, as no points are awarded for identical characters
		}
		// Check if any two characters are the same
		else if string(a[i]) == string(b[i]) || string(b[i]) == string(c[i]) || string(a[i]) == string(c[i]) {
			// Increment the answer by 1 for matching pairs
			ans++
		}
		// If all characters are different
		else {
			// Increment the answer by 2 for all different characters
			ans += 2
		}
	}

	// Output the final answer
	fmt.Println(ans)
}
