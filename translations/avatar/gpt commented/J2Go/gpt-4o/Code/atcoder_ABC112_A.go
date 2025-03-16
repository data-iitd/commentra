package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a buffered reader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the first input as an integer
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr[:len(nStr)-1]) // Convert string to integer

	// Check if the input is 1
	if n == 1 {
		// If the input is 1, print "Hello World"
		fmt.Println("Hello World")
	} else {
		// If the input is not 1, read two more strings
		str1, _ := reader.ReadString('\n')
		str2, _ := reader.ReadString('\n')

		// Parse the two strings as integers and print their sum
		num1, _ := strconv.Atoi(str1[:len(str1)-1]) // Convert string to integer
		num2, _ := strconv.Atoi(str2[:len(str2)-1]) // Convert string to integer
		fmt.Println(num1 + num2)
	}
}

// Note: In Go, there is no need for a close function for the reader as it is not explicitly required.
// <END-OF-CODE>
