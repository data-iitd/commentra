

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare three integer variables: A, B, and flag
	var A, B, flag int = 0, 0, 0

	// Create a new scanner to read two integers from the standard input
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		// Split the input string into two substrings and convert them to integers
		AB := scanner.Text()
		ABs := strings.Split(AB, " ")
		A, _ = strconv.Atoi(ABs[0])
		B, _ = strconv.Atoi(ABs[1])
	}

	// Iterate from 1 to 3 using a for loop
	for i := 1; i <= 3; i++ {
		// Check if the product of A, B, and the loop counter i is odd
		if (A*B*i)%2 == 1 {
			// Set the flag variable to 1 if the condition is true
			flag = 1
			// Break out of the loop if the condition is true
			break
		}
	}

	// Check the value of the flag variable
	if flag == 1 {
		// Print "Yes" to the standard output if the flag variable is 1
		fmt.Println("Yes")
	} else {
		// Print "No" to the standard output if the flag variable is 0
		fmt.Println("No")
	}
}

