
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner object to read input from the user
	scan := bufio.NewScanner(os.Stdin)

	// Declare variables
	var n, i, k, p int = 0, 1, 0, 1
	flag := true
	a := make([]int, 1000) // Array to keep track of occurrences

	// Read an integer input from the user
	scan.Scan()
	n, _ = strconv.Atoi(scan.Text())

	// Rest of the code goes here
	//...

	// Print the result
	fmt.Println(result)
}

// END-OF-CODE