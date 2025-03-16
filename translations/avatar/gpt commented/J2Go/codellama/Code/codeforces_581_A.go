package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Creating a Scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Declaring two integer variables to hold user input
	var a, b int

	// Reading two integers from user input
	sc.Scan()
	a, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	b, _ = strconv.Atoi(sc.Text())

	// Initializing a counter to keep track of the number of pairs processed
	count := 0

	// Loop to process pairs of a and b while both are greater than zero
	for a > 0 && b > 0 {
		// Increment the count of pairs
		count++
		// Decrement both a and b
		a--
		b--
	}

	// Calculate the number of pairs that can be formed from the remaining a and b
	ans := a/2 + b/2

	// Output the count of pairs processed and the calculated answer
	fmt.Println(count, ans)
}

