
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the first line of input
	line, _ := reader.ReadString('\n')
	// Split the input into a slice of strings
	xxs := strings.Split(line, " ")
	// Convert the strings to integers
	x, t, a, b, da, db := strconv.Atoi(xxs[0]), strconv.Atoi(xxs[1]), strconv.Atoi(xxs[2]), strconv.Atoi(xxs[3]), strconv.Atoi(xxs[4]), strconv.Atoi(xxs[5])

	// Define the main function to perform the logic
	func() {
		// Check if the value of x is 0
		if x == 0 {
			fmt.Println("YES")
			return
		}

		// Calculate the maximum number of times a and b can be decremented within the time limit t
		a_time := min(a/da, t-1)
		b_time := min(b/db, t-1)

		// Iterate over all possible combinations of decrements for a and b within their respective limits
		for i := 0; i <= a_time; i++ {
			for j := 0; j <= b_time; j++ {
				// Check if either a or b (or their sum) equals x
				if a-da*i == x || b-db*j == x {
					fmt.Println("YES")
					return
				}
				if a-da*i+b-db*j == x {
					fmt.Println("YES")
					return
				}
			}
		}

		// Return "Result Not Found" if no combination results in x
		fmt.Println("NO")
	}()
}

// min returns the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

