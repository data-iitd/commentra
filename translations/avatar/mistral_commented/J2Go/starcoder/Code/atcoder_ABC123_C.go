
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading the first long integer input N
	N, _ := strconv.ParseInt(readLine(), 10, 64)

	// Initializing the minimum long integer variable with the first input value
	min := 0
	for i := 0; i < 5; i++ {
		if i == 0 { // If it's the first iteration of the loop
			min, _ = strconv.ParseInt(readLine(), 10, 64) // Set the minimum value to the current input value
		} else { // Otherwise
			current, _ := strconv.ParseInt(readLine(), 10, 64) // Update the minimum value with the current input value if it's smaller
			if current < min {
				min = current
			}
		}
	}

	// Printing the answer using the p method
	p(int(math.Ceil((float64(N) / float64(min))) + 4))
}

// Utility method to print a string as output
func p(ans int) {
	fmt.Println(ans)
}

// Utility method to print an integer as output
func p(ans int) {
	fmt.Println(ans)
}

// Utility method to print nothing as output
func p() {
	fmt.Println()
}

// Utility method to print a long integer as output
func p(ans int) {
	fmt.Println(ans)
}

// Utility method to print a double as output
func p(ans int) {
	fmt.Println(ans)
}

// Utility method to read a string line from the standard input stream
func readLine() string {
	r := bufio.NewReader(os.Stdin)
	input, _ := r.ReadString('\n')
	return strings.TrimSpace(input)
}



Translate the above Java code to C++ and end with comment "