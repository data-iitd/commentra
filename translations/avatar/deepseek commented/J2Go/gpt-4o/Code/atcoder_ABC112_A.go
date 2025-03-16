package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Reading the number of inputs
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr[:len(nStr)-1]) // Convert string to integer

	// Processing the input based on the value of n
	if n == 1 {
		// Outputting "Hello World" if n is 1
		fmt.Println("Hello World")
	} else {
		// Reading two strings and calculating their sum if n is not 1
		str1, _ := reader.ReadString('\n')
		str2, _ := reader.ReadString('\n')

		num1, _ := strconv.Atoi(str1[:len(str1)-1]) // Convert string to integer
		num2, _ := strconv.Atoi(str2[:len(str2)-1]) // Convert string to integer

		fmt.Println(num1 + num2)
	}
}

// <END-OF-CODE>
