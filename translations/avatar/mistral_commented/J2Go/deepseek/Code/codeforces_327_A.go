package main

import (
	"fmt"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	// Read input from the user
	fmt.Print("Enter text: ")
	scanner.Scan()
	input := scanner.Text()

	// Print the input
	fmt.Println("You entered:", input)
}
