package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Creating a new scanner object to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Reading two integer values from the user
	fmt.Print("Enter two integers: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, " ", "", -1)
	a, _ := strconv.Atoi(input[:len(input)/2])
	b, _ := strconv.Atoi(input[len(input)/2:])

	// Checking if the first integer 'a' is positive
	if a > 0 {
		fmt.Println("Positive") // Output "Positive" if 'a' is greater than 0
	} else if b >= 0 {
		fmt.Println("Zero") // Output "Zero" if 'b' is greater than or equal to 0
	} else if (b - a + 1) % 2 == 0 {
		fmt.Println("Positive") // Output "Positive" if the result is even
	} else {
		fmt.Println("Negative") // Output "Negative" for all other cases
	}
}

