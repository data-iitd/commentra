
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int // Declaring an integer variable 'n' to store the number of test cases

	// Reading the first line of input which contains the number of test cases
	fmt.Scan(&n)

	// Checking if the number of test cases is equal to 1
	if n == 1 {
		// If yes, printing "Hello World" as output
		fmt.Println("Hello World")
	} else {
		// If not, reading the next two lines of input which contain two integers
		var num1, num2 int
		fmt.Scan(&num1, &num2)

		// Printing the sum of the two integers as output
		fmt.Println(num1 + num2)
	}
}

// 