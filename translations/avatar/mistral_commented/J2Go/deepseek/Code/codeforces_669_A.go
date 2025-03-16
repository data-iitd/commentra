package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int

	// Read the input number from the console and store it in the 'n' variable
	fmt.Print("Enter a number: ")
	input, _ := reader.ReadString('\n')
	n, _ = strconv.Atoi(input[:len(input)-1])

	// Call the 'solve' method to calculate and print the result
	solve(n)
}

// 'solve' method to calculate and print the result
func solve(n int) {
	// Calculate the result and print it to the console
	result := (n / 3) * 2
	if n % 3 != 0 {
		result += 1
	}
	fmt.Println(result)
}

