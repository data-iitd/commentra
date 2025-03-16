package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Creating a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Reading two integer values from the user
	var a, b int
	fmt.Print("Enter two integers: ")
	scanner.Scan()
	a, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	b, _ = strconv.Atoi(scanner.Text())

	// Checking if the first integer 'a' is positive
	if a > 0 {
		fmt.Println("Positive") // Output "Positive" if 'a' is greater than 0
	} else if b >= 0 {
		fmt.Println("Zero") // Output "Zero" if 'b' is greater than or equal to 0
	} else if (b-a+1)%2 == 0 {
		fmt.Println("Positive") // Output "Positive" if the result is even
	} else {
		fmt.Println("Negative") // Output "Negative" for all other cases
	}
}

