
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare integer variables to store input values
	var h1, h2, m1, m2, k int

	// Create a scanner to read input values from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read input values for h1, m1, h2, m2, and k from the standard input
	for scanner.Scan() {
		// Convert the input values from strings to integers
		var err error
		h1, err = strconv.Atoi(scanner.Text())
		if err!= nil {
			fmt.Println("Error:", err)
			return
		}
		if!scanner.Scan() {
			fmt.Println("Error: Not enough input values")
			return
		}
		m1, err = strconv.Atoi(scanner.Text())
		if err!= nil {
			fmt.Println("Error:", err)
			return
		}
		if!scanner.Scan() {
			fmt.Println("Error: Not enough input values")
			return
		}
		h2, err = strconv.Atoi(scanner.Text())
		if err!= nil {
			fmt.Println("Error:", err)
			return
		}
		if!scanner.Scan() {
			fmt.Println("Error: Not enough input values")
			return
		}
		m2, err = strconv.Atoi(scanner.Text())
		if err!= nil {
			fmt.Println("Error:", err)
			return
		}
		if!scanner.Scan() {
			fmt.Println("Error: Not enough input values")
			return
		}
		k, err = strconv.Atoi(scanner.Text())
		if err!= nil {
			fmt.Println("Error:", err)
			return
		}
		break
	}

	// Calculate the difference in minutes between h2:m2 and h1:m1
	ans := (h2 * 60 + m2) - (h1 * 60 + m1)

	// Print the result of subtracting k from the calculated difference
	fmt.Println(ans - k)
}

